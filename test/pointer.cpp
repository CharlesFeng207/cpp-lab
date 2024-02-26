#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *p = &a;
    *p++; // (*p)++
    cout << "a " << a << endl;    
    return 0;
}