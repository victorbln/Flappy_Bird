#include "Functions.h"
#include <iostream>
#include <windows.h>
#include "Data.h"
#include "Bird.h"
#include <thread>
#include <vector>
#include "flip_pipe.h"
#include<conio.h>
#include<dos.h>
#include <chrono>
#include<stdlib.h>
#include<string.h>
#include "Pipe.h"
#include "Timer.h"
void coordonate(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(hConsole, CursorPosition);
}
void SetColor(int color_code)
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

void Flappy_Bird()
{
    int optiune;
    while (1)
    {
        SetColor(3);
        coordonate(0, 3);  std::cout << "----------------------------------------------------------------------";
        coordonate(0, 4);  std::cout << "|                             Flappy Bird                            |";
        coordonate(0, 5);  std::cout << "----------------------------------------------------------------------";
        coordonate(0, 6);  std::cout << "|                                                                    |";
        coordonate(0, 7);  std::cout << "|                                                                    |";
        coordonate(0, 8);  std::cout << "|                                                                    |";
        coordonate(0, 9);  std::cout << "|                                                                    |";
        coordonate(0, 10); std::cout << "|                                                                    |";
        coordonate(0, 11); std::cout << "|                                                                    |";
        coordonate(0, 12); std::cout << "|                                                                    |";
        coordonate(0, 13); std::cout << "|                                                                    |";
        coordonate(0, 14); std::cout << "|                                                                    |";
        coordonate(0, 15); std::cout << "|                                                                    |";
        coordonate(0, 16); std::cout << "|                                                                    |";
        coordonate(0, 17); std::cout << "|                                                                    |";
        coordonate(0, 18); std::cout << "|                                                                    |";
        coordonate(0, 19); std::cout << "|                                                                    |";
        coordonate(0, 20); std::cout << "----------------------------------------------------------------------";
        SetColor(15);
        coordonate(31, 12); std::cout << "1 Start ";
        coordonate(32, 13); std::cout << "2 Exit";
        coordonate(32, 14); std::cout << "3 Scor";
        coordonate(28, 15); std::cout << "Alege o optiune: ";
        if (!(std::cin >> optiune)) {
            SetColor(4);
            coordonate(27, 15); std::cout << "Optiune invalida";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            coordonate(21, 16); system("PAUSE");
            SetColor(15);
            continue;
        }
        switch (optiune) {
        case 1:
            Play();
            //delete[]bird;
            break;
        case 2:exit(0);
        //case 3:
            //scor();
        default:
            SetColor(4);
            coordonate(27, 15); std::cout << "Optiune invalida";
            coordonate(21, 16); system("PAUSE");
            SetColor(15);
        }

    }



}
void ShowConsoleCursor(bool showFlag)
{
    

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
void chenar() {
    ShowConsoleCursor(false);
    SetColor(3);
    for (int i = 0; i < 70; i++) 
    {
    coordonate(i, 3);  std::cout << "\xDC";
    }
    coordonate(0, 4);  std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 5);  std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 6);  std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 7);  std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 8);  std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 9);  std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 10); std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 11); std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 12); std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 13); std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 14); std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 15); std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 16); std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 17); std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 18); std::cout << "\xDB                                                                    \xDB";
    coordonate(0, 19); std::cout << "\xDB                                                                    \xDB";
    for (int i = 0; i < 70; i++) 
    {
        if (i == 0 || i == 69) {

    coordonate(i, 20); std::cout << "\xDB";
        }
        else {
            coordonate(i, 20); std::cout << "\xDC";
        }
    }
}
void Play() 
{
    chenar();
    down_pipes.insert(down_pipes.begin(), Pipe());
        //.emplace_back(Pipe());
    up_pipes.insert(up_pipes.begin(), flip_pipe());
        //.emplace_back(flip_pipe());
    up_pipes[0].create(down_pipes[0].get_n());

    Bird* bird = new Bird();
    SetColor(15);
    
    int ok = 0;
    Timer bird_time;
    Timer pipe_time;
    coordonate(20, 21); std::cout << "Press any key to start";
    while (1) 
    {
        while(!_kbhit()&&!ok)
        {
            coordonate(20, 21); std::cout << "Press any key to start";
        }
        coordonate(0, 21); std::cout << "                                                                    ";
        ok = 1;
        if (pipe_time.elapsed()>var_time)
        {
            for (int i =0; i <=pipes; i++)// (int i = 0; i < pipes + 1; i++)
            {
                
                if (down_pipes[i].move_pipe()) 
                {
                    //pipe_it = down_pipes.back();
                    //down_pipes.erase(pipe_it);
                    down_pipes.pop_back();
                }
                if (up_pipes[i].flip_pipe_move())
                {
                    up_pipes.pop_back();
                    //flip_pipe_it = up_pipes.end();
                    //up_pipes.erase(flip_pipe_it);
                }
                
            }
            move_count++;
            pipe_time.reset();
        }
        if (move_count == 14) 
        {
            move_count=0;
            pipes++;
            down_pipes.emplace_back(Pipe());
            up_pipes.emplace_back(flip_pipe());
            up_pipes[pipes].create(down_pipes[pipes].get_n());
            
        }
        //bird->game_over()
        if (_kbhit()) 
        {
             bird->move_bird(_getch());
             bird->update_pos();
             bird_time.reset();
        }
        if (bird_time.elapsed() > var_time)
        {
             if (bird->fall()) 
             {
                 chenar();
                 SetColor(4);
                 coordonate(29, 10); std::cout << "GAME OVER";
                 coordonate(25, 11); system("PAUSE");
                 break;
             }
             else 
             {
                 bird_time.reset();
             }
        }

        
    }
               
}

            


