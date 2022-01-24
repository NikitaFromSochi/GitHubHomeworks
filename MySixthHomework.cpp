// MySixthHomework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

std::string SecondName, FirstName, ChangeOne, ChangeTwo, ResultFile;

int main()
{
    setlocale(LC_ALL, "Russian");

    // Task 1 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int* FirstMassiveArr; // Указатель на массив
    int MassiveSize; // Количество элементов
    std::cout << "Введите размер вашего массива: " << std::endl;
    std::cin >> MassiveSize;

    if (MassiveSize > 0)
    {
        FirstMassiveArr = new int[MassiveSize]; // Выделение памяти под одномерный массив
        // Работа с массивом
        for (int i = 0; i < MassiveSize; i++)
        {
            FirstMassiveArr[i] = pow(2, i);


            std::cout << FirstMassiveArr[i] << " ";
        }

        std::cout << std::endl;
        std::cout << std::endl;
        // освобождение памяти
        delete[] FirstMassiveArr;
        FirstMassiveArr = nullptr;

    }

    // Task 2 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int** DoubleMassiveArr;
    const size_t FirstMeasure = 4;
    const size_t SecondMeasure = 4;

    DoubleMassiveArr = new int * [FirstMeasure];
    for (size_t i = 0; i < FirstMeasure; i++)
    {
        DoubleMassiveArr[i] = new int [SecondMeasure];
        DoubleMassiveArr[i][i] = rand();
    }
    std::cout << DoubleMassiveArr[0][0] << " " << DoubleMassiveArr[0][1] << " " << DoubleMassiveArr[0][2] << " " << DoubleMassiveArr[0][3] << std::endl;
    std::cout << DoubleMassiveArr[1][0] << " " << DoubleMassiveArr[1][1] << " " << DoubleMassiveArr[1][2] << " " << DoubleMassiveArr[1][3] << std::endl;
    std::cout << DoubleMassiveArr[2][0] << " " << DoubleMassiveArr[2][1] << " " << DoubleMassiveArr[2][2] << " " << DoubleMassiveArr[2][3] << std::endl;
    std::cout << DoubleMassiveArr[3][0] << " " << DoubleMassiveArr[3][1] << " " << DoubleMassiveArr[3][2] << " " << DoubleMassiveArr[3][3] << std::endl;


    for (size_t i = 0; i < FirstMeasure; i++) {
        delete[] DoubleMassiveArr[i];
    }
    delete[] DoubleMassiveArr;
    DoubleMassiveArr = nullptr;

    std::cout << std::endl;
    std::cout << std::endl;

    // Task 3 ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::cout << "Введите название для файла и разрешение" << std::endl;
    std::getline(std::cin, FirstName);
   
    std::ofstream First(FirstName);
    if (First.is_open())
        {
        First << "London is the capital of great Britain. London is the capital of great Britain." << std::endl;
        First.close();
        }

    std::cout << std::endl;

    std::cout << "Введите название для второго файла с таким же разрешением" << std::endl;
    std::getline(std::cin, SecondName);

    std::ofstream Secondary(SecondName);
    if (Secondary.is_open())
        {
        Secondary << "My name is Nikita. I am 25 years old. I was born in Kirzhach, but now i live in Voronezh." << std::endl;
        Secondary.close();
        }


    return 0;
}


