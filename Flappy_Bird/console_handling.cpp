#include "console_handling.h"

void console_handling::coordonate(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(hConsole, CursorPosition);
}

void console_handling::SetColor(int color_code)
{
    WORD wColor;

    //We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        //Mask out all but the background attribute, and add in the foreground color
        wColor = (csbi.wAttributes & 0xF0) + (color_code & 0x0F);
        SetConsoleTextAttribute(hConsole, wColor);
    }
}

void console_handling::chenar()
{
    system("CLS");
    ShowConsoleCursor(false);
    SetColor(3);

    //top side of the window
    for (int i = 0; i < 78; i++)
    {
        coordonate(i, 3);  std::cout << "\xDC";
    }

    coordonate(0, 4);  std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 5);  std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 6);  std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 7);  std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 8);  std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 9);  std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 10); std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 11); std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 12); std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 13); std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 14); std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 15); std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 16); std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 17); std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 18); std::cout << "\xDB                                                                            \xDB";
    coordonate(0, 19); std::cout << "\xDB                                                                            \xDB";

    //bottom side of the window
    for (int i = 0; i < 78; i++)
    {
        if (i == 0 || i == 77) {

            coordonate(i, 20); std::cout << "\xDB";
        }
        else {
            coordonate(i, 20); std::cout << "\xDC";
        }
    }
}

void console_handling::ShowConsoleCursor(bool showFlag)
{
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
