/*
문제
stack에 저장된 숫자를 작은수부터 큰수 순으로 정렬하여 queue에 저장하라.
외부 함수는 사용할수 없다. (#include를 통한 외부 함수 사용 금지)
Main함수는 다음과 같으며 이를 구현하는 test_main함수를 작성하라.
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
    int ret = 1;
    int err_cnt = 0;
    for (int i = 1; i < SIZE; i++) {    
        if (queue[i] < queue[i - 1]) {
            printf("[%d]%d, [%d]%d\n", i-1,queue[i - 1],i, queue[i]);
            ret = 0; 
            err_cnt++;
        }
    }
    printf("error:%d\n", err_cnt);
    return ret;
}
void print() {
    int data;
    int cnt[10] = { 0 ,0,0,0,0,0,0,0,0,0};
    
    for (int i = 10000; i >=0 ; i--) {   
            for (int j = 0; j < 10; j++) {
                data = stack[j][i];

                if (!data || sp[j] <= i) {
                    if (i < 100)
                        printf("-\t");
                }
                else {
                    if (i < 100)
                        printf("%d\t", data);
                    cnt[j]++;
                }
            }
            if (i < 100)
                printf("\n");
    }
    printf("\n---------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < 10; i++)
        printf("%d\t", i);
    printf("\n");
    int res = 0;
    for (int i = 0; i < 10; i++) {
        printf("%d\t", cnt[i]);
        res += cnt[i];
    }
    printf("\n%d\n", res);
}
int main(void)
{
    SCORE = 0;
    for (int c = 0; c < 10; c++)
    {
        build_data();
        test_main();
        printf("%d\n", qs);
        printf(check() == 1 ? "===%d===\n" : "===false===\n",SCORE);
        
    }
    
    printf("SCORE = %d\n", SCORE);
}