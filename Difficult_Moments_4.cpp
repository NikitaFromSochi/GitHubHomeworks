#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

//task 1

template <class Container, class T>
void insert_sorted(Container& cont, const T& value)
{
	typename Container::iterator iter = upper_bound(begin(cont), end(cont), value);
	cont.insert(iter, value);
}

int main()
{
	//task 1

	vector<int> num = { 1,2,3,4,6 };
	insert_sorted(num, 5);
	for (const auto& n : num)
	{
		cout << n << " ";
	}
	cout << endl;
	list<string> str = { "a","c","d","e","f" };
	insert_sorted(str, "b");
	for (const auto& s : str)
	{
		cout << s << " ";
	}

	//task 2

	setlocale(LC_ALL, "Russian");

	vector<double> vectors(100);
	double analog = 0.0;
	generate(vectors.begin(), vectors.end(), [&analog](const double pi = atan(1.0) * 4)
		mutable {analog += (2 * pi / 100); return (32 * sin(analog) + 100); });
	cout << "Аналог:" << endl;

	copy(vectors.begin(), vectors.end(), ostream_iterator<double>{cout, "\t"});
	cout << endl;

	vector<double> v;
	auto digit = [](double d) {return trunc(d); };
	transform(vectors.begin(), vectors.end(), back_inserter(v), digit);
	cout << "Цифра:" << endl;

	copy(v.begin(), v.end(), ostream_iterator<double>{cout, "\t"});

	cout << endl;

	vector<double> e;
	transform(vectors.begin(), vectors.end(), v.begin(), back_inserter(e), [](double i, double j)
		{return pow((i - j), 2); });
	cout << "Погрешности = " << accumulate(begin(e), end(e), decltype(e)::value_type(0.0)) << endl;

	return 0;
}