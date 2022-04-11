﻿#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

//task 1

template <class Iter>
void uniuqeWord(Iter begin, Iter end)
{
	unordered_set<string> unique;
	copy(begin, end, inserter(unique, unique.begin()));
	for (const auto& w : unique)
	{
		cout << w << "\t";
	}
	cout << endl;
}

int main()
{
	//task 1

	vector<string> word =
	{ "rolls", "near", "no", "hay", "how", "belong", "couldn't", "be", "much", "speciphic", "from", "cry", "hearts", "old",
		"god", "who", "we", "are", "and", "nothing", "else", "relationship", "never", "opened", "myself", "this", "way",
		"life", "is", "it", "we", "lived", "so", "it", "noway", "all", "these" "words", "i", "don't", "just", "say", "and",
		"rolls", "else", "how"
	};
	uniuqeWord(word.begin(), word.end());

	//task 2

	setlocale(LC_ALL, "Russian");

	string text;
	string separators = ".!?";
	string temp;
	cout << "Ввод текста для разделения на предложения (в конце предложения обязательны для ввода следующие знаки: (. ! ?): " << endl;
	getline(cin, text);
	multimap<size_t, string> split;
	for (auto iter = text.begin(); iter != text.end(); iter++)
	{
		auto sent = find_first_of(iter, text.end(), separators.begin(), separators.end());
		if (sent != text.end())
		{
			auto sentBegin = distance(text.begin(), iter);
			auto sentEnd = distance(text.begin(), sent);
			temp = text.substr(sentBegin, sentEnd - sentBegin + 1);
			iter = sent;
			if (temp[0] == ' ')
			{
				temp = temp.substr(1);
			}
			split.emplace(temp.size(), temp);
		}
	}
	cout << endl << "Отсортированные по длине предложения: " << endl;
	for (const auto& n : split)
	{
		cout << n.second << endl;
	}
	return 0;
}
