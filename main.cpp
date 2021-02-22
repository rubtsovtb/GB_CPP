#include <iostream>

//задание 1
#define COMPARE(X1,X2) (((X1)>=0)&&((X1)<(X2)))
//задание 2
#define GETACCESS(ARRAY,ROW,COLUMN) (*((*((ARRAY)+(ROW)))+(COLUMN)))
//задание 3
#define ARRAYSIZE(ARRAY,DATATYPE)((sizeof(ARRAY))/(sizeof(DATATYPE)))

int main() {
    int x1 = 3;
    int x2 = 4;
    int Array1[16][8] = {0};
    int Array2[16] = {0};

    //проверка
    std::cout << (COMPARE(x1, x2)?1:0) << std::endl;
    std::cout << GETACCESS(Array1,10,1) << std::endl;
    std::cout << ARRAYSIZE(Array2, int) << std::endl;
    return 0;
}