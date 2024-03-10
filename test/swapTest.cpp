
#include <iostream>
#include <algorithm>

namespace SwapTest
{
    class Widget
    {
        public:
            Widget(int i) : impl(new int(i))
            {
            }

            // 通过特化std::swap
            void Swap(Widget& other)
            {
                std::swap(impl, other.impl);
            }

            int Data() const
            {
                return *impl;
            }
        private:
            int* impl;
    };

    template<typename T>
    class WidgetWithTemplate
    {
        public:
            WidgetWithTemplate(T i) : impl(new T(i))
            {
            }

            // 模板类通过non-member函数实现swap
            void Swap(WidgetWithTemplate& other)
            {
                std::swap(impl, other.impl);
            }

            T Data() const
            {
                return *impl;
            }
        private:
            T* impl;
    };

    // std不推荐添加新的模板，所以通过non-member函数实现
    template<typename T>
    void swap(WidgetWithTemplate<T>& a, WidgetWithTemplate<T>& b)
    {
        a.Swap(b);
    }
}

namespace std
{
    // std内的东西，允许特化
    template<>
    void swap(SwapTest::Widget& a, SwapTest::Widget& b)
    {
        a.Swap(b);
    }

    // 但是std不允许添加新的模板，下面函数是未定义、不推荐的 (虽然实测能跑)
    // template<typename T>
    // void swap(SwapTest::WidgetWithTemplate<T>& a, SwapTest::WidgetWithTemplate<T>& b)
    // {
    //     a.Swap(b);
    // }
}


int main()
{
    using std::swap; // 根据类型匹配swap函数

    SwapTest::Widget w1(1);
    SwapTest::Widget w2(2);
    
    // 简单情况，可直接用特化的std版本
    swap(w1, w2);

    std::cout << "w1: " << w1.Data() << std::endl;   
    std::cout << "w2: " << w2.Data() << std::endl;

    SwapTest::WidgetWithTemplate<int> wt1(1);
    SwapTest::WidgetWithTemplate<int> wt2(2);
    swap(wt1, wt2); // 匹配规则会找到命名空间下non-member函数

    std::cout << "wt1: " << wt1.Data() << std::endl;
    std::cout << "wt2: " << wt2.Data() << std::endl;

    return 0;
}