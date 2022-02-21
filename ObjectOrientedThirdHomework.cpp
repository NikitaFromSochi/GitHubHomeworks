// ObjectOrientedThirdHomework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "cmath"
#include "cassert"

class Figure 
{
public:
   
    virtual int Area() = 0;
};

class Parallelogramm : public Figure
{
protected:
    int m_Length;
    int m_Width;
    int m_Height;
public:
    int getLength() const { return m_Length; }
    int getWidth() const { return m_Width; }
    int getHeight() const { return m_Height; }
   

    Parallelogramm ( int Length = 0, int Width = 0, int Height = 0)
        : m_Length(Length), m_Width(Width), m_Height(Height)
    {}

    virtual int Area() override { m_Length * m_Width * m_Height; }
};


class Circle : public Figure
{
protected:
    int m_Radius;
public:
    int getRadius() const { return m_Radius; }
    

    Circle ( int Radius = 0)
        : m_Radius(Radius)
    {}

    virtual int Area() override { m_Radius* m_Radius * 3.14; }

};

class Rectangle : public Parallelogramm
{
protected:
    int m_RectangleLength;
    int m_RectangleWidth;
public:
    

    Rectangle ( int RectangleLength = 0, int RectangleWidth = 0)
        : m_RectangleLength(RectangleLength), m_RectangleWidth(RectangleWidth)
    {}

    virtual int Area() override { m_RectangleLength* m_RectangleWidth; }

};

class Sguare : public Parallelogramm
{
protected:
    int m_SquareLenght;
public:
    

    Sguare ( int SquareLength = 0)
        : m_SquareLenght(SquareLength)
    {}

    virtual int Area() override { m_SquareLenght* m_SquareLenght; }

};

class Rhombus : public Parallelogramm
{
protected:
    int m_Diagonal1;
    int m_Diagonal2;
public:
   
    Rhombus (int Diagonal1 = 0, int Diagonal2 = 0)
        : m_Diagonal1(Diagonal1), m_Diagonal2(Diagonal2)
    {}

    virtual int Area() override { m_Diagonal1* m_Diagonal2 * 0.5; }

};

class Car
{
protected:
    std::string company, model;
public:
    Car() {}
    Car(std::string inputCompany, std::string inputModel)
        : company(inputCompany), model(inputModel)
    {
        std::cout << "\nBase car constructor";
    }

    virtual ~Car()
    {
        std::cout << "\nBase car destructor";
    }
};

class PassengerCar : virtual public Car
{
public:
    PassengerCar() {}
    PassengerCar(std::string inputCompany, std::string inputModel)
        : Car(inputCompany, inputModel)
    {
        std::cout << "\nPassenger car constructor";
        std::cout << "\n" << company << " " << model;
    }

    std::string getModel()
    {
        return model;
    }

    ~PassengerCar()
    {
        std::cout << "\nPassenger car destructor";
    }
};

class Bus : virtual public Car
{
public:
    Bus() {}
    Bus(std::string inputCompany, std::string inputModel)
        : Car(inputCompany, inputModel)
    {
        std::cout << "\nBus constructor";
        std::cout << "\n" << company << " " << model;
    }

    ~Bus()
    {
        std::cout << "\nBus destructor";
    }
};

class Minivan : public PassengerCar, public Bus
{
public:
    Minivan(std::string inputCompany, std::string inputModel)
        : Car(inputCompany, inputModel)
    {
        std::cout << "\nMinivan constructor";
        std::cout << "\n" << company << " " << model;
    }

    ~Minivan()
    {
        std::cout << "\nMinivan destructor";
    }
};

class Fraction
{
private:
    double numerator, denominator;
public:
    Fraction(double inputNumerator, double inputDenominator)
        : numerator(inputNumerator), denominator(inputDenominator)
    {
        if (denominator == 0) denominator = 0.00000001;
    }

