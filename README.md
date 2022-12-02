# Flappy_Bird
Hello! My name is Victor and this is my first project uploaded on github.
It's not much because this is my first project in c++, one in which i learned a lot
but i tried to make it a full functional application even if it is just a flappy bird in console.

The customization of the console like colorized characters and a few other things are implemented
in the console_handling class. This class is inherited by my other classes that need to display 
something or are manipulating the objects from the console.

My main class is flappy_bird which has the meniu functionalities of the app as well as the Play 
method which is in fact the actuall game. In this Play method the bird and pipes objects are created
and manipulated by their specific methods like "move_bird" , "m_move_down_pipe" or "m_move_flip_pipe".
The pipes move after a certain set time but the bird only moves up if the player presses the SPACE key
and falls if the player press anything but the SPACE or doesn't press anything. However if the TAB key is pressed the game will pause untill another key(any) is pressed.

The movements of the objects on the display is realized by printing characters in a pozition updated
from the last position of them then the row or the column from where the object moved is filled with blank spaces. For example each pipe moves one space from the right to the left, so by using the "coordonate" function we set the cursor at a position with x postion equal to the pipe position-1 then we print the pipe again according to this new x, then the right part of the previous position of the pipe is erased by printing blank spaces.

This app also has a login option which is implemented in the "user" class. It has many functionalities like "register" which registers a new user but it checks if there is another user with the same username to avoid dublicates ...teh password field is hided but the password can be dislayed if the SPACE key is press and hided again if the same key is pressed again.
The users are stored in a binary file to use less space and to be faster on read and write operations.It isn't the best way of doing it (i mean to store usernames and passwords in a file) but for the moment and for this app i think it is good enough.