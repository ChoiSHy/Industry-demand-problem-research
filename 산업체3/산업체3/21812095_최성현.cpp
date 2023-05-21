// DO NOT ANY INCLUDE
#define STRING_SIZE 12800

int qidx;
static int param[127];
static int len_param;

int compare(int* p, int* m, int lenP, int lenM) {
	if (lenP == lenM) {
		for (int i = 0; i < lenP; i++) {
			if (p[i] != m[i])
				return p[i] - m[i];
		}
		return 0;
	}
	else {
		return lenP - lenM;
	}
}
int get_value(const char question[STRING_SIZE]) {
	len_param = 0;
	for (int i = 0; i < 127; i++) {
		if (question[qidx] == '+') {
			len_param = i;
			qidx--;
			return 1;
		}
		else if (question[qidx] == '-') {
			len_param = i;
			qidx--;
			return 0;
		}
		else {
			param[i] = question[qidx--] - 'A';

			if (qidx < 0) {
				len_param = i+1;
				return -1;
			}
		}
	}
}
void add(int* result, int* len) {
	int i = 0;
	int carry = 0;
	int res = 0;
	while (i < *len && i < len_param) {
		res = result[i] + param[i] + carry;
		carry = res / 26;
		res %= 26;

		result[i++] = res;
	}
	while (i < *len) {
		res = result[i] + carry;
		carry = res / 26;
		res %= 26;

		result[i++] = res;
	}
	while (i < len_param) {
		res = param[i] + carry;
		carry = res / 26;
		res %= 26;

		result[i++] = res;
	}
	if (carry == 1)
		result[i++] = 1;

	*len = i;
}
void sub(int* from, int* what, int* lenF, int lenW) {
	int i = 0;
	int res = 0;
	int carry = 0;
	while (i < *lenF && i < lenW) {
		res = from[i] - what[i] - carry;
		carry = res < 0 ? 1: 0;
		res = res < 0 ? 26 + res : res;

		from[i++] = res;
	}
	while (i < *lenF) {
		res = from[i] - carry;
		carry = res < 0 ? 1 : 0;
		res = res < 0 ? 26 + res : res;

		from[i++] = res;
	}
	if (res == 0)
		i--;
	*lenF = i;
}
int strlen(const char* str) {
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}
void test_main(char answer[STRING_SIZE], const char question[STRING_SIZE])
{
	int pm = 0;
	int pres[127]={0}, len_p = 0;
	int mres[127]={0}, len_m = 0;
	qidx = strlen(question) - 1;
	do {
		pm = get_value(question);
		
		if (pm) {
			add(pres, &len_p);
		}
		else {
			add(mres, &len_m);
		}

	} while (pm>=0);

	if (compare(pres, mres,len_p,len_m) >= 0) {
		sub( pres, mres, &len_p, len_m);
		for (int i = 0; i < len_p; i++)
			answer[i] = 'A'+pres[len_p-1-i];
	}
	else {
		sub( mres, pres, &len_m, len_p);	
		answer[0] = '-';
		for (int i = 1; i <= len_m; i++)
			answer[i] = 'A'+mres[len_m-i];
	}
}
