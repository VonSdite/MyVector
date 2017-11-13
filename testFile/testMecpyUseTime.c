#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int reTimes = 1e9;

int main(int argc, char const *argv[])
{
    int start, end;
    int a = 0;

    // 10�ڴ���������Ҫ��ƽ��ʱ��Ϊ2s
    start = clock();
    for (int i = 0; i < reTimes; ++i)
    {
        ++a;
    }
    end = clock();
    printf("%d\n", end - start);

    char *tmp1 = (char*)malloc(sizeof(char)*100);
    char *tmp2 = (char*)malloc(sizeof(char)*100);
    memset(tmp2, 'a', sizeof(char)*100);

    // 10�ڴθ���10���ֽڵ�ƽ��ʱ��Ϊ6s
    // 10�ڴθ���100���ֽڵ�ƽ��ʱ��Ϊ16s
    // 10�ڴθ���1000���ֽڵ�ƽ��ʱ��Ϊ60s
    start = clock();
    for (int i = 0; i < reTimes; ++i)
    {
        memcpy(tmp1, tmp2, sizeof(char)*100);
    }
    end = clock();
    printf("%d\n", end - start);

    return 0;
}