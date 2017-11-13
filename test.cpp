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
        printf("BeforePushBackVectorSize: %11d\t VectorSize:%d\n", beforePushBack, v.capacity()); 
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

    std::vector<int> v;
    v.resize(10);
    printf("%d %d\n", v.size(), v.capacity());
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    printf("%d %d\n", v.size(), v.capacity());
    return 0;
}