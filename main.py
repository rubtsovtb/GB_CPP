from ctypes import *

class Passport(Structure):              # класс, который соответствует структуре Passport
    _fields_ = [("name", c_char_p),    # из файла main.h
                ("surname", c_char_p),
                ("var", c_int)]

lib_dll = cdll.LoadLibrary("C:/Users/roubt/Desktop/Float/Test_04/cmake-build-debug/libTest_04.dll")   # подключаю свою DLL
lib_dll.SetPassport.argtypes  = [POINTER(Passport)] # указываем, тип аргумента функции

lib_dll.GetPassport()          # вывод в консоль структуры

lib_dll.SetName(c_char_p(b"Yury"))
lib_dll.SetSurname(c_char_p(b"Orlov"))

lib_dll.GetPassport()         # вывод в консоль структуры

name = str.encode(("Vasiliy"))  # первый вариант получения указателя на байтовую строку
surname = c_char_p((b'Pupkin')) # второй вариант получения указателя на байтовую строку

passport = Passport(name, surname, 34) # создаем объект структуры Passport

lib_dll.SetPassport(pointer(passport)) # передача структуры в функцию в DLL

lib_dll.GetPassport()         # вывод в консоль структуры