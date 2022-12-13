#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>
#include "headers/defs.h"
#include "headers/renderer.h"
#include "headers/text.h"
#include "headers/highscores.h"

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
  TTF_Init();

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window)
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer)
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer()
{
  SDL_DestroyWindow(sdl_window);
  TTF_Quit();
  SDL_Quit();
}

void Renderer::Render(Snake const snake, SDL_Point const &food)
{
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake.body)
  {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive)
  {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  }
  else
  {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::RenderLoseScreen(HighScores &high_scores, std::string &name_text, bool &name_done)
{
  ClearScreen();

  // You Lose
  Text lose_text(sdl_renderer, FONT_FNAME, GAME_LOSE_FONT_SIZE, GAME_LOSE_TEXT, GAME_LOSE_COLOR);
  SDL_Rect center_loc = lose_text.center_text(screen_height, screen_width);
  RenderText(lose_text, center_loc.x, center_loc.y / 6); // put centered up top
                                                         // Enter High score name
  if (high_scores.set_high_score)
  {
    Text set_hs_text(sdl_renderer, FONT_FNAME, GAME_HIGH_SCORE_HEADER_FONT_SIZE, GAME_HIGH_SCORE_TEXT, GAME_HIGH_SCORE_COLOR);
    center_loc = set_hs_text.center_text(screen_height, screen_width);
    RenderText(set_hs_text, center_loc.x, center_loc.y / 3); // put centered up top

    Text enter_name_text(sdl_renderer, FONT_FNAME, GAME_HIGH_SCORE_ENTER_NAME_FONT_SIZE, GAME_HIGH_SCORE_ENTER_NAME_TEXT, GAME_HIGH_SCORE_ENTER_NAME_COLOR);
    center_loc = enter_name_text.center_text(screen_height, screen_width);
    RenderText(enter_name_text, center_loc.x, (center_loc.y / 3) + set_hs_text.get_text_rect().h); // put centered up top, below the set high score

    if (!name_text.empty())
    {
      //not empty so render
      Text curr_name = Text(sdl_renderer, FONT_FNAME, GAME_HIGH_SCORE_ENTER_NAME_FONT_SIZE, name_text, GAME_HIGH_SCORE_ENTER_NAME_COLOR);
      center_loc = curr_name.center_text(screen_height, screen_width);
      RenderText(curr_name, center_loc.x, (center_loc.y / 3) + set_hs_text.get_text_rect().h + enter_name_text.get_text_rect().h); // below the prompt
    }
  }
  // High scores
  RenderScoreHeaders();
  RenderScores(high_scores, name_done);

  SDL_RenderPresent(sdl_renderer); //puts image on screen
}
void Renderer::RenderScoreHeaders()
{
  SDL_Color c = GAME_HIGH_SCORE_TABLE_HEADER_COLOR;
  Text rank_text(sdl_renderer, FONT_FNAME, GAME_HIGH_SCORE_HEADER_FONT_SIZE, "Rank", c);
  SDL_Rect center_loc = rank_text.center_text(screen_height, screen_width * 2 / 3);
  RenderText(rank_text, center_loc.x / 3, center_loc.y); // be 2/3 down, but 1/3 to the left of half start x

  Text name_text(sdl_renderer, FONT_FNAME, GAME_HIGH_SCORE_HEADER_FONT_SIZE, "Name", c);
  center_loc = name_text.center_text(screen_height, screen_width * 2 / 3);
  RenderText(name_text, center_loc.x, center_loc.y); // be 2/3 down, but half across start x

  Text score_text(sdl_renderer, FONT_FNAME, GAME_HIGH_SCORE_HEADER_FONT_SIZE, "Score", c);
  center_loc = score_text.center_text(screen_height, screen_width * 2 / 3);
  RenderText(score_text, center_loc.x * 5 / 3, center_loc.y); // be 2/3 down, but 1/3 to the right of half start x
}
void Renderer::RenderScores(HighScores &high_scores, bool &name_done)
{
  for (int i = 0; i < high_scores.GetHighScores().size(); i++)
  {
    auto scores = high_scores.GetHighScores();
    auto names = high_scores.GetHighScoreNames();
    // set up rank
    Text rank_text(sdl_renderer, FONT_FNAME, GAME_HIGH_SCORE_TABLE_ENTRY_FONT_SIZE, std::to_string(i + 1), GAME_HIGH_SCORE_TABLE_ENTRY_COLOR);
    SDL_Rect center_loc = rank_text.center_text(screen_height, screen_width);
    RenderText(rank_text, center_loc.x / 3, center_loc.y + (i * rank_text.get_text_rect().h)); // put centered up top 1/3 to the left
    // set up name
    Text name_text(sdl_renderer, FONT_FNAME, GAME_HIGH_SCORE_TABLE_ENTRY_FONT_SIZE, names[i], GAME_HIGH_SCORE_TABLE_ENTRY_COLOR);
    center_loc = name_text.center_text(screen_height, screen_width);
    RenderText(name_text, center_loc.x, center_loc.y + (i * name_text.get_text_rect().h)); // put centered up top
    // set up score
    Text score_text(sdl_renderer, FONT_FNAME, GAME_HIGH_SCORE_TABLE_ENTRY_FONT_SIZE, std::to_string(scores[i]), GAME_HIGH_SCORE_TABLE_ENTRY_COLOR);
    center_loc = score_text.center_text(screen_height, screen_width);
    RenderText(score_text, center_loc.x * 5 / 3, center_loc.y + (i * score_text.get_text_rect().h)); // put centered up top 1/3 to the right
  }
}
void Renderer::RenderPauseMenu()
{
  SDL_Rect pause_block{(int)screen_width / 4, (int)screen_height / 4, (int)screen_width, (int)screen_height};

  // Clear screen

  ClearScreen();

  // write pause
  Text pause_text(sdl_renderer, FONT_FNAME, GAME_PAUSE_FONT_SIZE, GAME_PAUSE_TEXT, GAME_PAUSE_COLOR);
  SDL_Rect center_loc = pause_text.center_text(screen_height, screen_width);
  RenderText(pause_text, center_loc.x, center_loc.y);
  SDL_RenderPresent(sdl_renderer); //puts image on screen
}

void Renderer::ClearScreen()
{
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);
}
void Renderer::RenderText(Text text, int x, int y)
{
  text.set_text_rect_pos(x, y);
  SDL_Rect r = text.get_text_rect();
  if (text.need_to_load_texture)
  {
    text.set_text_texture(text.load_font_texture(sdl_renderer));
    int w = text.get_text_rect().w;
    int h = text.get_text_rect().h;
    SDL_QueryTexture(text.get_text_texture(), nullptr, nullptr, &w, &h);
  }

  SDL_RenderCopy(sdl_renderer, text.get_text_texture(), nullptr, &r);
}
void Renderer::UpdateWindowTitle(int score, int fps)
{
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
