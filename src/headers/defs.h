
#include <string>
#include <SDL2/SDL.h>

// global game vars
constexpr uint8_t MAX_HIGH_SCORES = 10;
const std::string FONT_FNAME = strcat(SDL_GetBasePath(),"../assets/FreeSans.ttf");

// game pause
const std::string GAME_PAUSE_TEXT = "Game Paused";
const SDL_Color GAME_PAUSE_COLOR = {37, 207, 57, 255};
constexpr int GAME_PAUSE_FONT_SIZE = 80;
// game lose
const std::string GAME_LOSE_TEXT = "You Lost!";
const SDL_Color GAME_LOSE_COLOR = {255, 0, 0, 255};
constexpr int GAME_LOSE_FONT_SIZE = 40;
// game high score
const std::string SCORE_FILE = strcat(SDL_GetBasePath(),"../assets/Scores.txt");
const std::string GAME_HIGH_SCORE_TEXT = "You made a high score!";
const std::string GAME_ENTER_HIGH_SCORE_NAME = "Enter name:";
