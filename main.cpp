#include <iostream>
using namespace std;
#include "testWork.h"
using namespace testFuncs;

int main()
{
    //задание 6 в каждом задании (По-моему это + указатели на функции во всём дз были самыми полезными
    //для задания 1 и 5
    int arraySize; // размер массива
    cout << "Enter array size: ";
    cin >> arraySize; // получение от пользователя размера массива
    int* dynamicArray = new int[arraySize]; // Выделение памяти для массива
    void (*fponeChangeValues)(int*, int*); // Указатель на функцию с двумя параметрами
    fponeChangeValues = testFuncs::oneChangeValues; // перемещаем фунцию на указатель
    fponeChangeValues(dynamicArray, &arraySize); // производим действия с функцией
    delete [] dynamicArray; // очищаем память

    //для заднаия 2
    //Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;
    arraySize = 8;
    int array2 [arraySize];
    void (*fptwoSetValues)(int*, int*);
    fptwoSetValues = testFuncs::twoSetValues; // перемещаем фунцию на указатель
    fptwoSetValues(array2, &arraySize); // производим действия с функцией

    //для задания 3
    //комилятор CLion долго не мог найти заголовочный файл. Потерял на этом слишком много времени. Решение (алгоритм функции) подсмотремо в ответах
    int checkSize = 8;
    int inputArray[] = {1,4,6,3,7,8,9,4};
    bool (*fpthreeShiftValues)(int, int*);
    fpthreeShiftValues = testFuncs::threeCheckBalance;
    cout << "Lesson 3. Values balanced: " << fpthreeShiftValues(checkSize, inputArray) << endl;

    //для задания 4
    //решение (алгоритм функции) подсмотрено в ответах. По-моему, формулировка не совсем чёткая
    int inSize = 6;
    int testArray[] = {7, 6, 5, 4, 3, 2};
    int inShift = 5;
    void (*fpfourShiftValues)(int, int*, int);
    fpfourShiftValues = testFuncs::fourShiftArray;
    fpfourShiftValues(inSize, testArray, inShift);

    return 0;
}