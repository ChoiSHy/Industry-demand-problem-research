extern void my_push(int);
extern int my_pop(int);
extern void enqueue();

#define size 10000
#include <stdio.h>
extern void print();
int count[10];
int z;
int pop(int from) {
	count[from]--;
	return my_pop(from);
}
void push(int to) {
	++count[to];
	my_push(to); 
}
void spread() {
	int data;
	for (int i = 0; i < size; i++) {
		data = pop(0);
		if (data >= 512) {
			push(1);
		}
		else if (data >= 256) {
			push(9);
		}
		else if (data >= 128) {
			push(8);
		}
		else if (data >= 64) {
			push(7);
		}
		else if (data >= 32) {
			push(6);
		}
		else if (data >= 16) {
			push(5);
		}
		else if (data >= 8) {
			push(4);
		}
		else if (data >= 4) {
			push(3);
		}
		else if (data >= 2) {
			push(2);
		}
		else if (data >= 1 ) {
			push(1);
		}
		else {
			enqueue();
		}
	}
	while (count[1] > 0) {
		data=pop(1);
		if (data == 1)
			enqueue();
		else {
			push(0); z++;
		}
	}
}
void flush(int from, int b) {
	int data;
	while ( count[from] > 0 ) {
		data = pop(from);

		if (data >= b+256) {
			push(8);
		}
		else if (data >= b + 128) {
			push(7);
		}
		else if (data >= b + 64) {
			push(6);
		}
		else if (data >= b + 32) {
			push(5);
		}
		else if (data >= b + 16) {
			push(4);
		}
		else if (data >= b + 8) {
			push(3);
		}
		else if (data >= b + 4) {
			push(2);
		}
		else if (data >= b + 2) {
			push(1);
		}
		else if (data >= b + 1) {
			push(0);
		}
		else {
			enqueue();
		}
	}
	while (count[0] > z) {
		pop(0);
		enqueue();
	}
}
void flush2(int from, int b) {
	int data;
	while (count[from] > 0) {
		data = pop(from);
		z--;
		if (data >= b + 256) {
			push(9);
		}
		else if (data >= b + 128) {
			push(8);
		}
		else if (data >= b + 64) {
			push(7);
		}
		else if (data >= b + 32) {
			push(6);
		}
		else if (data >= b + 16) {
			push(5);
		}
		else if (data >= b + 8) {
			push(4);
		}
		else if (data >= b + 4) {
			push(3);
		}
		else if (data >= b + 2) {
			push(2);
		}
		else if (data >= b + 1) {
			push(1);
		}
		else {
			enqueue();
		}
	}
	while (count[0] > 1) {
		pop(0);
		enqueue();
	}
}
void flushes(int from, int* b) {
	
	flush(from, *b);
	*b += 2;
	flush(1, *b);
	*b += 2;
	
	for (int i = 2; i < from; i++) {
		flushes(i, b);
	}
}

void test_main() {
	int b ;
	count[0] = size;
	spread();	
	for (int i = 2; i < 10; i++) {
		b = 1;
		for (int j = 1; j < i; j++)
			b *= 2;
		flushes(i, &b);
	}
	flush2(0, 512);
	for (int i = 2; i < 10; i++) {
		b = 1;
		for (int j = 1; j < i; j++)
			b *= 2;
		b += 512;
		flushes(i, &b);
	}
	print();
}