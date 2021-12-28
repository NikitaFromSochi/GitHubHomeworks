// GeekBrainsSecondHomework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>

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

   
    enum  Variant {X, x, O, o};
    Variant noteX[2] = { X, x };
    Variant noteO[2] = { O, o };
    Variant NumberOne = x;
    std::cout << NumberOne <<std::endl;
    unsigned char Zerous[3][3] = {{x,X,o},{O,o,x},{O,x,o}}; // Вроде прописал нужный тип данных, но выводятся не те символы, что мне нужны. Плюс, наврное, надо результаты перечисления предоставлять как возможные для ввода игроком во время работы приложения и подставлять в ячейки массива? Если да, то пока не понимаю, как сделать.
    std::cout << "| " << Zerous[0][0] << " | " << Zerous[0][1] << " | " << Zerous[0][2] << " | \n" << "-------------\n" << "| " << Zerous[1][0] << " | " << Zerous[1][1] << " | " << Zerous[1][2] << " | \n" << "-------------\n" << "| " << Zerous[2][0] << " | " << Zerous[2][1] << " | " << Zerous[2][2] << " | \n";
    
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

