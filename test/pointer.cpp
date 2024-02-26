#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *p = &a;
    *p++;
    cout << "a " << a << endl;    
    return 0;
}