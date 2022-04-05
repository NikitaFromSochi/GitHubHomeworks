

#include <iostream>
#include <list>
#include <vector>
#include "../../../../AppData/Local/Temp/~vs599F.h"
using namespace std;

//task 2

int32_t Matrix::getRandNum(int32_t min, int32_t max)
{
	const static auto seeded = chrono::system_clock::now().time_since_epoch().count();
	static mt19937_64 generator(seeded);
	uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}

Matrix::Matrix(size_t matrixSize) : Size(matrixSize)
{
	if (Size <= 0)
	{
		cout << "Матрица не существует!" << endl;
		return;
	}
	matrix = new double* [Size];
	for (size_t i = 0; i < Size; i++)
	{
		matrix[i] = new double[Size];
	}
	for (size_t i = 0; i < Size; i++)
	{
		for (size_t j = 0; j < Size; j++)
		{
			matrix[i][j] = getRandNum(-1000, 1000);
		}
	}
}

double** Matrix::getMatrix() const
{
	return matrix;
}

size_t Matrix::getSize() const
{
	return Size;
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < getSize(); i++)
	{
		delete[] getMatrix()[i];
	}
	delete[] getMatrix();
}

double Matrix::Determ(double** mtx, size_t mSize)
{
	if (mSize == 1)
	{
		return mtx[0][0];
	}
	else if (mSize == 2)
	{
		return (mtx[0][0] * mtx[1][1]) - (mtx[0][1] * mtx[1][0]);
	}
	else
	{
		double determinate = 0;
		for (size_t k = 0; k < mSize; k++)
		{
			double** m = new double* [mSize - 1];
			for (int i = 0; i < mSize - 1; i++)
			{
				m[i] = new double[mSize - 1];
			}
			for (size_t i = 1; i < mSize; i++)
			{
				size_t t = 0;
				for (size_t j = 0; j < mSize; j++)
				{
					if (j == k)
					{
						continue;
					}
					m[i - 1][t] = mtx[i][j];
					t++;
				}
			}
			determinate += pow(-1, k + 2) * mtx[0][k] * Determ(m, mSize - 1);
		}
		return determinate;
	}
}

void Matrix::Print() const
{
	cout << setw(11) << "Матрица " << Size << "x" << Size << endl << setw(5);
	for (size_t i = 0; i < Size; i++)
	{
		for (size_t j = 0; j < Size; j++)
		{
			cout << matrix[i][j] << setw(5);
		}
		cout << endl;
	}
}

//task 3

class Range
{
private:
	class Impl
	{
	public:
		Impl(const size_t v, const vector<int>& values) : i_idx(v), i_values(values) {}
		auto operator*() const { return i_values[i_idx]; }
		auto& operator++()
		{
			i_idx++;
			return *this;
		}
		bool operator!=(const Impl& rhs) const { return i_idx != rhs.i_idx; }

	private:
		size_t i_idx;
		const vector<int>& i_values;
	};

public:
	Range(const vector<int>& values) : r_values(values) {}
	typedef Impl iterator;
	iterator begin() const { return Impl(0, r_values); }
	iterator end() const { return Impl(r_values.size(), r_values); }

private:
	const vector<int>& r_values;
};

int main()
{
	//task 1
	setlocale(LC_ALL, "Russian");
	double average{};
	list<double> numbers{ 801.66, 321.92, -124.22, 982.36, -51.42, 863.21, 510.58, -453.96,
		502.32, 100.90, 356.88, 825.74, 158.25, -12.11, 213.33, 256.23 };
	for (auto n : numbers)
	{
		average += n;
	}
	average /= numbers.size();
	numbers.push_back(average);
	cout << "Cреднее значение всех элементов в конце списка:" << endl;
	for (auto n : numbers)
	{
		cout << n << "\t";
	}

	//task 2
	Matrix m(4);
	m.Print();
	cout << endl << "Определитель матрицы = " << m.Determ(m.getMatrix(), m.getSize());
	cout << endl;

	//task 3
	const vector<int> integer = { 1, 2, 3, 4, 5, 6 };
	for (const int& i : Range(integer))
	{
		cout << i << endl;
	}
	return 0;
}