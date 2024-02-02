#include <iostream>

class Component
{
public:
    virtual void FunctionPad0()
    {
        std::cout << "FunctionPad"
                  << "\n";
    }
    virtual void FunctionPad1()
    {
        std::cout << "FunctionPad"
                  << "\n";
    }
    virtual void FunctionPad2()
    {
        std::cout << "FunctionPad"
                  << "\n";
    }
    virtual void FunctionPad3()
    {
        std::cout << "FunctionPad"
                  << "\n";
    }
    virtual void FunctionPad4()
    {
        std::cout << "FunctionPad"
                  << "\n";
    }
    virtual void FunctionPad5()
    {
        std::cout << "FunctionPad"
                  << "\n";
    }
    virtual void FunctionPad6()
    {
        std::cout << "FunctionPad"
                  << "\n";
    }
    virtual void FunctionPad7()
    {
        std::cout << "FunctionPad"
                  << "\n";
    }
    virtual void FunctionPad8()
    {
        std::cout << "FunctionPad"
                  << "\n";
    }
    virtual void FunctionPad9()
    {
        std::cout << "FunctionPad"
                  << "\n";
    }
    virtual const char *GetName()
    {
        return "Component";
    }
};

class Animator : public Component
{
public:
    const char* name = "Animator";
    virtual const char *GetName()
    {
        return name;
    }
};

class JobData
{
public:
    char pad[24];
    Animator *m_Animator = nullptr;
    char pad2[110];
};

int main()
{
    JobData *jobData = new JobData[2];
    jobData[0].m_Animator = new Animator();
    jobData[1].m_Animator = new Animator();

    std::cout << sizeof(jobData[0]) << "\n";
    // std::cout << jobData[0].m_Animator->GetName() << "\n";

    int index = 1;
    uintptr_t jobDataPtrAddr = (uintptr_t)jobData + 144 * index; // 计算第N个JobData的地址
    uintptr_t animatorPtrAddr = *(uintptr_t*)(jobDataPtrAddr + 24); // 计算第N个JobData的Animator指针地址
    uintptr_t vtablePtrAddr = *(uintptr_t *)animatorPtrAddr; // 对象首地址为虚表指针变量
    uintptr_t *vtblPtr = (uintptr_t *)vtablePtrAddr; // vtable地址转换成指针
    uintptr_t functionAddr = vtblPtr[10]; // 10 是 GetName 函数在 vtable 中的索引
    
    void* animatorPtr = (void*)animatorPtrAddr;

    // 定义一个函数指针类型，与被调用的成员函数签名匹配
    typedef const char*(*fakefunc)(void *);

    // 转换为函数指针
    fakefunc func = (fakefunc)functionAddr;

    // 调用成员函数，成员函数默认第一个参数this指针
    std::cout << func(animatorPtr) << "\n";

    return 0;
}
