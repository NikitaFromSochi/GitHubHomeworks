

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <cassert>


using namespace std;

void print(vector<int>& a) {
    std::cout << "The length is: " << a.size() << '\n';

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';

    cout << endl;
}




int dat()
{
    return rand() % 10 + 1;
}

class Hand
{
protected:
    std::vector<Card*> hand;
public:
    void Add ( Card* input )
    {
        hand.push_back (input);
    }

    void Clear()
    {
        hand.clear();
    }

    int GetValue() const
    {
        int sum = 0;
        bool hasAce = false;
        for (Card* card : hand)
        {
            if (card->getValue() >= HIGHESTCARDVALUE)
            {
                sum += HIGHESTCARDVALUE;
            }
            else if (card->getValue() == ACE)
            {
                hasAce = true;
            }
            else
            {
                sum += card->getValue();
            }

            if (hasAce && (sum + ACEMAXVALUE <= MAXPOINTSTOWIN))
            {
                sum += ACEMAXVALUE;
            }
            else if (hasAce && (sum + ACEMAXVALUE > MAXPOINTSTOWIN))
            {
                sum += ACEMINVALUE;
            }
        }
        return sum;
    }

    virtual ~Hand()
    {
        Clear();
    }
};


int main()
{
    vector<int> array{ 0, 1, 2, 3 };

    array.resize(7); // изменяем длину array на 7
    print(array);

    array.pop_back();
    print(array);

    array.pop_front();
    print(array);

    int N;
    cout << "N=";
    vector<int> v(N);
    generate(v.begin(), v.end(), dat);
    set<int> s(v.begin(), v.end());
    cout << "Total different numbers=" << s.size() << endl << "They are: ";
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    system("pause");

    return 0;
}


