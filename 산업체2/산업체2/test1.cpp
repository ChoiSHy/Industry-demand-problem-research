//extern void my_push(int);
//extern int my_pop(int);
//extern void enqueue();
//
//#define size 10000
//#include <stdio.h>
//extern void print();
//int count[10];
//int z;
//
//int pop(int from) {
//	count[from]--;
//	return my_pop(from);
//}
//void push(int to) {
//	++count[to];
//	my_push(to); 
//}
//
//void spread() {
//	int data;
//	for (int i = 0; i < size; i++) {
//		data = pop(0);
//		if (data >= 256) {
//			push(9);
//		}
//		else if (data >= 128) {
//			push(8);
//		}
//		else if (data >= 64) {
//			push(7);
//		}
//		else if (data >= 32) {
//			push(6);
//		}
//		else if (data >= 16) {
//			push(5);
//		}
//		else if (data >= 8) {
//			push(4);
//		}
//		else if (data >= 4) {
//			push(3);
//		}
//		else if (data >= 2) {
//			push(2);
//		}
//		else if (data >= 1 ) {
//			push(1);
//		}
//		else {
//			enqueue();
//		}
//	}
//	while (count[1] > 0) {
//		pop(1);
//		enqueue();
//	}
//}
//
//void flush(int from, int b) {
//	int data;
//	while ( count[from] > 0 ) {
//		data = pop(from);
//
//		if (data >= b+256) {
//			if (from == 9)
//				push(8);
//			else
//				push(9);
//		}
//		else if (data >= b + 128) {
//			push(7);
//		}
//		else if (data >= b + 64) {
//			push(6);
//		}
//		else if (data >= b + 32) {
//			push(5);
//		}
//		else if (data >= b + 16) {
//			push(4);
//		}
//		else if (data >= b + 8) {
//			push(3);
//		}
//		else if (data >= b + 4) {
//			push(2);
//		}
//		else if (data >= b + 2) {
//			push(1);
//		}
//		else if (data >= b + 1) {
//			push(0);
//		}
//		else {
//			enqueue();
//		}
//	}
//	while (count[0] > 0) {
//		pop(0);
//		enqueue();
//	}
//}
//
//void flushes(int from, int* b) {
//	
//	flush(from, *b);
//	*b += 2;
//	flush(1, *b);
//	*b += 2;
//	
//	for (int i = 2; i < from; i++) {
//		flushes(i, b);
//	}
//}
//
//void test_main() {
//	int b ;
//	count[0] = size;
//	spread();
//	print();
//	for (int i = 2; i < 10; i++) {
//		b = 1;
//		for (int j = 1; j < i; j++)
//			b *= 2;
//		flushes(i, &b);
//	}
//
//	flushes(9, &b);
//	//print();
//}