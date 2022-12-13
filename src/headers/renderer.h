#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <SDL2/SDL.h>
#include "headers/snake.h"
#include "headers/text.h"
#include "headers/highscores.h"

class Renderer
{
public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food);
  void UpdateWindowTitle(int score, int fps);
  void RenderPauseMenu();
  void RenderLoseScreen(HighScores &high_scores, std::string &name_text, bool &name_done);
  void RenderText(Text text, int x, int y);
  void RenderScoreHeaders();
  void RenderScores(HighScores &high_scores, bool &name_done);
  void ClearScreen();
  SDL_Renderer getRenderer();

private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif