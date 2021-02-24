#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define DLL_EXPORT __declspec(dllexport) // обязательно определять функции,
// которые могут быть экспортированы из                                                 // библиотеки
#ifdef __cplusplus
extern "C"
{
#endif

struct Passport{
    char*  name;
    char*  surname;
    int var;
};

void DLL_EXPORT SetName(char* new_name);
void DLL_EXPORT SetSurname(char* new_surname);
void DLL_EXPORT SetPassport(Passport* new_passport);
void DLL_EXPORT GetPassport(void);

#ifdef __cplusplus
}
#endif
#endif // __MAIN_H__