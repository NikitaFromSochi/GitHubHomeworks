#include <iostream>
#include "MyLib.h"

#define SwapINT(a, b);
#define PrintPuzyrSize std::cout << "Введите размер массива" << std::endl; \
std::cin >> PuzyrSize;

namespace MyLib {

	int PlusNumber, MinusNumber, FirstSize;
	int nums[10];

	void SizeArray(const float array[], const int size)
	{
		std::cout << "Massive Size is " << size << std::endl;
	}


	void printArray(const float array[], const int size)
	{

		for (int i = 0; i < size; i++)
			std::cout << array[i] << " ";

	}

	void PlusMinus(const float array[], const int size)
	{
		for (int i = 0; i < size; i++) {

			if (array[i] >= 0)
				PlusNumber = PlusNumber + 1;
			MinusNumber = size - PlusNumber;
		}
		std::cout << PlusNumber << std::endl;
		std::cout << MinusNumber << std::endl;
	}

	void SizePuzyr(const int Myarray[], const int PuzyrSize)
	{
		for (int k = 0; k < PuzyrSize; k++) nums[k] = rand();
		for (int k = 0; k < PuzyrSize; k++) std::cout << nums[k] << std::endl;
		for (int k = 0; k < PuzyrSize; k++) {
			bool flag = true;
			for (int j = 0; j < PuzyrSize - (k + 1); j++) {
				if (nums[j] > nums[j + 1]) {
					flag = false;
					SwapINT(nums[j], nums[j + 1]);
				}
			}
			if (flag) {
				break;
			}

			std::cout << "Массив в отсортированном виде: " << std::endl;

			for (int k = 0; k < 10; k++) {
				std::cout << nums[k] << std::endl; 
			}

		}
	}

}