    friend Fraction operator+(const Fraction& d1, const Fraction& d2);
    friend Fraction operator-(const Fraction& d1, const Fraction& d2);
    friend Fraction operator*(const Fraction& d1, const Fraction& d2);
    friend Fraction operator/(const Fraction& d1, const Fraction& d2);
    friend Fraction operator-(const Fraction& d1);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);

    void setDenominator(double inputDenominator)
    {
        if (inputDenominator == 0) inputDenominator = 0.00000001;
        denominator = inputDenominator;
    }

    void setNumerator(double inputNumerator)
    {
        numerator = inputNumerator;
    }

    double getNumerator()
    {
        return numerator;
    }

    double getDenominator()
    {
        return denominator;
    }
};

Fraction operator+(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator + d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator-(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator - d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator*(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.numerator, d1.denominator * d2.denominator);
}

Fraction operator/(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator, d1.denominator * d2.numerator);
}

Fraction operator-(const Fraction& d1)
{
    return Fraction(-d1.numerator, -d1.denominator);
}

bool operator==(Fraction& d1, Fraction& d2)
{
    if ((d1.getNumerator() == d2.getNumerator()) && (d1.getDenominator() == d2.getDenominator())) return true;
    else return false;
}

bool operator!=(Fraction& d1, Fraction& d2)
{
    if (d1 == d2) return false;
    else return true;
}

bool operator>(Fraction& d1, Fraction& d2)
{
    if ((d1.getNumerator() / d1.getDenominator()) > (d2.getNumerator() / d2.getDenominator())) return true;
    else return false;
}

bool operator<=(Fraction& d1, Fraction& d2)
{
    if (!(d1 > d2)) return true;
    else return false;
}

bool operator<(Fraction& d1, Fraction& d2)
{
    if ((d1.getNumerator() / d1.getDenominator()) < (d2.getNumerator() / d2.getDenominator())) return true;
    else return false;
}

bool operator>=(Fraction& d1, Fraction& d2)
{
    if (!(d1 < d2)) return true;
    else return false;
}


std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}


    enum Suit : char {
        Cross,
        Booby,
        Worms,
        Peaks
    };

    enum Meaning : char {
        ACE = 1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };

   
  
    class Card
    {
    private:
        Suit suit;
       Meaning meaning;
        bool isFaceUp;
    public:

        void Flip()
        {
            isFaceUp = !isFaceUp;
        }

        Meaning getValue()
        {
            return meaning;
        }
    };



int main()
{
    Car* car = new Car("Daewoo", "Matiz");
    std::cout << "\n==============================";
    PassengerCar* passengerCar = new PassengerCar("Mersedes", "X5");
    std::cout << "\n==============================";
    Bus* bus = new Bus("PAZ", "3201");
    std::cout << "\n==============================";
    Minivan* minivan = new Minivan("Volkswagen", "Caravelle");
    std::cout << "\n==============================";
    delete minivan;
    std::cout << "\n==============================";
    delete bus;
    std::cout << "\n==============================";
    delete passengerCar;
    std::cout << "\n==============================";
    delete car;

   
    Fraction d1(3, 2);
    Fraction d2(8, 3);
    std::cout << "\n\n" << (d1 + d2);
    std::cout << "\n\n" << (d1 - d2);
    std::cout << "\n\n" << (d1 * d2);
    std::cout << "\n\n" << (d1 / d2);
    std::cout << "\n\n" << (-d1) << "\n";

    if (d1 == d2) std::cout << "\nFraction 1 == Fraction 2";
    if (d1 != d2) std::cout << "\nFraction 1 != Fraction 2";
    if (d1 > d2) std::cout << "\nFraction 1 > Fraction 2";
    if (d1 <= d2) std::cout << "\nFraction 1 <= Fraction 2";
    if (d1 < d2) std::cout << "\nFraction 1 < Fraction 2";
    if (d1 >= d2) std::cout << "\nFraction 1 >= Fraction 2";
    return 0;
}

