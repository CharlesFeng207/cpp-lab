#include <iostream>
#include <boost/format.hpp>
#include "src/sub/test.h"
#include "utils/json.hpp"
#include <string>
#include <windows.h>


using json = nlohmann::json;

int test2()
{
    return 3;
}

int test()
{
    int a = 1;
    return test2() + 2;
}

int main(int, char **)
{
    std::string package_name = "com.tencent.tmgp.sgame";
    
    boost::format fmt("/sdcard/Android/data/%1%/files/framerecord.txt %2%");
    fmt % package_name % 100;
    std::cout << fmt.str() << std::endl;

    std::cout << "Hello, from cpplab!\n";

    while (true)
    {
        test();
        Sleep(1000);
    }
}
