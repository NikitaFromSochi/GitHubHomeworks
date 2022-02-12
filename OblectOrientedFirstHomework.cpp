// OblectOrientedFirstHomework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdint>

class Power  {
public:
    int FirstNumber;
    int SecondNumber;

    void Set()
    {
        FirstNumber = 7;
        SecondNumber = 4;
    }

    void Calculate()
    {
        int Result = pow(FirstNumber, SecondNumber);
        std::cout << Result << std::endl;
    }
};

 class RGBA {
 public:
    std::uint8_t  m_red = 0;
    std::uint8_t  m_green = 0;
    std::uint8_t  m_blue = 0;
    std::uint8_t  m_alpha = 255;

    void Task()
    {
        std::cout << "Vvedite chicloviye znacheniya dlya 4 peremenniyh" << std::endl;
        std::cin >> m_red;
        std::cin >> m_green;
        std::cin >> m_blue;
        std::cin >> m_alpha;
    };
   

    void FirstPrint()
    {
        std::cout << m_red << " , " << m_green << " , " << m_blue << " , " << m_alpha << std::endl;
    }
};

class Stack 
{

public:

    void reset() 
    {

    };

    void print()
    {

    };

    void push()
    {

    };

    void pop()
    {

    };

};

int main()
{
    Power Start;
    Start.Set();
    Start.Calculate();


    RGBA Go;
    Go.Task();
    Go.FirstPrint();


    Stack stack;
    stack.reset();
    stack.print();

    stack.push();
    stack.push();
    stack.push();
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}

