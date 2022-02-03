// Krestiki-Noliki.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include "KrestLib.h"
#include <chrono>
#include <stdlib.h>

using namespace std;

enum KrestCell : char {
    Cross = 'X',
    Zero = '0',
    Empty = '_'
};

enum KrestProgress {
    InProgress,
    ManWin,
    CompWin,
    Draw
};

struct KrestCoord {
    size_t x{ 0U };
    size_t y{ 0U };
};

struct KrestGame {
    KrestCell** ppField = nullptr;
    const size_t Size{ 4U };
    KrestCell Man;
    KrestCell Comp;
    KrestProgress Progress{ InProgress };
    size_t turn{ 0U };
};

inline void ClearScr()
{
    std::cout << "\x1B[2J\x1B[H";
}

int32_t __fastcall GetRandomNum(int32_t min, int32_t max)
{
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

void __fastcall InitGame(KrestGame& g)
{
    g.ppField = new KrestCell * [g.Size];
    for (size_t i = 0; i < g.Size; i++)
    {
        g.ppField[i] = new KrestCell[g.Size];
    }

    for (size_t x = 0; x < g.Size; x++)
    {
        for (size_t y = 0; y < g.Size; y++)
        g.ppField[x][y] = Empty;
    }

    if (GetRandomNum(0, 1000) > 500 )
    {
        g.Man = Cross;
        g.Comp = Zero;
        g.turn = 0;
    }
    else
    {
        g.Man = Zero;
        g.Comp = Cross;
        g.turn = 1;
    }
}

void __fastcall DeinitGame(KrestGame& g)
{
    for (size_t i = 0; i < g.Size; i++)
    {
        delete[] g.ppField[i];
    }
    delete g.ppField;
    g.ppField = nullptr;
}

void __fastcall DrawGame(const KrestGame& g)
{
    std::cout << "     ";
    for (size_t y = 0; y < g.Size; y++)
        std::cout << y + 1 << "   ";
        std::cout << std::endl;
    for (size_t x = 0; x < g.Size; x++)
    {
        std::cout << " " << x + 1 << " | ";
        for (size_t y = 0; y < g.Size; y++)
        {
            std::cout << g.ppField[x][y] << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Man:" << g.Man << std::endl << "----------" << std::endl << "Computer:" << g.Comp << std::endl;
}

void  __fastcall Congrats(const KrestGame& g)
{
    if (g.Progress == ManWin)
        std::cout << "You win, congratulations!" << std::endl;
    else if (g.Progress == CompWin)
        std::cout << "Sorry, but computer win :/" << std::endl;
    else if (g.Progress == Draw)
        std::cout << "No one can win in this battle!" << std::endl;
}

 int GetWon(const KrestGame& g)
{
    for (size_t x = 0; x < g.Size; x++)
    {
        if (g.ppField[x][0] == g.ppField[x][1] && g.ppField[x][0] == g.ppField[x][2])
        {
            if (g.ppField[x][0] == g.Man)
                return ManWin;

            if (g.ppField[x][0] == g.Comp)
                return CompWin;
        }
        if (g.ppField[x][1] == g.ppField[x][2] && g.ppField[x][1] == g.ppField[x][3])
        {
            if (g.ppField[x][1] == g.Man)
                return ManWin;

            if (g.ppField[x][1] == g.Comp)
                return CompWin;
        }
        for (size_t y = 0; y < g.Size; y++)
        {
            if (g.ppField[0][y] == g.ppField[1][y] && g.ppField[0][y] == g.ppField[2][y])
            {
                if (g.ppField[0][y] == g.Man)
                    return ManWin;

                if (g.ppField[0][y] == g.Comp)
                    return CompWin;
            }
            if (g.ppField[1][y] == g.ppField[2][y] && g.ppField[1][y] == g.ppField[3][y])
            {
                if (g.ppField[1][y] == g.Man)
                    return ManWin;

                if (g.ppField[1][y] == g.Comp)
                    return CompWin;
            }
        }
        if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2])
        {
            if (g.ppField[0][0] == g.Man)
                return ManWin;

            if (g.ppField[0][0] == g.Comp)
                return CompWin;
        }
        if (g.ppField[1][1] == g.ppField[2][2] && g.ppField[1][1] == g.ppField[3][3])
        {
            if (g.ppField[1][1] == g.Man)
                return ManWin;

            if (g.ppField[1][1] == g.Comp)
                return CompWin;
        }
        if (g.ppField[0][3] == g.ppField[1][2] && g.ppField[0][3] == g.ppField[2][1])
        {
            if (g.ppField[0][3] == g.Man)
                return ManWin;

            if (g.ppField[0][3] == g.Comp)
                return CompWin;
        }
        if (g.ppField[1][2] == g.ppField[2][1] && g.ppField[1][2] == g.ppField[3][0])
        {
            if (g.ppField[1][2] == g.Man)
                return ManWin;
            if (g.ppField[1][2] == g.Comp)
                return CompWin;
        }
        if (g.ppField[0][2] == g.ppField[1][1] && g.ppField[0][2] == g.ppField[2][0])
        {
            if (g.ppField[0][2] == g.Man)
                return ManWin;

            if (g.ppField[0][2] == g.Comp)
                return CompWin;
        }
        if (g.ppField[1][3] == g.ppField[2][2] && g.ppField[1][3] == g.ppField[3][1])
        {
            if (g.ppField[1][3] == g.Man)
                return ManWin;

            if (g.ppField[1][3] == g.Comp)
                return CompWin;
        }
        if (g.ppField[0][1] == g.ppField[1][2] && g.ppField[0][1] == g.ppField[2][3])
        {
            if (g.ppField[0][1] == g.Man)
                return ManWin;

            if (g.ppField[0][1] == g.Comp)
                return CompWin;
        }
        if (g.ppField[1][0] == g.ppField[2][1] && g.ppField[1][0] == g.ppField[3][2])
        {
            if (g.ppField[1][0] == g.Man)
                return ManWin;

            if (g.ppField[1][0] == g.Comp)
                return CompWin;
        }
    }
    bool draw = true;
    for (size_t x = 0; x < g.Size; x++)
    {
        for (size_t y = 0; y < g.Size; y++)
        {
            if (g.ppField[x][y] == Empty)
            {
                draw = false;
                break;
            }
        }
        if (!draw)
            break;
    }
    if (draw)
        return Draw;

    return InProgress;
}

KrestCoord GetManCoord(const KrestGame& g)
{
    KrestCoord c;
        do
        {
            std::cout << "Enter Y: (1..4)" << std::endl;
            cin >> c.x;
            std::cout << "Enter X: (1..4)" << std::endl;
            cin >> c.y;

            c.x--;
            c.y--;
        } while (c.x > 3 || c.y > 3 || g.ppField[c.x][c.y] != Empty);
            return c;
}

KrestCoord GetCompCoord(KrestGame& g)
{
    for (size_t x = 0; x < g.Size; x++)
    {
        for (size_t y = 0; y < g.Size; y++)
        {
            if (g.ppField[x][y] == Empty)
            {
                g.ppField[x][y] = g.Comp;
                if (GetWon(g) == CompWin)
                {
                    g.ppField[x][y] == Empty;
                    return { x, y };
                }
                g.ppField[x][y] == Empty;
            }
        }
    }
    for (size_t x = 0; x < g.Size; x++)
    {
        for (size_t y = 0; y < g.Size; y++)
        {
            if (g.ppField[x][y] == Empty)
            {
                g.ppField[x][y] = g.Man;
                if (GetWon(g) == ManWin)
                {
                    g.ppField[x][y] == Empty;
                    return { x, y };
                }
                g.ppField[x][y] == Empty;
            }
        }
    }
}

int main()
{
    KrestGame(g);
    InitGame(g);
    ClearScr();
    DrawGame(g);

    do {
        if (g.turn % 2 == 0)
        {
            KrestCoord c = GetManCoord(g);
            g.ppField[c.x][c.y] = g.Man;
        }
        else
        {
            KrestCoord c = GetCompCoord(g);
            g.ppField[c.x][c.y] = g.Comp;
        }

        g.turn++;
        ClearScr();
        DrawGame(g);
        g.Progress == GetWon(g);

    } while (g.Progress == InProgress);

    Congrats(g);
    DeinitGame(g);
    return 0;
}

