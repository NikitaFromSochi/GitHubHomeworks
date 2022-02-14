// ObjectOrientedSecondHomework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class Person
{
    public:
        std::string m_Name;
        int m_Age;
        std::string m_Gender;
        int m_Weight;

        std::string getName() const { return m_Name; }
        int getAge() const { return m_Age; }
        std::string getGender() const { return m_Gender; }
        int getWeight() const { return m_Weight; }

        Person (std::string Name = "", int Age = 0, std::string Gender = "", int Weight = 0)
            : m_Name(Name), m_Age(Age), m_Gender(Gender), m_Weight(Weight)
        {}

        

};

class Student : public Person
{
public:
    int m_YearOfEducation;

    int GetYearOfEducation() const { return m_YearOfEducation; }

    Student (const char YearOfEducation = 0)
        : m_YearOfEducation(YearOfEducation)
    {}

    
};


class Fruit
{
    public:
        std::string m_Title;
        std::string m_Color;

        std::string getTitle() const { return m_Title; }
        std::string getColor() const { return m_Color; }

        Fruit (std::string Title = "", std::string Color = "")
            : m_Title(Title), m_Color(Color)
        {}

        
};

class Apple : public Fruit
{
public:
};

class Banana : public Fruit
{
public:
};

class GrannySmith : public Apple
{
public:
};


int main()
{


    Student Ivan;
    Ivan.m_Name = "Ivan";
    Ivan.m_Age = 19;
    Ivan.m_Gender = "Male";
    Ivan.m_Weight = 85;
    Ivan.m_YearOfEducation = 2;

    std::cout << "First Student name is " << Ivan.getName() << ", his age is" << Ivan.getAge() << ". Gender is " << Ivan.getGender() << "and weight is " << Ivan.getWeight() << ". Year of education is: " << Ivan.GetYearOfEducation() << std::endl;
    
    Student Mariya;
    Mariya.m_Name = "Maruya";
    Mariya.m_Age = 23;
    Mariya.m_Gender = "Female";
    Mariya.m_Weight = 135;
    Mariya.m_YearOfEducation = 7;

    std::cout << "Second Student name is " << Mariya.getName() << ", his age is" << Mariya.getAge() << ". Gender is " << Mariya.getGender() << "and weight is " << Mariya.getWeight() << ". Year of education is:" << Mariya.GetYearOfEducation() << std::endl;
   
    Student Semion;
    Semion.m_Name = "Semion";
    Semion.m_Age = 45;
    Semion.m_Gender = "Male";
    Semion.m_Weight = 70;
    Semion.m_YearOfEducation = 4;

    std::cout << "Third Student name is " << Semion.getName() << ", his age is" << Semion.getAge() << ". Gender is " << Semion.getGender() << "and weight is " << Semion.getWeight() << ". Year of education is: " << Semion.GetYearOfEducation() << std::endl;

    Apple a;
    a.m_Title = "Apple";
    a.m_Color = "Red";
    Banana b;
    b.m_Title = "Banana";
    b.m_Color = "Blue";
    GrannySmith c;
    c.m_Title = "GrannySmith";
    c.m_Color = "Yellow";

    std::cout << "My " << a.getTitle() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getTitle() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getTitle() << " is " << c.getColor() << ".\n";

    return 0;
}

// По поводу игры в БлэкДжек. Должны быть базовые классы Игрок, Компьютер и Карта, содержащая информацию о всех возможных 
// вариантах выпадения карты. Также должны быть наследованные классы состояния Игрока и Компьютера, показывающие выпавшую
// карту и количество очков у игроков. Соответственно, необходимо реализовать переход хода как метод. Также необходимо 
// создать метод, позволяющий игроку в каждый свой ход либо остановить набор карт либо взять ещё одну. И последний метод
// собирает информацию о количестве очков и уведомляет и проигрыше либо выигрыше. Возможно, его стоит внедрить в переход
// хода чтобы тот не происходил при определённом результате игры.
