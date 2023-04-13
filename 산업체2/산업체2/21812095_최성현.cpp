extern void enqueue();
extern int my_pop(int s);
extern void my_push(int s);

#define SIZE 10000

int count[10];

int pop(int from) {
	if (count[from] <= 0)
		return -1;
	count[from]--;

	return my_pop(from);
}
void push(int to) {
	my_push(to);
	count[to]++;
}

void spread(int base, int from) {
	int data;
	int cnt = count[from];
	
	for (int i = 0; i < cnt; i++) {
		data = pop(from);

		if (data >= base + 256) {
			if (from == 9)
				push(0);
			else
				push(9);
		}
		else if (data >= base + 128) {
			if (from == 8)
				push(0);
			else
				push(8);
		}
		else if (data >= base + 64)
		{
			if (from == 7)
				push(0);
			else
				push(7);
		}
		else if (data >= base + 32)
		{
			if (from == 6)
				push(0);
			else
				push(6);
		}
		else if (data >= base + 16)
		{
			if (from == 5)
				push(0);
			else
				push(5);
		}
		else if (data >= base + 8)
		{
			if (from == 4)
				push(0);
			else
				push(4);
		}
		else if (data >= base + 4)
		{
			if (from == 3)
				push(0);
			else
				push(3);
		}
		else if (data >= base + 2)
		{
			if (from == 2)
				push(0);
			else
				push(2);
		}
		else if (data >= base + 1)
		{
			if (from == 1)
				push(0);
			else
				push(1);
		}
		else
			enqueue();
	}
}

void test_main() {
	count[0] = SIZE;
	for (int i = 0; i < 1024; i += 2) {
		int j = 0;
		for (; j < 10; j++)
			if (count[j] != 0)
				break;
		spread(i, j);

		if (j == 0 && i != 0) {
			for (j; j < 10; j++)
				if (count[j] != 0) break;
			spread(i, j);
		}
		while (count[1] > 0) {
			pop(1);
			enqueue();
		}
	}
}
