#include <iostream>
#include "src/Utils.h"
#include "src/sub/test.h"

int main(int, char**){
    int i = Utils::CreateTexture("xxx");
    std::cout << test(i);
    std::cout << i;
    std::cout << i;
    std::cout << " Hello, from cpplab!\n";
}
