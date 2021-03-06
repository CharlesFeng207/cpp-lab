#include <algorithm>
#include <iostream>
#include <time.h>
#include <vector>
#include <debug.h>

using namespace std;

void bubbleSort(vector<int> &a)
{
    int len = a.size();
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void test(vector<int> &a)
{
    int start = clock();
    bubbleSort(a);
    cout << clock() - start << endl;
}

int main()
{
    vector<int> v;
    for (int i = 10000; i >= 0; i--)
        v.push_back(i);

    vector<int> v2;
    for (int i = 10000; i >= 0; i--)
        v2.push_back(rand());

    test(v);
    test(v2);

    // cout << v[0];
    Debug::printVector<int>(v);

    getchar();
}