#include "Flappy_bird.h"

void flappy_bird::login_meniu()
{
    int Quit=0;
    user1 = new User();
    user1->m_set_login_string_dimensions(6, 10, 8, 24);
    int optiune;
    while (1)
    {
        system("CLS");
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
            user1->m_register_user();
            coordonate(10, 15);
            system("PAUSE");
            break;
        case 2:
            Quit = user1->m_login_user();

            if (Quit==0)
            {
                coordonate(10, 15);
                user_name = user1->m_get_user_name();
                highest_score = user1->m_get_score();
                guest = 0;
                Flappy_Bird();
            }
            else if (Quit == -1)
            {
                break;
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
void flappy_bird::instructions()
{
    chenar();
    coordonate(18, 10); std::cout << "Press SPACE to make the bird jump 1 space.";
    coordonate(15, 11); std::cout << "You must make the bird pass between the 2 pipes.";
    coordonate(17, 12); std::cout << "If the bird hit the pipes the game is over.";
    coordonate(24, 13); system("PAUSE");
}
void flappy_bird::Flappy_Bird()
{
    int optiune;
    int ok = 1;
    while (ok)
    {
        system("CLS");
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
            break;

        case 2:
            instructions();
            break;

        case 3:
            if (!guest)
            {
                user1->save_info();
            }
            ok = 0;
            attempts = 0;
            highest_score = 0;
            break;

        default:
            SetColor(4);
            coordonate(35, 15); std::cout << "Optiune invalida";
            coordonate(29, 16); system("PAUSE");
            SetColor(15);
        }

    }



}  
void flappy_bird::Play()
{
    chenar();//creation of edges for the window of the game in console
    int QUIT_GAME = 0;
    //display start screen and initial conditions
    score = 0;
    attempts++;
    move_count = 0;
    pipes = 0;
    //creating 2 pipes
    down_pipes[pipes] = new Pipe();
    up_pipes[pipes] = new flip_pipe(down_pipes[pipes]->m_get_head());

    //initial creation of the bird for the beginning of the game
    Bird* bird = new Bird();
    

    //creating 2 timer objects to count the time elapsed
    Timer bird_time;//for bird
    Timer pipe_time;//for pipes


    while(!_kbhit())
    {
         coordonate(20, 21); std::cout << "Press any key to start";//waiting till the player hit a key
    }
    coordonate(0, 21); std::cout << "                                                                    ";

    coordonate(0, 0); std::cout << "Attempt: ";
    coordonate(0, 1); std::cout << "Score: ";
    coordonate(0, 2); std::cout << "Highest score : ";
    coordonate(60, 0); std::cout << "Press ESC to quit";
    coordonate(60, 1); std::cout << "Press TAB to pause";
    coordonate(60, 2); std::cout << "Press SPACE to jump";
   // coordonate()

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
                // calling the m_move_down_pipe and m_move_flip_pipe methods to move the pipes
                if (down_pipes[i]->m_move_down_pipe() || up_pipes[i]->m_move_flip_pipe())
                {
                    up_pipes[i]->m_move_flip_pipe();//we call this method once more because if the down pipes is at the edge..it returns 1 and the call from the if statement wont operate
                    //if the pipes are at the left edge of the window the methods
                    //will delete the visual pipes but now we delete the objects from memmory
                    delete down_pipes[i];
                    delete up_pipes[i];
                    //shifting left the arrays of pipes
                    for (int j = 0; j <= pipes; j++)
                    {
                        down_pipes[j] = down_pipes[j + 1];
                        up_pipes[j] = up_pipes[j + 1];
                    }
                    pipes--;//decrement the pipes count variable
                    i--;
                    score++;
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
            QUIT_GAME = bird->move_bird(_getch());
            if (QUIT_GAME==1)
            {
                //QUIT
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
                    user1->m_set_score(score);
                }
                delete bird;
                //display game over screen
                SetColor(4);
                coordonate(29, 21); std::cout << "QUIT GAME";
                coordonate(20, 22); system("PAUSE");
                break;
            }
            else if (QUIT_GAME == 0)
            {
                //JUST JUMP
                bird_time.reset();
            }
            else if (QUIT_GAME == 2)
            {
                //PAUSE
                coordonate(29, 21); std::cout << "PAUSE";
                coordonate(20, 22); std::cout << "Press any key to continue";
                _getch();
                coordonate(29, 21); std::cout << "                                  ";
                coordonate(20, 22); std::cout << "                                  ";
            }
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
                user1->m_set_score(score);
            }
            delete bird;
            //display game over screen
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
  


