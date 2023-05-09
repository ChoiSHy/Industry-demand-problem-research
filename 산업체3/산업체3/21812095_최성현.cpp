// DO NOT ANY INCLUDE
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 12800

int qidx;
static int pres[128];
static int mres[128];
static int param[128];

static int len_pres;
static int len_mres;
static int len_param;

void print() {
	printf("valu : %c", !param[0] ? '+' : '-');
	for (int i = 1; i < len_param; i++)
		printf("%c(%d)", param[i] + 'A',param[i]);
	printf("\n");
}
void print_pres() {
	printf("pres : +");
	for (int i = 1; i < len_pres; i++)
		printf("%c[%d]", pres[i] + 'A',pres[i]);
	printf("\n\n");
}
void print_mres() {
	printf("mres : -");
	for (int i = 1; i < len_mres; i++)
		printf("%c[%d]", mres[i] + 'A',mres[i]);
	printf("\n\n");
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
			param[i] = question[qidx--] - 'A';

			if (qidx < 0) {
				param[0] = 0;
				len_param = i;
				return;
			}
		}
	}
}
void addp() {
	int i = 1;
	int carry = 0;
	int res = 0;
	while (i < len_pres && i < len_param) {
		res = pres[i] + param[i] + carry;
		carry = res / 26;
		res %= 26;

		pres[i++] = res;
	}
	while (i < len_pres) {
		res = pres[i] + carry;
		carry = res / 26;
		res %= 26;

		pres[i++] = res;
	}
	while (i < len_param) {
		res = param[i] + carry;
		carry = res / 26;
		res %= 26;

		pres[i++] = res;
	}
	if (carry == 1)
		pres[i++] = 1;

	len_pres = i;
}
void addm() {
	int i = 1;
	int carry = 0;
	int res = 0;
	while (i < len_mres && i < len_param) {
		res = mres[i] + param[i] + carry;
		carry = res / 26;
		res %= 26;

		mres[i++] = res;
	}
	while (i < len_mres) {
		res = mres[i] + carry;
		carry = res / 26;
		res %= 26;

		mres[i++] = res;
	}
	while (i < len_param) {
		res = param[i] + carry;
		carry = res / 26;
		res %= 26;

		mres[i++] = res;
	}
	if (carry == 1)
		mres[i++] = 1;

	len_mres = i;
}
void test_main(char answer[STRING_SIZE], const char question[STRING_SIZE])
{
	qidx = strlen(question) - 1;
	mres[0] = 1;
	//get_value(question);
	do {
		get_value(question);
		
		if (param[0]) {
			print();
			addm();
			print_mres();
		}
		else {
			print();
			addp();
			print_pres();
		}

	} while (len_param > 1);
	printf("===================\n");
	print_mres();
	print_pres();
}*/
