
#include <iostream>
#include <cstdlib>
#include <string>

// Task 1

int getInt()
{
    std::string input;
    int intInput = 0;

    while (true)
    {
        bool formatCheck = true;
        std::cout << "Enter your number: ";
        std::getline(std::cin, input);
        for (unsigned int i = 0; i < input.length(); i++)
        {
            if (!isdigit(input[i])) formatCheck = false;
        }
        if (formatCheck)
        {
            intInput = std::stoi(input);
            return intInput;
        }
        else
        {
            system("cls");
            std::cerr << "Incorrect format!" << std::endl;
            std::cin.clear();
            //std::cin.ignore(10000, '\n');           
        }
    }
}

// Task 2

std::ostream& endll(std::ostream& stream)
{
    stream << "\n\n";
    stream.clear();
    return stream;
}


// Task 3

class Player : virtual public GenericPlayer
{
public:
    Player(const std::string& inputName)
        : GenericPlayer(inputName) {}
    virtual bool IsHitting() const override
    {
        while (true)
        {
            std::cout << *this;
            std::cout << "\nTake another card? (Y/N): ";
            bool formatCheck = true;
            std::string input;
            std::getline(std::cin, input);
            if (std::cin && (input == "N" || input == "n")) return false;
            else if (std::cin && (input == "Y" || input == "y")) return true;
            else
            {
                //system("cls");
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Incorrect input!";
            }
        }
    }
    void Win() const
    {
        std::cout << "\n" << name << " have Won!";
    }

    void Lose() const
    {
        std::cout << "\n" << name << " have Lost.";
    }

    void Push() const
    {
        std::cout << "\n" << name << " played a Draw";
    }
};

// Task 4

class House : virtual public GenericPlayer
{
public:
    House()
        : GenericPlayer("Dealer") {}

    virtual bool IsHitting() const override
    {
        if (GetValue() <= DEALERTAKETHRESHOLD) return true;
        else return false;
    }

    void FlipFirstCard()
    {
        hand.front()->Flip();
    }
};

// Task 5

class Card
{
protected:
    Suits suit = CLUBS;
    Ranks rank = ACE;
    bool isFaceUp = true;
public:
    Card() {}
    Card(Ranks inputRank, Suits inputSuit)
        : suit(inputSuit), rank(inputRank)
    {

    }
    void Flip()
    {
        isFaceUp = !isFaceUp;
    }

    Ranks getValue()
    {
        return rank;
    }

    Suits getSuit()
    {
        return suit;
    }

    std::string getSuitName() const
    {
        switch (suit)
        {
        case 0:
            return "Clubs";
        case 1:
            return "Diamonds";
        case 2:
            return "Hearts";
        case 3:
            return "Spades";
        default:
            return "";
        }
    }

    std::string getRankName() const
    {
        switch (rank)
        {
        case 1:
            return "Ace";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        case 10:
            return "Ten";
        case 11:
            return "Jack";
        case 12:
            return "Queen";
        case 13:
            return "King";
        default:
            return "";
        }
    }

    bool isFaceUpCheck()
    {
        if (isFaceUp) return true;
        else return false;
    }

    friend std::ostream& operator<<(std::ostream& out, const Card& card);
};

std::ostream& operator<<(std::ostream& out, const Card& card)
{
    if (card.isFaceUp)
    {
        out << card.getRankName() << " " << card.getSuitName() << "\n";
    }
    else out << "XX\n";
    return out;
}


int main()
{
    {
        int result = getInt();
        std::cout << "Your number is " << result << endll << "Task 2 test";
    }

    return 0;
}

