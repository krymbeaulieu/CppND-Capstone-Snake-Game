# CPPND: Capstone Snake Game Example

This is an extension of the starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Features for Capstone
- Lose screen displays high scores from file & lost message
- Score history tracking (user input for name if high score reached that writes to file)
- pause the game (only while game is in session, not on lose screen)


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [SDLTTF](https://github.com/libsdl-org/SDL_ttf) 
  *
## Basic Build Instructions

1. Clone this repo.
2. 
Option 1 (install libs via provided script):
  1. cd to repo
  2. `./install_libs.sh`
Option 2 (install libs seperately in terminal):
  1. Install SDL ttf library: `sudo apt-get install libsdl2-ttf-dev`
    * `y` to continue install
  2. Install SDL Image library: `sudo apt-get install libsdl2-image-dev`
    * `y` to continue install
3. Make a build directory in the top level repo directory: `mkdir build && cd build`
4. Compile: `cmake .. && make`
5. Run it: `./SnakeGame`.

## Core Classes
The core classes remain the controller, game, renderer trio. The classes added are supplemental to the main architecure of the game loop.
Classes can be explored via a generated documentation in html via doxygen. Open documentation/html/index.html in your browser of choice (firefox was tested in the workspace) to get the project's class documentation. 

### New Items From Base Snake Game
* defs - header that stores the games consts (text, max values, colors, etc.)
* high scores class
  * supports the Game class in the controller/update game/render game loop
  * stores high scores
  * writes new scores to file
  * loads history (top 10) of scores to the game
* Text class
  * supports the renderer class 
  * stores info about text and what the renderer needs to generate it on the fly (ex. font, color, surface, texture)
  * multiple class instantiations available depending on if it has access to the renderer (rendering text on the pause screen vs. what needs input to rerender on screen which may not directly interface with the renderer)
* Controller was updated to do text input for the high score setting & pause menu functionality
* headers are now in headers/ to keep the src folder .cpp files less cluttered

## expected behavior
* Run the game with `./SnakeGame'
* play until your snake head collides with the sname body
  * If you have no previous high scores, a new high score will be set. Put in your 3 initials and press enter. Current version of the game will close once you set your score
  * If you have previous high sores, the high scores will loaded from file and shown on the lose screen. If your score is within the top 10, it will set a new high score and you can put in your 3 initials. Current version of the game will close once you set your high score.
  * if your high score board is full and you do NOT match or beat the bottom (least) score, your lose screen will just load the score file and display it.
  * If you get tired and want to take a break, you can pause your game by pressing the escape button. Note this won't pause on the lose screen, you've already lost.
  
### Expected output
* assets/ holds the Scores.txt that the game renders and adds the new high scores to. Feel free to delete it to reset the scores. It is on the honor system that the scores are not altered via the text file.
  
## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

### Other Code Credits
[CDL Tutorials]: https://www.parallelrealities.co.uk/tutorials

## Rubric Criteria Met
### README (All Rubric Points REQUIRED)
| CRITERIA                                                           | MEETS SPECIFICATIONS                                                                                                                                                                                                                                                         | CURRENTLY MET | LINE NUMBER(S) |
|--------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------|----------------|
| A README with instructions is included with the project            | The README is included with the project and has instructions for building/running the project. If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions. You can submit your writeup as markdown or pdf. |       ✔️       | README         |
| The README indicates which project is chosen.                      | The README describes the project you have built. The README also indicates the file and class structure, along with the expected behavior or output of the program.                                                                                                          |    ✔️           | README         |
| The README includes information about each rubric point addressed. | The README indicates which rubric points are addressed. The README also indicates where in the code (i.e. files and line numbers) that the rubric points are addressed.                                                                                                      |       ✔️        | README         |
### Compiling and Testing (All Rubric Points REQUIRED)
| CRITERIA                             | MEETS SPECIFICATIONS                                                                                                                                                                                                    | CURRENTLY MET | LINE NUMBER(S) |
|--------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------|----------------|
| The submission must compile and run. | The project code must compile and run without errors. We strongly recommend using cmake and make, as provided in the starter repos. If you choose another build system, the code must compile on any reviewer platform. |       ✔️       |      N/A - whole code base compiles          |
### Loops, Functions, I/O
| CRITERIA                                                                                       | MEETS SPECIFICATIONS                                                                                                     | CURRENTLY MET | LINE NUMBER(S) |
|------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------|---------------|----------------|
| The project demonstrates an understanding of C++ functions and control structures.             | A variety of control structures are used in the project. The project code is clearly organized into functions.           |    ✔️           |       game.cpp (39-50),

 text.cpp (ALL), renderer.cpp (97-182), highscores.cpp (ALL)|
| The project reads data from a file and process the data, or the program writes data to a file. | The project reads data from an external file or writes data to a file as part of the necessary operation of the program. |      ✔️         |       highscores.cpp (22-47 load, 96-105 write)         |
| The project accepts user input and processes the input.                                        | The project accepts input from a user as part of the necessary operation of the program.                                 |        ✔️       |       controller.cpp (122-135 typing, 102-110 backpace)         |
### Object Oriented Programming
| CRITERIA                                                                         | MEETS SPECIFICATIONS                                                                                                                                                                         | CURRENTLY MET | LINE NUMBER(S) |
|----------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------|----------------|
| The project uses Object Oriented Programming techniques.                         | The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.                                                                       |        ✔️       |      text.cpp (all), highscores.cpp(all), renderer(97-197 added rendering functionality)          |
| Classes use appropriate access specifiers for class members.                     | All class data members are explicitly specified as public, protected, or private.                                                                                                            |      ✔️         |     text.h, highscores.h,  game.h (29, 30 added member vars), renderer.h (19-24 added funcs)          |
| Class constructors utilize member initialization lists.                          | All class members that are set to argument values are initialized through member initialization lists.                                                                                       |               |                |
| Classes abstract implementation details from their interfaces.                   | All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.      |         ✔️      |      doxygen generated (documentation/), getters/setters for private variables as needed (text.h, highscores.h)          |
| Classes encapsulate behavior.                                                    | Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.                        |         ✔️      |       highscores.h, text.h         |
| Classes follow an appropriate inheritance hierarchy.                             | Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified. |               |                |
| Overloaded functions allow the same function to operate on different parameters. | One function is overloaded with different signatures for the same function name.                                                                                                             |       ✔️        |    text.h (11,12) implementation in text.cpp (12-27)            |
| Derived class functions override virtual base class functions.                   | One member function in an inherited class overrides a virtual base class member function.                                                                                                    |               |                |
| Templates generalize functions in the project.                                   | One function is declared with a template that allows it to accept a generic parameter.                                                                                                       |               |                |
### Memory Management
| CRITERIA                                                                                  | MEETS SPECIFICATIONS                                                                                                                                                                                                                     | CURRENTLY MET | LINE NUMBER(S) |
|-------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------|----------------|
| The project makes use of references in function declarations.                             | At least two variables are defined as references, or two functions use pass-by-reference in the project code.                                                                                                                            |      ✔️         |       text.h (36-37 vars, 11-14 funcs)         |
| The project uses destructors appropriately.                                               | At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor.                                                     |               |                |
| The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. | The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction. |               |                |
| The project follows the Rule of 5.                                                        | For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor are defined, then all of these functions are defined.                                          |               |                |
| The project uses move semantics to move data, instead of copying it, where possible.      | For classes with move constructors, the project returns objects of that class by value, and relies on the move constructor, instead of copying the object.                                                                               |               |                |
| The project uses smart pointers instead of raw pointers.                                  | The project uses at least one smart pointer: unique_ptr, shared_ptr, or weak_ptr. The project does not use raw pointers.                                                                                                                 |               |                |
### Concurrency
| CRITERIA                                     | MEETS SPECIFICATIONS                                                                                                                            | CURRENTLY MET | LINE NUMBER(S) |
|----------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|---------------|----------------|
| The project uses multithreading.             | The project uses multiple threads in the execution.                                                                                             |               |                |
| A promise and future is used in the project. | A promise and future is used to pass data from a worker thread to a parent thread in the project code.                                          |               |                |
| A mutex or lock is used in the project.      | A mutex or lock (e.g. std::lock_guard or `std::unique_lock) is used to protect data that is shared across multiple threads in the project code. |               |                |
| A condition variable is used in the project. | A std::condition_variable is used in the project code to synchronize thread execution.                                                          |               |                |
