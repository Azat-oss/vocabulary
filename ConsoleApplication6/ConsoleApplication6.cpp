// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>


#include <fstream>

#include <sstream>

#include <map>

#include <string>

#include <algorithm>

using namespace std;

void toLowerCase(string& word) 
{

    transform(word.begin(), word.end(), word.begin(), ::tolower);

}

int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    ifstream inputFile("input.txt");

    ofstream outputFile("output.txt");

    map<string, int> wordCount;

    string word;



    if (!inputFile.is_open()) 
    {

        cerr << "Ошибка открытия файла!" << endl;

        return 1;

    }



    // Чтение слов из файла

    while (inputFile >> word) 
    {

        toLowerCase(word);

        wordCount[word]++;

    }

    inputFile.close();



    // Вывод информации обо всех словах

    for (const auto& entry : wordCount) 
    {

        cout << entry.first << ": " << entry.second << endl;

    }



    // Найти наиболее часто встречающееся слово

    string maxWord;

    int maxCount = 0;

    for (const auto& entry : wordCount) 
    {

        if (entry.second > maxCount) 
        {

            maxCount = entry.second;

            maxWord = entry.first;

        }

    }



    // Вывод информации о самом частом слове

    cout << "Самое часто встречающееся слово: " << maxWord << " (" << maxCount << " раз)" << endl;



    // Запись результата в файл

    outputFile << "Частотный словарь:\n";

    for (const auto& entry : wordCount) 
    {

        outputFile << entry.first << ": " << entry.second << "\n";

    }

    outputFile << "Самое часто встречающееся слово: " << maxWord << " (" << maxCount << " раз)\n";

    outputFile.close();



    return 0;
}
