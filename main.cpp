#include <iostream> /* загружаем стандартную библиотеку */

int main() {

    std::cout << "Welcome to objects tester!" << std::endl;
    /*для задания 1*/
    int spbYear = 1703;
    const float exp = 2.7182818284590452353602874713527;
    volatile char testChar = (char)'None';
    /*CLion выдавал 36: warning: multi-character character constant [-Wmultichar]
    volatile char testChar = (char)'None'; //CLion РІС‹РґР°РІР°Р» 36: warning: multi-character character constant [-Wmultichar]
    ^~~~~~
     */

    /*для задания 2*/
    typedef enum possibleStates {X = 7, O, Nothing} possibleStatesTemplate; //шаблон здесь несколько избыточен

    /*для задания 3*/
    int gameVals[3]; //создаём массив
    gameVals[1] = possibleStates(X); // инициализируем переменные
    gameVals[2] = possibleStates(O);
    gameVals[3] = possibleStates(Nothing);
    int i;
    for ( i = 1 ; i <= 3; i++) { // выводим значения (получилось только числовые. Сами значения enum по индексу вытянуть не получилось
        std::cout << i << " value of array = " << gameVals[i] << std::endl;
    }

    /*для задания 4*/

    struct gameFields {
        int heightInCells;
        int widthInCells;
        int crossVal;
        int zeroVal;
        int nothingVal;
    } game1={3,3,possibleStatesTemplate(X),possibleStatesTemplate(O),possibleStatesTemplate(Nothing)};

    std::cout << "Zero field value = " << game1.zeroVal << std::endl;

    /*для задания 5*/
    union varMultiTypeTemplate{
        int i;
        char c;
        float f;
    };

    union varMultiTypeTemplate tmp;
    tmp.f=1.009;

    struct complexTemplate{
        union varMultiTypeTemplate value;
        int isInt : 1;
        int isFloat : 1;
        int isChar : 1;
    } complex{tmp, 0, 1, 0};

    /*будет интересно увидеть верный ответ. В сети написано, что приведением типов это не лечится*/
    std::cout << "Data type == Int. True? " << complex.isInt << std::endl;
    std::cout << "Data type == Float. True? " << complex.isFloat << std::endl;
    std::cout << "Data type == Char. True? " << complex.isChar<< std::endl;

    return 0;
}
