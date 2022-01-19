// MyFifthHomework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdarg>

int  Move, SizeMassive;
void MyPrintArray(const double* arr, const size_t Size)
{
    for (int i = 0; i < Size; i++)
    {
        std::cout << arr[i] << " " ;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void NullAndOneArray(const int* arr, const size_t SecondSize)
{
    for (int i = 0; i < SecondSize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
}

bool OneAndNullArray( int* arr, const size_t SecondSize) 
{
    for (int i = 0; i < SecondSize; i++)
    {

        std::cout << (arr[i] = !arr[i]) << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;
        return true;
    
   
}


void MultiplyThreeArray(int* arr, const size_t MassiveSize)
{
    for (int i = 0; i < MassiveSize; i++)
    {
        std::cout << (i * 3 + 1) << " ";

    }

    std::cout << std::endl;
    std::cout << std::endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    const size_t Size = 5;
    double MyArr[Size] = { -345.67, 345678.7896, -45.998, -234.987, 1.2 };
    MyPrintArray(MyArr, Size);

  

    const size_t SecondSize = 10;
    int NullAndOneArr[SecondSize] = { 1, 1, 0, 1, 0, 0, 0, 1, 1, 0 };
    NullAndOneArray(NullAndOneArr, SecondSize);
    OneAndNullArray(NullAndOneArr, SecondSize);


    const size_t MassiveSize = 8;
    int MultiplyThreeArr[MassiveSize];
    MultiplyThreeArray(MultiplyThreeArr, MassiveSize);
   
   
        

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

