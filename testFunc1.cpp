#include "testWork.h"
#include <iostream>
using namespace std;
namespace testFuncs
{
    void oneChangeValues(int* inArray, int* inArraySize)
    {
        //сначала проинициализируем 1 и 0 (по признаку счётности), а потом сразу заменяем 0 на 1 и 1 на 0
        for (int i = 0; i < *inArraySize; i++) {
            if ((i%2) == 0)
            {
                inArray[i] = 1;
                cout << "Lesson 1. Old value of " << i << " element is " << inArray[i] << endl;
                inArray[i] = 0;
                cout << "Lesson 1. New value of " << i << " element is " << inArray[i] << endl;
            }
            else
            {
                inArray[i] = 0;
                cout << "Lesson 1. Old value of " << i << " element is " << inArray[i] << endl;
                inArray[i] = 1;
                cout << "Lesson 1. New value of " << i << " element is " << inArray[i] << endl;
            }
        }
    }
}
