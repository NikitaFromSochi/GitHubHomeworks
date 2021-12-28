// GeekBrainsSecondHomework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>

struct Game // Новый тип данных игра
{
    unsigned short size; // размер поля
    unsigned short difficulty; // сложность игры
    double points; // количество очков в случае победы
};

union MyVariant // моя кастомная структура
{
    int BotIq; // АйКью бота
    float MyMultiplier; // Множитель очков в зависимости от сложности
    char MyPin; // возможность выбора другого знака вместо Х
    
};

int main()
{
    setlocale(LC_ALL, "Russian");
    
    // short int, int, long long, char, bool, float, double
    short int First = 3270;
    int Second = 2345678;
    long long Third = -9876543211234;
    char Fourth = 'b';
    bool Fifth = true;
    float Sixth = 3.14f;
    double Seventh = -54345678.98765;
    std::cout << First << " , " << Second << " , " << Third << " , " << Fourth << " , " << Fifth << " , " << Sixth << " , " << Seventh << std::endl;

   
    enum  MyGame { x, o};
        MyGame noteX[1] = { x };
        MyGame noteO[1] = { o };
        MyGame NumberOne = x;
        MyGame NumberTwo = o;
        std::cout << NumberOne <<std::endl;
        std::cout << NumberTwo << std::endl;
    
    MyGame arr[3][3] = { 0 }; 
        std::cout << "| " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << " | \n" << "-------------\n" << "| " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << " | \n" << "-------------\n" << "| " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << " | \n";
        arr[0][0] = NumberOne;
        arr[0][1] = NumberTwo;

    Game v1, v2;
        v1.size = 3;
        v1.difficulty = 31;
        v1.points = 120'000.0;
        v2 = { 5, 28, 750'000.0 };

     MyVariant info;
        info.BotIq = 25;
        std::cout << info.BotIq << std::endl; // Выведет на экран: 25
        info.MyPin = 'm';
        std::cout << info.MyPin << std::endl; // Выведет на экран: m
        info.MyMultiplier = 3.75;
        std::cout << info.MyMultiplier << std::endl; // Выведет на экран: 3.75
        
        
        
        
    
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

