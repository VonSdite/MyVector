#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int reTimes = 1e9;

int main(int argc, char const *argv[])
{
    int start, end;
    int a = 0;

    // 10亿次自增所需要的平均时间为2s
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

    // 10亿次复制10个字节的平均时间为6s
    // 10亿次复制100个字节的平均时间为16s
    // 10亿次复制1000个字节的平均时间为60s
    start = clock();
    for (int i = 0; i < reTimes; ++i)
    {
        memcpy(tmp1, tmp2, sizeof(char)*100);
    }
    end = clock();
    printf("%d\n", end - start);

    return 0;
}