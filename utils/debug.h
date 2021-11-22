#pragma once

#include <vector>
using namespace std;

class Debug
{
public:
    template <typename T>
    static void printVector(vector<T> &vector)
    {
        cout << "[";

        int size = vector.size();
        for (int i = 0; i < size; i++)
        {
            if (i != size - 1)
            {
                cout << vector[i] << ", ";
            }
            else
            {
                cout << vector[i] << "]" << endl;
            }
        }
    }
};