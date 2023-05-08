// DO NOT ANY INCLUDE
#include <stdio.h>

#define STRING_SIZE 12800

int qidx;

char* get_value(const char question[STRING_SIZE]) {
	if (question[qidx] == NULL)
		return NULL;
	char value[127];
	int idx = 0;
	while (true) {	
		if (qidx > 126 || question[qidx] == '+' || question[qidx] == '-') {
			qidx++;
			return value;
		}
		printf("%c\t", question[qidx]);
		value[idx++] = question[qidx++];
	}
}
void test_main(char answer[STRING_SIZE], const char question[STRING_SIZE])
{
	int idx = 0;
	char* value;
	do {
		value = get_value(question);
		printf("%s\n",value);
	} while (value != NULL);
}
