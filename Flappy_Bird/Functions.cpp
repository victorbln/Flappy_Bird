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
        coordonate(0, 21); std::cout << "                                                                      ";
        coordonate(0, 22); std::cout << "                                                                      ";
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
        case 2:
            coordonate(0,30);
            exit(0);
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
    chenar();//creation of endges for the window of the game in console

    //initial creation of 2 pipes for the beginning of the game
    pipes = 0;
    down_pipes[pipes] = new Pipe();
    up_pipes[pipes] = new flip_pipe(down_pipes[pipes]->m_get_head());
    //flip_pipes[pipes]->create(down_pipes_ptr[0]->get_n());

    //initial creation of the bird for the beginning of the game
    Bird* bird = new Bird();
    

    //creating 2 timer objects to count the time elapsed
    Timer bird_time;
    Timer pipe_time;
    coordonate(20, 21); std::cout << "Press any key to start";
    while(!_kbhit())//
    {
         coordonate(20, 21); std::cout << "Press any key to start";
    }
    coordonate(0, 21); std::cout << "                                                                    ";
    while (1) 
    {

        if (pipe_time.elapsed()>var_time)//verify the time elapsed from the last move of pipes
        {
            for (int i =0; i <=pipes; i++)
            {
                if (down_pipes[i]->m_move_down_pipe())//calling the m_move_down_pipe method for the down pipes
                {
                    //if the pipe is at the left edge of the window the m_move_down_pipe 
                    //will delete the visual pipe but now we delete the objects from memmory
                    delete down_pipes[i];

                    //shifting left the array of down side pipes
                    for (int i = 0; i <= pipes; i++)
                    {
                        down_pipes[i] = down_pipes[i + 1];
                    }

                    
                }
                if (up_pipes[i]->m_move_flip_pipe())//calling the m_move_flip_pipe method for the up side pipes
                {
                    //will delete the visual pipe but now we delete the objects from memmory
                    //if the pipe is at the left edge of the window the m_move_flip_pipe 
                    delete up_pipes[i];//erasing the object from memmory

                    //shifting left the array of up side pipes
                    for (int i = 0; i <= pipes; i++)
                    {
                        up_pipes[i] = up_pipes[i + 1];
                    }
                    pipes--;//decrement the pipes count variable
                    i--;
                }
               
            }
            move_count++;//counting the moves of the pipes on the screen
            pipe_time.reset();//reset the pipe time because we moved them
        }
        if (move_count == 20)//if the pipes moved 16 spaces we create other pipes at the right side of the window 
        {
            move_count=0;
            pipes++;

            //creating new pipes at the right side of the window and adding the objects to the arrays
            down_pipes[pipes] = new Pipe();
            up_pipes[pipes] = new flip_pipe(down_pipes[pipes]->m_get_head());

            
        }
        if (_kbhit()) 
        {
            
             bird->move_bird(_getch());
             bird_time.reset();
        }
        if (bird->game_over(down_pipes, up_pipes))
        {
            //if the bird hit the pipes
            SetColor(4);
            coordonate(29, 21); std::cout << "GAME OVER";
            coordonate(25, 22); system("PAUSE");
            for (int i = 0; i < pipes; i++)
            {
                delete down_pipes[i];
                delete up_pipes[i];
                down_pipes[i] = nullptr;
                up_pipes[i] = nullptr;
            }
            break;
        }
        if (bird_time.elapsed() > var_time)
        {
             if (bird->fall())//if the time for the bird elapsed it will fall 1 space
             {
                 //if the bird hit the ground we enter in this block of code
                 SetColor(4);
                 coordonate(29, 21); std::cout << "GAME OVER";
                 coordonate(25, 22); system("PAUSE");
                 for (int i = 0; i < pipes; i++)
                 {
                     delete down_pipes[i];
                     delete up_pipes[i];
                     down_pipes[i] = nullptr;
                     up_pipes[i] = nullptr;
                 }
                 break;
             }
             else 
             {
                 //if the bird didn't fell we enter in this block which just resets the timer for it
                 bird_time.reset();
             }
        }

        
    }
               
}



            


