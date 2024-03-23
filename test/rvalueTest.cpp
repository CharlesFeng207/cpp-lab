#include <iostream>
#include <vector>

class TestClass
{
public:
    std::string data;
    TestClass()
    {
        std::cout << "Default Constructor" << std::endl;
    };
    TestClass(const TestClass &other)
    {
        data = other.data;
        std::cout << "Copy Constructor" << std::endl;
    };
    ~TestClass()
    {
        std::cout << "Destructor" << std::endl;
    };
    TestClass(TestClass &&other)
        : data(std::move(other.data))
    {
        std::cout << "Move Constructor" << std::endl;
    };
    TestClass &operator=(TestClass &other)
    {
        data = other.data;
        std::cout << "Copy Assignment Operator" << std::endl;
    };
};

template<typename T>
int forwardTest(T&& t, std::vector<TestClass>& vec)
{
    vec.emplace_back(std::forward<T>(t));
    return 0;
}

int main()
{
    std::vector<TestClass> vec;
    std::string *p;
    if (true)
    {
        TestClass t;
        t.data = "123";

        p = &t.data;
        std::cout << "before move " << *p << std::endl;

        // vec.emplace_back(std::move(t));
        forwardTest(std::move(t), vec);
        // forwardTest(t, vec);
        // vec.emplace_back(t);
        // vec.emplace_back(TestClass());
        // vec.push_back(t);

        std::cout << "after move " << *p << std::endl;
    }

    std::cout << "End of block " << *p << std::endl;
    std::cout << "End of main " << vec[0].data << std::endl;
    return 0;
}