#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//для задания 1
//функция создания случайных значений
string createRandValues(int numVals)
{
    string res;
    for (int i = 0; i < numVals; i++)
    {
        //res.append(1, (char) rand());
        res.append(1, (char) i);
    }
    return res;
}

//функция создания файла и заполнения его случайными значениями
void createFileWithVals(const string& inFileName, int rowsInFile)
{
    ofstream myFile;
    myFile.open(inFileName);;
    myFile << createRandValues(rowsInFile);
    myFile.close();
}

//функция создания файла и заполнения его случайными значениями + текстом для дальнейшего поиска
void createFileWithVals(const string& inFileName, int rowsInFile, string inWord)
{
    ofstream myFile;
    myFile.open(inFileName);;
    myFile << createRandValues(rowsInFile);
    myFile << inWord;
    myFile.close();
}

//для задания 2
//функция измерения длинны массива
int getFileSize(const string& inFileName)
{
    //ifstream myFile;
    //myFile.open(inFileName, ifstream::ate);
    //ifstream myFile(inFileName, ios::binary | ios::ate);


    //ifstream myFile(inFileName, ios::ate);
    //int length = myFile.tellg();
    //myFile.close();


    ifstream in_file(inFileName, ios::ate);
    in_file.seekg(0, ios::end);
    int file_size = in_file.tellg();
    cout<<"Size of the file is"<<" "<< file_size<<" "<<"bytes";
    return file_size;
}

//функция для объединения файлов
void mergeFiles(const string& inFileName, const string& outFileName)
{
    ifstream inFile(inFileName);
    ofstream outFile(outFileName, ofstream::app);

    //буферизация почему-то отрабатывается некорректно
    //int tmp = getFileSize(inFileName);
    //char* temp = (char*) malloc(sizeof(char)*getFileSize(inFileName));
    char c;
    //int j = 0;
    while (inFile.get(c) && !inFile.eof())
    {
        //*(temp + j++) = c;
        outFile << c;
    }

    //outFile << temp;
    //delete temp;

    inFile.close();
    outFile.close();
}

//для задания 3
bool findVal(const string& inFileName, const string& inWord)
{
    ifstream inFile(inFileName);
    const char* wbytes = inWord.c_str();

    char c;
    int step = 0;
    while (inFile.get(c)&& !inFile.eof())
    {
        if (c==*(wbytes+step))
        {
            step++;
        }
        else
        {
            step=0;
            if (*wbytes == c)
            {
                step++;
            }
        }
        if (step==inWord.length())
        {
            cout<<"Word found"<<endl;
            return true;

        }
    }
    return false;
}

int main() {
    //задание 1
    string testVal = "Test_value_To_Find";
    string path1 = "C:\\Users\\roubt\\Desktop\\Float\\Test_10\\Test1.txt";
    string path2 = "C:\\Users\\roubt\\Desktop\\Float\\Test_10\\Test2.txt";
    string path3 = "C:\\Users\\roubt\\Desktop\\Float\\Test_10\\Test3.txt";
    createFileWithVals(path1, 100);
    createFileWithVals(path2, 89, testVal);

    //задание 2
    mergeFiles(path1, path3);
    mergeFiles(path2, path3);

    //задание 3
    //ответ взят из занятия 7, но почему-то не заводится
    findVal(path2, testVal);
    return 0;
}