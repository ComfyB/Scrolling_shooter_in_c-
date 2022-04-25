

# SpaceInvaders _Documentation_ 

##Contents

---

- Introduction
- How-to-guide
    - Dependencies
    - GamePlay
- Software Summary
    - Classes
    - Constants
- Technical Information



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
  ###mac
On mac the easiest way to get SDL to work is to download homebrew. this is done through bash and the easiest way is to use the script:

/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"


## Software Summary
### Classes
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
### Constants 
- dkdkkdd