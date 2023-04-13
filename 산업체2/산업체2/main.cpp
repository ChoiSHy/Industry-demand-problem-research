/*
����
stack�� ����� ���ڸ� ���������� ū�� ������ �����Ͽ� queue�� �����϶�.
�ܺ� �Լ��� ����Ҽ� ����. (#include�� ���� �ܺ� �Լ� ��� ����)
Main�Լ��� ������ ������ �̸� �����ϴ� test_main�Լ��� �ۼ��϶�.
*/

#include <stdio.h>
#include <stdlib.h> 

#define SIZE 10000

void test_main(void);

static int stack[10][SIZE];

static int sp[10];

static int queue[SIZE];

static int qs;

static int hold;

static long long SCORE = 0;

void my_push(int s)
{
    SCORE++;
    stack[s][sp[s]++] = hold;
}

int my_pop(int s)
{
    SCORE++;
    return hold = stack[s][--sp[s]];
}

void enqueue(void)
{
    queue[qs++] = hold;
    hold = -1;
}

static void build_data(void)
{
    for (int c = 0; c < SIZE; c++)
    {
        stack[0][c] = rand() % 1024;
    }
    sp[0] = SIZE;
    for (int c = 1; c < 10; c++) sp[c] = 0;
    qs = 0;
}
int check() {
    for (int i = 1; i < SIZE; i++) {
        if (queue[i] < queue[i - 1])
            return 0;
    }
    return 1;
}
void print() {
    for (int i = 0; i < 20; i++) {
        printf("%d\n", stack[0][SIZE-1-i]);
    }
}
int main(void)
{
    SCORE = 0;
    for (int c = 0; c < 1; c++)
    {
        build_data();
        print();
        test_main();
        printf("%d ~ %d\n", queue[0], queue[SIZE - 1]);
        printf(check() == 1 ? "===%d===\n": "===false===\n",SCORE);
        
    }
    
    printf("SCORE = %d\n", SCORE);
}