#include "testWork.h"
#include <iostream>
using namespace std;
namespace testFuncs
{
    void twoSetValues(int* inArray, int* inArraySize)
    {
        //сначала проинициализируем 1 и 0 (по признаку счётности), а потом сразу заменяем 0 на 1 и 1 на 0
        for (int i = 0; i < *inArraySize; i++)
        {
            inArray[i] = 1 + i*3;
            cout << "Lesson 2. New value of " << i << " element is " << inArray[i] << endl;
        }
    }
}
