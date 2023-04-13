
/*#include <stdio.h>

extern void enqueue();
extern int my_pop(int s);
extern void my_push(int s);

int count[10];
int top[10];

int pop(int from) {
	if (count[from] <= 0)
		return -1;
	
	count[from]--;
	return my_pop(from);
}
void push(int to) {
	count[to]++;
	my_push(to);
}
int peek(int where) {
	int ret = my_pop(where);
	my_push(where);
	return ret;
}
int spread() {
	top[0]=pop(0);
	for (int i = 1; i < 9; i++) {
		if (top[0] < top[i]) {
			push(i);
			top[i] = top[0];
			return 1;
		}
	}
	return 0;
}
int min_idx() {
	int min=1024, idx=0;
	for (int i = 1; i < 9; i++) {
		if (min > top[i]) {
			min = top[i];
			idx = i;
		}
	}
	return idx;
}
void merge() {

}
void reset() {
	for (int i = 1; i < 9; i++) {
		top[i] = 1024;
	}
}
void run() {
	count[0] = SIZE;
	reset();
	for (int i = 0; i < 30; i++) {		
		int ret = spread();
		if (ret==0) { printf("error\n"); }
	}
}
void print() {
	for (int j = 0; j < 10; j++) {
		for (int i = 1; i < 10; i++) {

			int r = pop(i);
			if (r >= 0)
				printf("%d\t", r);
			else
				printf("-\t");
		}
		printf("\n");
	}
}*//*
void test_main() {
	run();
	print();
}*/