#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct FVector2D
{
    int X;
    int Y;
};

void SetLocation(FVector2D NewLocation);


int main()
{
    bool bRunning = true;
    FVector2D PlayerPosition;
    PlayerPosition.X = 1;
    PlayerPosition.Y = 1;

    while (bRunning)
    {
        int KeyCode = _getch();

        switch (KeyCode)
        {
        case 'w':
        case 'W':
            PlayerPosition.Y--;
            break;
        case 's':
        case 'S':
            PlayerPosition.Y++;
            break;
        case 'a':
        case 'A':
            PlayerPosition.X--;
            break;
        case 'd':
        case 'D':
            PlayerPosition.X++;
            break;
        case 27:
            bRunning = false;
            break;

        }

        PlayerPosition.X = PlayerPosition.X < 11 ? 11 : PlayerPosition.X;
        PlayerPosition.Y = PlayerPosition.Y < 6 ? 6 : PlayerPosition.Y;
        PlayerPosition.X = PlayerPosition.X > 27 ? 27 : PlayerPosition.X;
        PlayerPosition.Y = PlayerPosition.Y > 13 ? 13 : PlayerPosition.Y;

        system("cls");

    int Map[15][15] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, }
    };
    for (int Y = 0; Y < 15; ++Y)
    {
        for (int X = 0; X < 15; ++X)
        {
            if (Map[Y][X] == 1)
            {
                cout << '#' << ' ';
            }
            else if (Map[Y][X] == 0)
            {
                cout << ' ' << ' ';
            }
           
            
        }
        cout << '\n';
    }
    

    SetLocation(PlayerPosition);
    cout << "P";
    }



    return 0;
}


void SetLocation(FVector2D NewLocation)
{
    COORD Cur;
    Cur.X = NewLocation.X;
    Cur.Y = NewLocation.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
