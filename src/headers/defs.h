#include <string>
#include <SDL2/SDL.h>
#include <vector>

// global game vars
constexpr uint8_t MAX_HIGH_SCORES = 10;
const std::string FONT_FNAME = strcat(SDL_GetBasePath(),"../assets/FreeSans.ttf");

// game pause
const std::string GAME_PAUSE_TEXT = "Game Paused";
const SDL_Color GAME_PAUSE_COLOR={37, 207, 57, 255}; // red
constexpr int GAME_PAUSE_FONT_SIZE = 80;
// game lose
const std::string GAME_LOSE_TEXT = "You Lost!";
const SDL_Color GAME_LOSE_COLOR={255, 0, 0, 255}; // red 
constexpr int GAME_LOSE_FONT_SIZE = 40;
// game high score
const std::string SCORE_FNAME = strcat(SDL_GetBasePath(),"../assets/Scores.txt");
const std::string GAME_HIGH_SCORE_TEXT = "You made a high score!";
const SDL_Color GAME_HIGH_SCORE_COLOR={37, 207, 57, 255}; // green


const std::string GAME_HIGH_SCORE_ENTER_NAME_TEXT = "Enter Initials (press enter when done):";
const SDL_Color GAME_HIGH_SCORE_ENTER_NAME_COLOR={244,189,49, 255}; // gold
constexpr int GAME_HIGH_SCORE_ENTER_NAME_FONT_SIZE = 20;

constexpr int GAME_HIGH_SCORE_HEADER_FONT_SIZE = 30;
const SDL_Color GAME_HIGH_SCORE_TABLE_HEADER_COLOR={0,244,123,255}; // light green
const SDL_Color GAME_HIGH_SCORE_TABLE_ENTRY_COLOR={221,221,221,225}; // grey
constexpr int GAME_HIGH_SCORE_TABLE_ENTRY_FONT_SIZE = 20;

constexpr uint8_t MAX_NAME_LENGTH = 3; // like old school high score tags
// game high score file writing
const std::string SCORE_HEADERS = "RANK NAME SCORE";
