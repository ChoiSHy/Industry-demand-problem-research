/*
extern void enqueue();
extern int my_pop(int s);
extern void my_push(int s);

#include <stdio.h>
#include <Windows.h>
extern void print();

#define SIZE 10000

int count[10];

int pop(int from) {
	int ret;
	if (count[from] <= 0)
		return -1;

	ret = my_pop(from);
	count[from]--;

	return ret;
}
void push(int to, int val) {
	my_push(to);
	count[to]++;
}

void spread(int base, int from) {
	int data = 0;
	int cnt = count[from];

	while(data != -1) {
		data = pop(from);

		if (data >= base + 256) {
			if (from == 9 && count[from] != 0) {
				push(0, data);
			}
			else {
				push(9, data);
			}
		}
		else if (data >= base + 128) {
			if (from == 8 && count[from] != 0) {

				push(0, data);
			}
			else {

				push(8, data);
			}
		}
		else if (data >= base + 64)
		{
			if (from == 7 && count[from] != 0) {

				push(0, data);
			}
			else {

				push(7, data);
			}
		}
		else if (data >= base + 32)
		{
			if (from == 6 && count[from] != 0) {

				push(0, data);
			}
			else {

				push(6, data);
			}
		}
		else if (data >= base + 16)
		{
			if (from == 5 && count[from] != 0) {

				push(0, data);
			}
			else {

				push(5, data);
			}
		}
		else if (data >= base + 8)
		{
			if (from == 4 && count[from] != 0) {

				push(0, data);
			}
			else {

				push(4, data);
			}
		}
		else if (data >= base + 4)
		{
			if (from == 3 && count[from] != 0) {

				push(0, data);
			}
			else {

				push(3, data);
			}
		}
		else if (data >= base + 2)
		{
			if (from == 2 && count[from] != 0) {

				push(0, data);
			}
			else {

				push(2, data);
			}
		}
		else if (data >= base + 1)
		{
			if (from == 1 && count[from] != 0) {

				push(0, data);
			}
			else {

				push(1, data);
			}
		}
		else if(data <= base){
			enqueue();
		}
	}

}

void test_main() {
	int r, j;
	count[0] = SIZE;

	
	for (int i = 0; i < 1024; i += 2) {
		// 값이 들은 스택 중, 가장 번호가 빠른 스택(j)을 spread
		j = 0;
		
		for (; j < 10; j++)
			if (count[j] != 0)
				break;
		spread(i, j);
		
		// 0번 스택에서 값을 spread 한 경우, 다음으로 가장 빠른 스택(j)를 찾아 spread/*
		if (j == 0 && i != 0) {
			for (j; j < 10; j++)
				if (count[j] != 0) break;
			spread(i, j);
		}
		// 1번 스택에 남은 값들을 spread 
		// 1번 스택에 있는 값들은 enqueue한 값들보다 1 큰 값이므로 바로 enqueue해도 무방.
		while (count[1] > 0) {
				pop(1);
				enqueue();
		}
			

	}
}*/

