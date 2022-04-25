

# SpaceInvaders _Documentation_ 

##Contents

---

- Introduction
- How-to-guide
    - Dependencies
    - GamePlay
- Software Summary
    - Classes



---
##Introduction
This game is a c++ implementation of the classic scrolling shooter, made as an exam in the subject c++ (PG4400) at Høyskolen Kristiania. The task was to make a scrolling shooter and implement some design templates free of choice. I started out with a singletons and inheritance in the design. And ended up using that throughout the project. If i were to restart the project I would have chosen to go for a more component design solution and probably tried to minimize the use of singletons. Even though i believe my implementation should be thread safe and make it impossible to create more than one instance of the class. 

The game has 3 levels. Where the speed of the enemies increase when you level up, the color of the background change. The player has 5 lives and the game ends if u get hit 5 times by either enemies bullts or by crashing into enemies. You get one point by killing an enemy. Upon leaving the game or losing the highscores will be read into and array and sorted by highest number. The top 10  is then  saved in the hs.csv file. If i had more time left after implementing the highscore savedata i would have made a hash function so that the highscores were safer for manipulation by players. But as its just a single player game I decided to focus my efforts elsewhere. 


---

## How-to-guide
  ### Dependencies
    The game needs SDL, SDL_Image, SDL_Mixer and SDL2_ttf to compile correctly.
    I've used c++ 20 as compile standard while writing and compiling the game. 
    

  ### installing SDL
  ### MacOS
On Mac the easiest way to get SDL to work is to download homebrew. this is done through bash and the easiest way is to use the script:

    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

Then you are able to install SDL through the command 

    brew -install sdl2 sdl2_image sdl2_ttf sdl2_mixer

### Windows
For Windows the easiest way to install SDL is by using a packagemanager like MYSYS2
Here is an excellent guide on installing msys and sdl2
https://gist.github.com/thales17/fb2e4cff60890a51d9dddd4c6e832ad2
There's currently a bug when using msys, and you would have to run another command from cmd.
go into the folder where msys toolchain is located. then go into the folder where u have msys installed and into the correct toolchain. from there you have to navigate into the subfolder "x86_64-w64-mingw32" from there write:

    "mklink /D .\include ..\include"

you then have to add msys2 to you preferred toolchain/editor. 


## Software Summary
### Classes overview
- Main
  - Game
  - GameObject
    - Player
    - Enemy
    - HealthBar
    - Projectile
    - TextObject
    - UI_Element
  - InputHandler
  - GameStateMachine
  - GameState
    - PlayingState
    - MenuState
    - HighscoreState
  - ObjectParamLoader
  - Randomizer
  - SoundLoader
  - TextureManager
  - Vector2D
  - FileReader


#### Game

  The Game is where the magic happens. In this class we manage all the rendering and running loops as well as initial setup of the program. The class also holds pointers to the window, renderer, player and gamestatemachine. This makes the access easier from other places in the code. I've decided to use a singleton of the Game so that we can access the game without passing objects around in the code. It saves some code, and most of the game-designs I've found uses singletons, so I decided to ignore some of the warnings I read. I tried my best to make the objects thread safe. 
  
  The game instance also keeps a vector with all the game-objects we are going to render in the program. There are also functions for deleting inactive || dead objects. Which I realized a bit late that could have been done better. Since I am doing too many resource heavy operations by deleting and creating objects. I figured a popular way to get around the heavy lifting of creating and deleting objects were to create a pool of objects at runtime and just reset them as needed. This could have resulted in better performance. 

#### GameObjects

  The Gameobjects keeps their draw and updatefunctions as needed and are all inhereted from Gameobject class. Theres modifications to the methods where needed. This way, by using Inheritance I was able to create one array with all the objects in the game. And therefore i was able to create simple rendering loop and updaters.

#### Inputhandler

  The inputhandler returns diffrent values from a set enum - this depends on what buttons the inputhandler is reading out thats pressed.
  I chose to use a switch case here so that the handling of the events and using the Inputhandler would be easier. The bad part about using a switch case is that there is no key rollover. But it makes the class easier and better to reuse as an module. So I decided that the no rollover issue was superseded by the positives.

#### GameStateMachine
  The GameStateMachine class keeps funcitons for adding and swapping between the different Gamestates. Runs the Gamestate onExit for cleanups when swapping state and the GameState-> onenter when entering a new state. This way I am able to change states on the fly. And therefore implement menu in an easy way. With a statemachine it is also easier to implement and expand the game when wanted. Like if i were to add a game over screen, I could simply implement it so that the GameOver state was pushed whenever the player lives went to zero. Right now the behavior is to return to the menuScreen. If i were to implement a game over screen at a later point it would be a nice addition to see whether or not the player has beaten the highscore. ~~~~
 
#### GameState
  The GameState class is pure virtual and creates an inteface for the states the game can be in.
  - PlayingState
    - Has funtions that define the gameplay. On initialization it creates the gameObjects and a default enemy. The updatescore updates a scorecounter on enemy kill and increments the level when a level is beaten. 
  - MenuState
    - Has an enum to select which menuItem thats selected. And functions to launch the correct state corresponding to the selection. 
  - HighscoreState
    - Creates a txt list with the 10 best scores achieved. It uses the FileReader class to read out the topscores saved in a csv file.
      
#### ObjectParamLoader 

  helper-class for loading params into gameobjects.

#### Randomizer
  Helper-class to generate random numbers for spawning enemies.

#### Soundloader
  Singleton that loads sound files and plays sounds. also stores a map of the soundfiles. 

#### TextureManager

  Singleton that loads, stores, and draws textures. storage and access to textures is done by a map. Textures are initialized as smart pointers with custom deleters which call SDL_destroytexture on exit. I have mostly integrated smart pointers where usable.
  
#### Vector2d
  
  2d vector for saving positions and sizes. This class is heavily inspired from the book SDL Game Development by Shaun Mitchell
  
#### FileReader
  
  the file-reader class has two methods. One for simply reading out the text file of highscores and one where it takes a score as an input, reads in the scores and sort them. then the class writes the first 10 items of the sorted list to the hs.csv file. This way the new score will be written at the correct posisiton if the score is in the top 10.
