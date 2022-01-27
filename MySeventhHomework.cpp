// MySeventhHomework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "MyLib.h"

#define PrintMessage std::cout << "Программа проверяет, входит ли первое из двух введённых вами чисел в диапазон от 0 до второго числа." << std::endl; \
std::cin >> FirstNumber; \
std::cin >> SecondNumber;

#define Print_STR(str) \
if (0 <= FirstNumber && FirstNumber < SecondNumber) \
std::cout << "True" << std::endl; \
else \
std::cout << "False" << std::endl; 

int FirstNumber, SecondNumber, PuzyrSize;



#define PrintPuzyrSize std::cout << "Введите размер массива" << std::endl; \
std::cin >> PuzyrSize;

#define SwapINT(a, b);

int main()
{

	setlocale(LC_ALL, "Russian");
	
	const int size = 10;
	
	// Task 1 and 5 //////////////////////////////////////////////////////////////////////

	float arr[size] = { -1, 2, -4, 5, -7, -8, 9, 6, -3, 1 };

	MyLib::SizeArray(arr, size);

	MyLib::printArray(arr, size); 

	MyLib::PlusMinus(arr, size);


	// Task 2 ////////////////////////////////////////////////////////////////////////////

	PrintMessage


		Print_STR(str)

		// Task 3 ////////////////////////////////////////////////////////////////////////////

		int Myarr[1]{};

		PrintPuzyrSize

		MyLib::SizePuzyr(Myarr, PuzyrSize);

	return 0;
}