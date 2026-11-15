#include "ConsoleUtils.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <windows.h>

using namespace std;

void paintBelow()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (!GetConsoleScreenBufferInfo(hc, &csbi))
        return;

    COORD pos = csbi.dwCursorPosition;
    DWORD cells = (csbi.dwSize.Y - pos.Y) * csbi.dwSize.X - pos.X;
    DWORD written;

    FillConsoleOutputAttribute(hc, 0xf0, cells, pos, &written);
}

int readInt(const string& prompt)
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    int value;

    while (true)
    {
        paintBelow();
        cout << prompt;

        if (cin >> value)
        {
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            return value;
        }

        if (cin.eof())
            exit(EXIT_SUCCESS);

        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');

        SetConsoleTextAttribute(hc, 0xf4);
        cout << "\nInvalid input! Please enter an integer.\n\n";
        SetConsoleTextAttribute(hc, 0xf0);
    }
}