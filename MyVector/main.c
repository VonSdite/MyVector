#include <stdio.h>
#include "MyVector.h"
#include <stdlib.h>

state_using_vector(int);   // 申明使用 vector_int  =.=不能重复申明

int main(int argc, char const *argv[])
{
    vector_int a;
    initVector_int(&a);    // 初始化vector
    printf("%d %d\n", getSize_int(&a), getMaxSize_int(&a));
    for (int i = 0; i < 100; ++i)
    {
        pushBack_int(&a, &i);
        printf("%d %d\n", getSize_int(&a), getMaxSize_int(&a));
    }

    int tmp;
    pop_int(&a, &tmp);
    printf("%d %d %d\n", tmp, getSize_int(&a), getMaxSize_int(&a));
    for (int i = 0; i < a.size; ++i)
    {
        printf("%d ", a.elem[i]);
    }
    puts("");
    return 0;
}