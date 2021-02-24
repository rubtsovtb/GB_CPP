//взято всё здесь:
//https://habr.com/ru/post/499152/
#include "main.h"

#define SIZE_BUF 20

struct Passport passport; // объявляем переменную passport типа Passport

// Функция установки имени
void DLL_EXPORT SetName(char* new_name)
{
    printf("SetName\n");
    strcpy(passport.name, new_name);
}

// Функция установки фамилии
void DLL_EXPORT SetSurname(char* new_surname)
{
    printf("SetSurname\n");
    strcpy(passport.surname, new_surname);
}

// Функция установки полей структуры.
// На вход принимает указатель на структуру
void DLL_EXPORT SetPassport(Passport* new_passport)
{
    printf("SetPassport\n");
    strcpy(passport.name, new_passport->name);
    strcpy(passport.surname, new_passport->surname);
    passport.var = new_passport->var;
}

// Вывести в консоль данные структуры
void DLL_EXPORT GetPassport(void)
{
    printf("GetPassport: %s | %s | %d\n", passport.name, passport.surname, passport.var);
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            printf("Load DLL in Python\n");

            passport.name = (char*)malloc(SIZE_BUF * sizeof(char)); // выделение памяти
            passport.surname = (char*)malloc(SIZE_BUF * sizeof(char)); // выделение памяти

            passport.var = 17; // начальная инициализация переменной
            SetName("Default"); // начальная инициализация буфера имени
            SetSurname("Passport"); // начальная инициализация буфера фамилии
            return 1;

        case DLL_PROCESS_DETACH:
            free (passport.name); // Освобождение памяти
            free (passport.surname); // Освобождение памяти
            printf("DETACH DLL\n");
            break;

        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE; // succesful
}