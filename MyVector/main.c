#include <stdio.h>
#include "MyVector.h"
#include <stdlib.h>
#include <string.h>
// #include <crtdbg.h>      // vs内存泄漏检测工具头文件


// 这里的声明必须是在最开始申明，类似c++的using namespace std;

state_using_vector(int);        // 申明使用 vector_int      =.=不能重复申明
state_using_vector(double);     // 申明使用 vector_double   =.=不能重复申明
state_using_vector(char);       // 申明使用 vector_char     =.=不能重复申明

// 要存放指针类型的需将 相应的指针类型typedef为另一个名字
// 同样!要结构体的需将 相应的结构体类型typedef为另一个名字
typedef char* pchar;
state_using_vector(pchar);      // 申明适用 vector_pchar    =.=不能重复申明

int vis[100000];

int main(int argc, char const *argv[])
{
    // _CrtSetBreakAlloc(453);      // vs内存泄漏检测，453代表泄漏的位置，在453位置中断的意思

    memset(vis, 0, sizeof(vis));

    vector_pchar a;
    initVector_pchar(&a);
    for (int i = 0; i < 100; ++i)
    {
        char *tmp = "haha";
        pushBack_pchar(&a, &tmp);

        if (!vis[getCapacity_pchar(&a)])
        {   // 当vector大小改变了才输出

            printf("当前vector元素个数:%-3d 当前vector的大小:%3d\n", 
                getSize_pchar(&a), 
                getCapacity_pchar(&a));

            vis[getCapacity_pchar(&a)] = 1;
        }
    }

    while (getSize_pchar(&a))
    {
        char *tmp;
        pop_pchar(&a, &tmp);  // 出队
        printf("出队的元素:%s 出队后元素的个数:%-3d 出队后vector的大小:%3d\n", 
            tmp, 
            getSize_pchar(&a), 
            getCapacity_pchar(&a));
    }

    remove_pchar(&a);         // 销毁

    // _CrtDumpMemoryLeaks();        // vs内存泄漏检测工具
    return 0;
}