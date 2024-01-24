#include <iostream>

class TestClass
{
    public:
        TestClass()
        {
            std::cout << "Hello World!" << std::endl;
        };
        ~TestClass()
        {
            std::cout << "Goodbye World!" << std::endl;
        };
};

int main()
{
    if(true)
        TestClass test;
    std::cout << "End of main" << std::endl;
    return 0;
}