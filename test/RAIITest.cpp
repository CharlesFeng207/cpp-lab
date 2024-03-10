#include <iostream>
#include <memory>

class Test
{
    public:
        int i = 100;
        ~Test()
        {
            std::cout << "Destructor" << std::endl;
        }
    private:
        int j;
};

int main()
{
    {
        std::shared_ptr<Test> ptr(new Test());
        std::cout << ptr.get()->i << std::endl;
        std::cout << ptr->i << std::endl;

    }
    
    std::cout << "End of main" << std::endl;
    return 0;
}