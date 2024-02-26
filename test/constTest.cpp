#include <iostream>

class Test
{
public:
    // 这是 C++ 中关于初始化数组的一种便捷语法，称为零初始化。它保证了数组中所有元素都会被初始化为 0，即使未显式指定初始值。因此，整型数组 arr 中的所有 10 个元素都将被初始化为 0。
    // 如果初始化器中的元素数量少于数组的大小，那么未显式初始化的元素将被默认初始化。对于整型数组，就会将其余的元素默认初始化为 0
    int arr[10] = {0};
    const int& Func(int i) const
    {
        return arr[i];
    }

    int& Func(int i)
    {
        // 当const版本和non-const版本函数重复时，应该用nonconst版本调用const版本
        const Test* constThis = const_cast<const Test*>(this);
        int r = constThis->Func(i);

        return arr[i];
    }
};
int main()
{
    Test t;
    t.Func(0) = 100;
    std::cout << t.Func(0) << std::endl;

    const Test ct = Test();
    std::cout << ct.Func(0) << std::endl;
    // ct.Func(0) = 100; // 这里会编译报错保护
    return 0;
}