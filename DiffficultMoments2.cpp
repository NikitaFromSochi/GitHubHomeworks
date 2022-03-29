#include <iostream>
#include <vector>
#include "chrono"
#include <string>
#include <fstream>
#include <algorithm>
#include "../../DifficultMoments2/DifficultMoments2/Timer.h"
using namespace std;

// Task 1

void swap(int* a, int* b)
{
	a = b;
	b = a;
}

auto swap()
{
	int a1 = 1, a2 = 2;
	swap(a1, a2);
	cout << a1 << " " << &a1 << " " << a2 << " " << &a2;
	return 0;
}

// Task 2

void sortPointers(std::vector<int*>& v) {
	int size = v.size();
	for (int i = v.size() - 1; i < size; i++)
	{
		for (int q = i + 1; q < size; q++)
		{
			if (*v[i] > *v[q])
				swap(v[i], v[q]);
		}
	}
}

auto sortPointers() {
	std::vector<int*> v;
	std::vector<int*> v1;
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (int i = 0; i < 10; i++)
	{
		v1[i] = arr + i;
		v.push_back(v1[i]);
	}

	int size = v.size();
	for (int i = 0; i < size; i++)
		cout << *v[i] << " ";
	cout << "\n";
	for (int i = 0; i < size; i++)
		cout << *v[i] << " ";
	cout << "\n";
	return 0;
}

// Task 3

auto WarAndPeace() {
	Timer t;
	std::ifstream in("WarAndPeace.txt");
	in.seekg(0, std::ios::end);
	size_t size = static_cast<size_t>(in.tellg());
	in.seekg(0);
	std::string sz(size, ' ');
	in.read(&sz[0], size);
	in.close();
	uint32_t count_vow = { 0 };
	std::string vow = "AEIOUYaeiouy";

	t.start("Count_if+Find");
	count_vow = std::count_if(sz.begin(), sz.end(), [&vow](auto str) {
		return vow.find(str) != std::string::npos ? true : false;
		});
	t.print();
	std::cout << "count of vowels: " << count_vow << std::endl;
	count_vow = 0;

	t.start("Count_if+for");
	for (const char iwow : vow)
	{
		count_vow += std::count_if(sz.begin(), sz.end(), [&iwow](auto str)->bool {return iwow == str; });
	}
	t.print();
	std::cout << "count of vowels: " << count_vow << std::endl;
	count_vow = 0;

	t.start("For+find");
	size_t ps{};
	for (auto isz : sz)
	{
		ps = vow.find(isz);
		if (ps != std::string::npos)
			count_vow++;
	}
	t.print();
	std::cout << "count of vowels: " << count_vow << std::endl;
	count_vow = 0;

	t.start("For+for");
	for (auto _vow : vow)
	{
		for (auto _wd : sz)
		{
			if (_vow == _wd)
				count_vow++;
		}
	}
	t.print();
	std::cout << "count of vowels: " << count_vow << std::endl;
	count_vow = 0;

	return 0;
}

int main()
{
	swap();
	sortPointers();
	WarAndPeace();
	system("pause");
	return 0;
}
