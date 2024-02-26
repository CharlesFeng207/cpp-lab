// #include <float.h>
// https://www.cnblogs.com/zrtqsk/p/4371773.html

#include <cstring>
#include <iostream>

using namespace std;

struct Test
{
    int a;
    char b;
    static const int c = 100; // class成员里面的常量，为了避免const占用多份内存，需要加static修饰
};

int main()
{
    Test t;

    cout << sizeof(t);

    getchar();
}