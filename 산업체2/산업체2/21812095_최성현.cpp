extern void my_push(int);
extern int my_pop(int);
extern void enqueue();

#define size 10000

int count[10];

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
		if (data >= 1020) {
			push(9);
		}
		else if (data >= 764) {
			push(8);
		}
		else if (data >= 636) {
			push(7);
		}
		else if (data >= 572) {
			push(6);
		}
		else if (data >= 540) {
			push(5);
		}
		else if (data >= 524) {
			push(4);
		}
		else if (data >= 516) {
			push(3);
		}
		else if (data >= 512) {
			push(2);
		}
		else if (data >= 1) {	// 1 ~ 511
			push(1);
		}
		else {
			enqueue();
		}
	}
	while (count[1] > 0) {	// 1 ~ 511
		data = pop(1);

		if (data >= 256) {
			push(8);
		}
		else if (data >= 128) {
			push(7);
		}
		else if (data >= 64) {
			push(6);
		}
		else if (data >= 32) {
			push(5);
		}
		else if (data >= 16) {
			push(4);
		}
		else if (data >= 8) {
			push(3);
		}
		else if (data >= 4) {
			push(2);
		}
		else if (data >= 2) {	// 2,3
			push(0);
		}
		else
			enqueue();	// 1
	}
	while (count[0]>0) {
		data=pop(0);
		if (data > 2)
			push(1);	// 3
		else
			enqueue();	// 2
	}
	while (count[1] > 0) {
		pop(1);	// 3
		enqueue();
	}
}

void flush(int from, int b) {
	int data;
	
	while (count[from]>0) {
		data = pop(from);
		if (b < 512 && data >= 512) {
			push(from);
			break;
		}
		if (data >= b + 256) {
			if (from == 9)
				push(8);
			else
				push(9);
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
	while (count[0] > 0) {
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
	int b;
	count[0] = size;
	spread();
	
	for (int i = 2; i < 9; i++) {
		b = 1;
		for (int j = 0; j < i; j++)
			b *= 2;
		flushes(i, &b);
	}
	for (int i = 2; i < 10; i++) {
		b = 1;
		for (int j = 0; j < i; j++)
			b *= 2;
		b += 508;
		flushes(i, &b);
	}
}