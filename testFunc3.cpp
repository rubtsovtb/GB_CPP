#include "testWork.h"
#include <iostream>
using namespace std;
namespace testFuncs
{
    bool threeCheckBalance(int size, int *a)
    {
        int lbound = 0;
        int rbound = size - 1;
        int left = 0;
        int right = 0;
        while (lbound <= rbound) {
            if (left > right)
                right += a[rbound--];
            else
                left += a[lbound++];
        }
        return left == right;
    }
}////
// Created by roubt on 16.02.2021.
//

