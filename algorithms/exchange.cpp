#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <debug.h>

using namespace std;

vector<int> exchange(int t)
{
    static vector<int> v{1000, 500, 200, 100, 50, 20, 10, 5, 1};

    vector<int> result;
    int c = 0;

    while (c < t)
    {
        for (int i = 0; i < v.size(); i++)
        {
            int value = v[i];
            if (c + value <= t)
            {
                result.push_back(value);
                c += value;

                if (c == t)
                    return result;

                break;
            }

            if (i == v.size() - 1)
            {
                return {};
            }
        }
    }

    return {};
}

int main()
{
    auto result = exchange(1599);

    Debug::printVector<int>(result);

    getchar();
}