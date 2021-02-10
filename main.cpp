#include <iostream>

// для задания 2
bool IntegerIsPrime(int in){
    // если n > 1
    if (in > 1)
    {
        // в цикле перебираем деление числа на большее 1 и меньшее in
        for (int i = 2; i <in; i++)
            if (in % i == 0)
                return false;
        return true;
    }
    else if (in == 1)// иначе возвращаем false (число не простое)
        return true;
    else
        return false;
}

//для задания 4
bool YearIsLeap(int inYear){
    if (inYear % 400 == 0)
        return true;
    else if (inYear % 100 == 0)
        return false;
    else if (inYear % 4 == 0)
        return true;
    else
        return false;
}

int main() {
    //задание 1
    int a = 0;
    int b = 0;
    int* pa = &a;
    int* pb = &b;
    bool result1 = false;
    std::cout << "Enter integer a:\n" << std::endl;
    std::cin >> *pa;
    std::cout << "Enter integer b:\n" << std::endl;
    std::cin >> *pb;
    result1 = (((*pa+*pb) >= 10) && ((*pa+*pb) <= 20)) ? true: false;
    std::cout << "Variable within range :\n" << result1 << std::endl;

    //задание 2
    int a1 = 0;
    int* pa1 = &a1;
    bool result2 = false;
    std::cout << "Enter integer to check it prime and natural:\n" << std::endl;
    std::cin >> *pa1;
    if ((*pa1 > 0) && (IntegerIsPrime(*pa)))
        result2 = true;
    else
        result2 = false;
    std::cout << "Variable is prime and natural :\n" << result2 << std::endl;

    //задание 3
    const int a2 = 8;
    const int b2 = 2;

    if (a2 == 10)
        std::cout << "some of constants or their sum is equal 10";
    else if (b2 == 10)
        std::cout << "some of constants or their sum is equal 10";
    else if ((a2+b2) == 10)
        std::cout << "some of constants or their sum is equal 10\n";
    else
        std::cout << "none of constants or their sum is equal 10";

    //задание 4
    bool result3 = false;
    int a3 = 0;
    std::cout << "Enter the year:\n" << std::endl;
    std::cin >> a3;
    result3 = YearIsLeap(a3);
    std::cout << "Year is leap :\n" << result3 << std::endl;

    return 0;
}