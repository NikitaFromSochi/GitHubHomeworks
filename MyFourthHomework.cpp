// MyFourthHomework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
int a, b, h, y;
const int c = 9;
const int d = 1;
bool pr = true;
int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите первое число" << std::endl;
    std::cin >> a;
    std::cout << "Введите второе число" << std::endl;
    std::cin >> b;
    if ((a + b) >= 10 && (a + b) <= 20)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }


    if ((c == 10 && d == 10) || (c + d == 10))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    std::cout << "Ваши числа: " << std::endl;
    for (int i = 1; i <= 50; i++)
        if (i % 2 != 0)
            std::cout << i << " ";
    std::cout << "." << std::endl;

    std::cout << "Введите любое число и программа определит, является ли оно простым" << std::endl;
    std::cin >> h;
    for (int i = 2; i < h; i++)
    {
        if (h % i == 0)
            pr = false;
    }
    if (pr == true)
        std::cout << "Простое число" << std::endl;
    else
        std::cout << "Число не является простым" << std::endl;

    std::cout << "Введите год от 1 до 3000 и программа определит, является ли он високосным" << std::endl;
    std::cin >> y;
    if ((y >= 400) && (y <= 3000) && (y % 400 == 0))
        std::cout << "Високосный" << std::endl;
        else if ((y >= 100) && (y <= 3000) && (y % 100 == 0))
        std::cout << "Не високосный" << std::endl;
        else if ((y >= 1) && (y <= 3000) && (y % 4 == 0))
        std::cout << "Високосный" << std::endl;
        
        else
        std::cout << "Не високосный" << std::endl;
    
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"


