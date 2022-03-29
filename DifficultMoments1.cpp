#include <iostream>
#include <string>
#include <optional>
#include <set>
#include <tuple>
#include <algorithm>
#include <fstream>
#include <vector>
#include <istream>

// Task 1;
struct Person
{
private:
	std::string name;
	std::string sur;
	std::string patr;
public:
	Person() {}
	Person(std::string n, std::string s) : name(n), sur(s)
	{}
	Person(std::string n, std::string s, std::string p) : Person(n, s)
	{
		patr = p;
	}
	friend std::ostream& operator<<(std::ostream& os, const Person& a);
};

std::ostream& operator<<(std::ostream& out, const Person& a)
{
	out << a.patr << " " << a.name << " " << a.sur;
	return out;
}

// Task 2

struct PhoneNumber
{
	unsigned int countryCode, cityCode, addNum;
	std::string callNumber;
	PhoneNumber(unsigned int cc1 = 0, unsigned int cc2 = 0, const std::string& str = "null", unsigned int add = 0) :countryCode(cc1), cityCode(cc2), callNumber(str), addNum(add) {};
	friend std::ostream& operator<<(std::ostream& out, const PhoneNumber& a);
}number{ 7, 911, "1234567", 12 };

std::ostream& operator<<(std::ostream& out, const PhoneNumber& a)
{
	out << "+" << a.countryCode << "(" << a.cityCode << ")" << a.callNumber << " " << a.addNum;
	return out;
}

// Task 3

class PhoneBook {
private:
	std::vector<std::pair<Person, PhoneNumber>> vec_p_book;
public:
	PhoneBook(std::ifstream& file) {
		if (file.is_open())
		{
			std::string str;
			std::istringstream ist;
			unsigned int n;
			Person person;
			PhoneNumber pNum;
			int count{ 0 };
			bool is_person{ 0 };
			bool is_pNum{ 0 };

			while (!file.eof()) {
				str = "";
				ist.clear();
				if (count <= 6) {
					switch (count)
					{
					case 0:
						file >> person.m_F;
						break;
					case 1:
						file >> person.m_I;
						break;
					case 2:
						file >> str;
						if (str != "-")
							person.m_O = std::make_optional(str);
						is_person = true;
						break;
					case 3:
						file >> pNum.coCode;
						break;
					case 4:
						file >> pNum.m_city_code;
						break;
					case 5:
						file >> pNum.number;
						break;
					case 6:
						file >> str;
						if (str != "-") {
							ist.str(str);
							ist >> n;
							pNum.m_extension_number = std::make_optional(n);
						}
						is_pNum = true;
						break;
					default:
						break;
					}
				}
				count++;
				if (is_person && is_pNum) {
					vec_p_book.push_back(std::pair<Person, PhoneNumber>(person, pNum));
					is_person = false;
					is_pNum = false;
					count = 0;
					person.m_O.reset();
					pNum.m_extension_number.reset();
				}
			}
		}
		file.close();
	}

	friend void operator << (std::ostream& out, const PhoneBook& phone_book) {
		for (auto& [p, f] : phone_book.vec_p_book)
			std::cout << p << "\t" << f << std::endl;
	}

	void SortByName() {
		std::sort(vec_p_book.begin(), vec_p_book.end(),
			[&](const std::pair<Person, PhoneNumber>& L, const std::pair<Person, PhoneNumber>& R) {
				return L.first < R.first;
			});
	};

	void SortByPhone() {
		std::sort(vec_p_book.begin(), vec_p_book.end(),
			[&](const std::pair<Person, PhoneNumber>& L, const std::pair<Person, PhoneNumber>& R) {
				return L.second < R.second;
			});
	};


	std::pair<std::string, PhoneNumber> GetPhoneNumber(const std::string& surname) {
		PhoneNumber tmp;
		PhoneNumber number;
		unsigned int count{ 0 };
		for (auto& [p, f] : vec_p_book) {
			if (p.m_F == surname) {
				count++;
				if (count == 1)
					number = f;
			}
		}

		if (count == 1)
			return std::pair<std::string, PhoneNumber>("", number);
		if (count == 0)
			return std::pair<std::string, PhoneNumber>("not found", tmp);
		if (count > 1)
			return std::pair<std::string, PhoneNumber>("found more than 1", tmp);
	}

	void ChangePhoneNumber(const Person& person, const PhoneNumber& pNum) {
		for (auto& [p, f] : vec_p_book) {
			if (person == p)
				f = pNum;
		}
	}
};

int main() {

	std::cout << std::boolalpha;

	std::ifstream file("PhoneBook.txt");

	PhoneBook book(file);

	std::cout << book;

	std::cout << "------SortByPhone-------" << std::endl;
	book.SortByPhone();
	std::cout << book;

	std::cout << "------SortByName--------" << std::endl;
	book.SortByName();
	std::cout << book;

	std::cout << "-----GetPhoneNumber-----" << std::endl;
	
	auto print_pNum = [&book](const std::string& surname) {
		std::cout << surname << "\t";
		auto answer = book.GetPhoneNumber(surname);
		if (get<0>(answer).empty())
			std::cout << get<1>(answer);
		else
			std::cout << get<0>(answer);
		std::cout << std::endl;
	};

	print_pNum("Ivanov");
	print_pNum("Petrov");

	std::cout << "----ChangePhoneNumber----" << std::endl;
	book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 7, 123, "15344458", std::nullopt });
	book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });
	std::cout << book;

	return 0;
}
