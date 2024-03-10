
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

    // void swap(Widget& a, Widget& b)
    // {
    //     a.Swap(b);
    // }
}

namespace std
{
    template<>
    void swap(SwapTest::Widget& a, SwapTest::Widget& b)
    {
        a.Swap(b);
    }
}



int main()
{
    SwapTest::Widget w1(1);
    SwapTest::Widget w2(2);

    // using std::swap;
    std::swap(w1, w2);

    std::cout << "w1: " << w1.Data() << std::endl;   
    std::cout << "w2: " << w2.Data() << std::endl;
    return 0;
}