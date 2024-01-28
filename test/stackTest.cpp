#include <iostream>

class TestClass
{
    public:
        int num;
        TestClass()
        {
            std::cout << "Hello World!" << std::endl;
        };
        ~TestClass()
        {
            std::cout << "Goodbye World!" << std::endl;
        };
};

TestClass TestFunction()
{
    TestClass test;
    test.num = 5;
    return test;
}

int main()
{
    if(true)
        TestClass test; // 离开作用域时，会调用析构函数
    std::cout << "End of if" << std::endl;

    // 返回值优化（Return Value Optimization，简称 RVO）是一种优化技术
    // 用于避免不必要的对象拷贝操作。它的主要原理是将函数中创建的局部对象直接放置到函数调用者提供的内存空间中
    // 从而避免了拷贝构造函数的调用。
    auto t = TestFunction();
    std::cout << "End of main " << t.num << std::endl;

    return 0;
}