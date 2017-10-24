# MyVector

- **用C语言实现c++ vector的基本功能**
- **使用C语言进行泛型编程**

## C语言实现vector
- 使用宏定义解决泛型编程问题
- 当最大存储空间不够时，采取扩大为原来存储空间**两倍**的策略
- 实现vector以下功能
    + push_back()   在末尾增加一个元素
    + pop           出队
    + size()        返回元素个素
    + max_size()    当前数据的大小
    + init()        初始化函数
    + remove()      销毁函数

## vector的一些特点的研究

*vector的详细介绍戳这里:* http://classfoo.com/ccby/article/jnevK

### vector的一些成员函数

- vector::size()            返回**有效元素个数**

- vector::max_size()        返回 vector 支持的最大元素个数
    + 是一个当前容器能够达到的**受限于操作系统或编译器的最大可能大小**。但实事上容器并**不保证能够达到这个大小**：在达到这个上限之前，已经出现内存分配失败。

- vector::resize()          改变有效元素的个数

- vector::capacity()        返回当前可使用的**最大元素内存块数**（即存储容量）

- vector::shrink_to_fit()   请求移除未使用的存储空间 


### 测试c++的vector

- 通过测试， 得知 vector当前最大存储空间不够时， vector会开辟原来空间的**两倍**
    - 两倍的增长即指数增加，所以开辟内存空间的操作会**少于60次**(普通pc机最多也只是达**32**次)
    - 优点是 **不需要频繁开辟空间**， 节省时间
    - 缺点是，**会占用较多的内存**， 可以使用 *vector::shrink_to_fit()   请求移除未使用的存储空间*

- 传统解决 vector当前最大存储空间不够时，常采用每次增加固定大小的内存空间
    + 这样的缺点是， **难以确定合适的固定大小**
    + 设置过小的话， 容易导致开辟空间操作过多
    + 设置过大的话， 容易发生我只输入一两个数据， 却开辟了很大内存空间的尴尬场面
    + 所以， 仿c++ vector实现也采用两倍增长的方法

**测试代码如下 或见 test.cpp**
``` C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getVectorMaxSize()
{
    vector<int> n;
    vector<bool> b;
    vector<double> d;
    vector<string> s;
    printf("vector_int:    %-11d \n\
vector_bool:   %-11d \n\
vector_double: %-11d \n\
vector_string: %-11d\n", 
        n.max_size(),
        b.max_size(),
        d.max_size(),
        s.max_size());
}

// 证实vector空间不够的时候，会开原来空间的两倍
void testBig1()
{
    // 第一种:
    vector<int> v;
    for (int i = 0; i < 100; ++i)
    {
        v.push_back(i);
        printf("Size: %d VectorSize:%d\n", v.size(), v.capacity());
    }
}

void testBig2()
{
    // 第二种
    vector<int> v; // 直接分配七个有效元素的空间
    v.resize(7);
    printf("init 7 size\n");
    v.push_back(0);
    // 最大元素个数是原来的空间两倍，所以是14
    printf("Size: %d VectorSize:%d\n", v.size(), v.capacity()); 
}

void testBig3()
{
    // 第三种
    vector<int> v; 
    
    for (int i = 1; i <= 26; ++i)
    {
        v.resize(1 << i);
        int beforePushBack = v.capacity();
        v.push_back(0);
        printf("BeforePushBackVectorSize: %d\t VectorSize:%d\n", 
        beforePushBack, v.capacity()); 
    }
        
}


void howBigICanCreate()
{
    vector<int> v;
    // v.resize(1 << 30);
    // v.resize(1 << 29);
    v.resize(1 << 28); 
    printf("Size: %d VectorSize:%d\n", v.size(), v.capacity()); 
}

int main(int argc, char const *argv[])
{
    // 找到vector开的空间最大时能存储的元素个数
    // int 可以开到 2^30个空间
    getVectorMaxSize(); 

    // 证实vector空间不够的时候，会开原来空间的两倍
    // 以下三种方法
    testBig1();
    testBig2();
    testBig3();

    // (int)我的电脑只能开 2^28次方的大小， 达不到2^30次方
    howBigICanCreate(); 

    return 0;
}
```
