#include <iostream>
#include <cstdio> //для printf() и scanf()
#include "externalValuesDef.h" //для 3-го задания

int main() {
    //задание 1
    int a = 2;
    int b = 3;
    int c = 4;
    int d = 5;
    float result = 0;
    result = (a*(b+((float)c/(float)d))); //чтобы нормально отработало деление приводим обе переменные в делении к float
    std::cout<<result<<"\n";

    //задание 2
    //сначала случайно выполнил это задание в C, а потом уже просто не захтелось переделывать, так что оставил команды вывода из C и подключил библиотеку cstdio
    int x1;
    int trigger1 = 21;
    int result1;
    printf("Type your integer:\n");
    scanf("%i", &x1);
    result1 = ((x1 <= trigger1) ? abs(x1 - trigger1) : 2*(x1 - trigger1)); // для перестраховки сделал разницу по модулю
    printf("Your score:%i\n", result1); // выводим значение переменной x удвоенное

    //задание 3
    //хорошо описано здесь: http://www.cplusplus.com/forum/beginner/47834/
    int a1 = aExt;
    int b1 = bExt;
    int c1 = cExt;
    int d1 = dExt;
    float result2 = 0;
    result2 = (a1*(b1+((float)c1/(float)d1))); //чтобы нормально отработало деление приводим обе переменные в делении к float
    std::cout<<result2<<"\n";

    //задание 4
    const int sideSize = 3;
    int cube[sideSize][sideSize][sideSize] = {
            { {21,2,3},{2,61,3},{43,65,98} },
            { {21,2,3},{2,62,3},{43,65,98} },
            { {21,2,3},{2,63,3},{43,65,98} }
    }; // создаём массив и заводим в него значения
    int* pcube[sideSize][sideSize][sideSize]; //создаём указатель на массив
    for ( int i = 0; i < sideSize; i++) { // обходим по перовму измерению
        for ( int j = 0; j < sideSize; j++) { // обходим по второму измерению
            for ( int k = 0; k < sideSize; k++) { // обходим по третьему измерению
                pcube[i][j][k] = &cube[i][j][k]; //присваиваем указателю адреса ячеек массива
            }
        }
    }
    int value = *pcube[1][1][1]; // разыменование указателя
    std::cout<<"Printing cube value: "<<value<<"\n";
    return 0;
}