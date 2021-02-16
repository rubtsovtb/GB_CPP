#include "testWork.h"
#include <iostream>
using namespace std;
namespace testFuncs
{
    void fourShiftArray(int size, int* array, int value) {
        value %= size;
        int shift = size + value;
        shift %= size;

        for (int i = 0; i < shift; i++)
        {
            int temp = array[size - 1];
            for (int j = size - 1; j > 0; --j)
            {
                array[j] = array[j - 1];
            }
            array[0] = temp;
            cout << "Lesson 4. New value of " << i << " element is " << array[0]<< endl;
        }
    }
}//
// Created by roubt on 16.02.2021.
//

