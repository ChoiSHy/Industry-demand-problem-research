// DO NOT ANY INCLUDE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 12800

int qidx;
static int result[128];
static int param[128];

static int len_result;
static int len_param;

void print() {
	printf("%c", !param[0] ? '+' : '-');
	for (int i = 1; i < len_param; i++)
		printf("%c", param[i] + 'A');
	printf("\n");
}
void get_result() {
	printf("%c", !result[0] ? '+' : '-');
	for (int i = 1; i < len_result; i++)
		printf("%c", result[i] + 'A');
	printf("\n");
}
void get_value(const char question[STRING_SIZE]) {
	len_param = 0;
	for (int i = 1; i < 128; i++) {
		if (question[qidx] == '+') {
			param[0] = 0;
			len_param = i;
			qidx--;
			return;
		}
		else if (question[qidx] == '-') {
			param[0] = 1;
			len_param = i;
			qidx--;
			return;
		}
		else {
			param[i] = question[qidx--]-'A';

			if (qidx < 0) {
				param[0] = 0;
				len_param = i;
				return;
			}
		}
	}
}
void add() {
	int i = 1;
	int carry = 0;
	int res = 0;	

	for (; i < 128; i++) {
		if (len_result < i || len_param < i)  break; 

		res = result[i] + param[i] + carry;
		carry = res / 26;
		res = res % 26;
		
		result[i] = res;
	}
	while (len_result > i) {
		res = result[i] + carry;
		carry = res / 26;
		res %= 26;

		result[i++] = res;
	}
	while (len_param > i) {
		res = param[i] + carry;
		carry = res / 26;
		res %= 26;

		result[i++] = res;
	}
	len_result = i;	
}
void sub() {
	int i = 1;
	int carry = 0;
	int res = 0;

	for (; i < 128; i++) {
		if (len_result <= i || len_param <= i)  break;

		res = result[i] - param[i] - carry;
		carry = res < 0 ? 1 : 0;
		res = res < 0 ? 26 + res : res;

		result[i] = res;
	}
	while (len_result > i) {
		res = result[i] - carry;
		carry = res < 0 ? 1 : 0;
		res = res < 0 ? 26 + res : res;

		result[i++] = res;
	}
	while (len_param > i) {
		res = -param[i] - carry;
		carry = res < 0 ? 1 : 0;
		res = res < 0 ? 26 + res : res;

		result[i++] = res;
	}
	len_result = i;
}
void set1() {
	param[0] = 0;
	param[1] = 1;
	param[2] = 10;
	len_param = 3;
}
void set2() {
	param[0] = 0;
	param[1] = 2;
	len_param = 2;
}
void test_main(char answer[STRING_SIZE], const char question[STRING_SIZE])
{
	qidx = strlen(question) - 1;
	get_result();
	//get_value(question);
	set1();
	add();
	get_result();
	set2();
	print();
	sub();
	get_result();
}
