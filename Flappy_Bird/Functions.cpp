#include "Functions.h"
#include <iostream>
#include <windows.h>
#include <string.h>
#include <string>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <istream>
#include <fstream>
#include <chrono>
#include "Data.h"
#include "Bird.h"
#include "flip_pipe.h"
#include "Pipe.h"
#include "Timer.h"
#include "User.h"
User* user1;
void inline coordonate(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(hConsole, CursorPosition);
}
void inline SetColor(int color_code)
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

void login_meniu()
{
    user1 = new User();
    int optiune;
    while (1)
    {
        coordonate(0, 0);  std::cout << "                                                                    ";
        coordonate(0, 1);  std::cout << "                                                                    ";
        coordonate(0, 2);  std::cout << "                                                                    ";
        SetColor(3);
        for (int i = 0; i < 78; i++)
        {
            coordonate(i, 3);  std::cout << "\xDC";
        }
       // coordonate(70, 3);  std::cout << "         ";

        coordonate(0, 4);  std::cout << "\xDB                                 Flappy Bird                                \xDB";
       // coordonate(70, 4); std::cout << "        ";

        for (int i = 0; i < 78; i++)
        {
            if (i == 0 || i == 77) {

                coordonate(i, 5); std::cout << "\xDB";
            }
            else {
                coordonate(i, 5); std::cout << "\xDC";
            }
        }
        //coordonate(70, 5);  std::cout << "         ";
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

        coordonate(0, 21); std::cout << "                                                                      ";
        coordonate(0, 22); std::cout << "                                                                      ";
        for (int i = 0; i < 78; i++)
        {
            if (i == 0 || i == 77) {

                coordonate(i, 20); std::cout << "\xDB";
            }
            else {
                coordonate(i, 20); std::cout << "\xDC";
            }
            //coordonate(70, 20); std::cout << "         ";
        }
        SetColor(15);
        coordonate(33, 10); std::cout << "1 Register ";
        coordonate(34, 11); std::cout << "2 Log in ";
        coordonate(31, 12); std::cout << "3 Play as guest ";
        coordonate(35, 13); std::cout << "4 Exit ";
        coordonate(31, 14); std::cout << "Alege o optiune: ";
        if (!(std::cin >> optiune)) {
            SetColor(4);
            coordonate(27, 15); std::cout << "Optiune invalida";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            coordonate(21, 16); system("PAUSE");
            SetColor(15);
            continue;
        }
        switch (optiune)
        {
        case 1:
            //create_user();
            user1->m_register_user();
            coordonate(10, 15);
            system("PAUSE");
            break;
        case 2:
            //user1->m_set_score(0);
           // user1->m_get_user_name().clear();
            //user1->m_get_password().clear();

            if (user1->m_login_user())
            {
                coordonate(10, 15);
                coordonate(0, 45); std::cout << "main";
                user_name = user1->m_get_user_name();
                password = user1->m_get_password();
                highest_score = user1->m_get_score();
                guest = 0;
                Flappy_Bird();
            }
            else
            {
                chenar();
                SetColor(4);
                coordonate(10, 15); std::cout << " LOGIN ERROR Please check your username and password\n";
                coordonate(10, 16);
                system("PAUSE");
                SetColor(15);
            }
            break;
        case 3:
            guest = 1;
            Flappy_Bird();
            break;
        case 4:
            coordonate(0, 30);
            exit(0);
        default:
            SetColor(4);
            coordonate(27, 15); std::cout << "Optiune invalida";
            coordonate(21, 16); system("PAUSE");
            SetColor(15);

        }
    }
}

void instructions()
{
    chenar();
    coordonate(18, 10); std::cout << "Press SPACE to make the bird jump 1 space.";
    coordonate(15, 11); std::cout << "You must make the bird pass between the 2 pipes.";
    coordonate(7, 12); std::cout << "If the bird falls on the ground or hit the pipes the game is over.";
    coordonate(24, 13); system("PAUSE");
}
void Flappy_Bird()
{
    int optiune;
    int ok = 1;
    while (ok)
    {
        coordonate(0, 0);  std::cout << "                                                                    ";
        coordonate(0, 1);  std::cout << "                                                                    ";
        coordonate(0, 2);  std::cout << "                                                                    ";
        SetColor(3);
        for (int i = 0; i < 78; i++)
        {
            coordonate(i, 3);  std::cout << "\xDC";
        }


        coordonate(0, 4);  std::cout << "\xDB                                 Flappy Bird                                \xDB";


        for (int i = 0; i < 78; i++)
        {
            if (i == 0 || i == 77) {

                coordonate(i, 5); std::cout << "\xDB";
            }
            else {
                coordonate(i, 5); std::cout << "\xDC";
            }
        }
       
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

        coordonate(0, 21); std::cout << "                                                                              ";
        coordonate(0, 22); std::cout << "                                                                              ";
        for (int i = 0; i < 78; i++)
        {
            if (i == 0 || i == 77) {

                coordonate(i, 20); std::cout << "\xDB";
            }
            else {
                coordonate(i, 20); std::cout << "\xDC";
            }
        }
        SetColor(15);
        if (!guest) 
        {
            coordonate(39-((int)(user_name.length()+7) / 2), 10); std::cout << "Hello, " << user_name << "!";
            coordonate(30, 11); std::cout << "Welcome to the game!";
        }
        else
        {
            coordonate(31, 10); std::cout << "Hello, dear Guest!";
            coordonate(30, 11); std::cout << "Welcome to the game!";
                

        }
        coordonate(37, 12); std::cout << "1 Play";
        coordonate(33, 13); std::cout << "2 Instructions";
        coordonate(35, 14); std::cout << "3 Log out";
        coordonate(32, 15); std::cout << "Alege o optiune: ";
    
        if (!(std::cin >> optiune)) {
            SetColor(4);
            coordonate(35, 15); std::cout << "Optiune invalida";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            coordonate(29, 16); system("PAUSE");
            SetColor(15);
            continue;
        }
        switch (optiune) {

        case 1:
            Play();
            highest_score = user1->m_get_score();
            break;
        case 2:
            instructions();
            
            break;
        case 3:
            ok = 0;
            attempts = 0;
            highest_score = 0;
            //delete &user1;
            
            break;
        default:
            SetColor(4);
            coordonate(35, 15); std::cout << "Optiune invalida";
            coordonate(29, 16); system("PAUSE");
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
    
    //top side of the window
    for (int i = 0; i < 78; i++)
    {
        coordonate(i, 3);  std::cout << "\xDC";
    }
    //
    /*
    * int height=15;
    * int width=78;
    * 
    for (int i = 4;i <= width ; i++)
    {
        for (int j = 0; j <= height; j++)
        {
            if (j == 0||j==width)
            {
                coordonate(0 + j, i); std::cout << "\xDB";
            }
            else
            {
                coordonate(0+j, i); std::cout << " ";
            }

        }
    }
    */
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
    
void Play() 
{
    chenar();//creation of edges for the window of the game in console

    //display start screen and initiall conditions
    score = 0;
    attempts++;
    move_count = 0;
    pipes = 0;
    down_pipes[pipes] = new Pipe();
    up_pipes[pipes] = new flip_pipe(down_pipes[pipes]->m_get_head());

    //initial creation of the bird for the beginning of the game
    Bird* bird = new Bird();
    

    //creating 2 timer objects to count the time elapsed
    Timer bird_time;
    Timer pipe_time;


    while(!_kbhit())
    {
         coordonate(20, 21); std::cout << "Press any key to start";
    }
    coordonate(0, 21); std::cout << "                                                                    ";

    coordonate(0, 0); std::cout << "Attempt: ";
    coordonate(0, 1); std::cout << "Score: ";
    coordonate(0, 2); std::cout << "Highest score : ";


    while (1) 
    {
        SetColor(15);

        coordonate(9, 0); std::cout << attempts;
        coordonate(7, 1); std::cout << score;
        coordonate(16, 2); std::cout << highest_score;
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
                    score++;

                    
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
        if (move_count == 22)//if the pipes moved 22 spaces we create other pipes at the right side of the window 
        {
            move_count=0;
            pipes++;

            //creating new pipes at the right side of the window and adding the objects to the arrays
            down_pipes[pipes] = new Pipe();
            up_pipes[pipes] = new flip_pipe(down_pipes[pipes]->m_get_head());

            
        }

        ///space key hit
        if (_kbhit()) 
        {
             bird->move_bird(_getch());
             bird_time.reset();
        }

        ///bird collided with the pipes
        if (bird->game_over(down_pipes, up_pipes))
        {
            //delete pipes objects
            for (int i = 0; i < pipes; i++)
            {
                delete down_pipes[i];
                delete up_pipes[i];
                down_pipes[i] = nullptr;
                up_pipes[i] = nullptr;
            }

            //update high score
            if (highest_score < score)
            {
                highest_score = score;
            }
            delete bird;
            //display game over screen
            //save_score();
            SetColor(4);
            coordonate(29, 21); std::cout << "GAME OVER";
            coordonate(20, 22); system("PAUSE");
            break;
        }
        if (bird_time.elapsed() > bird_time_var)
        {
            bird->fall();
            bird_time.reset();
        } 
    }            
}

/*void save_score()
{
    /*std::ifstream input("database.txt");
    while (input >> u >> p)
    {
        if (u == user_name && p == password)

        {
            acces = 1;
            guest = 0;
        }
    }
    input.close();

    std::ofstream reg("scores.txt", std::ios::app);
    reg << user_name << ' ' << score << std::endl;
    reg.close();
}*/

            


