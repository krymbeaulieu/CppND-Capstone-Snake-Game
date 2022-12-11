#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "headers/defs.h"
#include "headers/renderer.h"
#include "headers/text.h"

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
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

void Renderer::RenderLoseScreen(){
  // set you lose text
  // if(){
  //   std::cout << "YOU MADE A HIGH SCORE" << std::endl;
  // }
  ClearScreen();

  Text lose_text(sdl_renderer,FONT_FNAME,GAME_LOSE_FONT_SIZE,GAME_LOSE_TEXT,GAME_LOSE_COLOR);
  SDL_Rect center_loc = lose_text.center_text(screen_height,screen_width);
  RenderText(lose_text,center_loc.x,center_loc.y/6);
  SDL_RenderPresent(sdl_renderer); //puts image on screen

}

void Renderer::RenderPauseMenu()
{
  SDL_Rect pause_block {screen_width/4, screen_height/4, screen_width, screen_height };

  // Clear screen
  
  ClearScreen();

  // write pause
  Text pause_text(sdl_renderer,FONT_FNAME,GAME_PAUSE_FONT_SIZE,GAME_PAUSE_TEXT,GAME_PAUSE_COLOR);
  SDL_Rect center_loc = pause_text.center_text(screen_height,screen_width);
  RenderText(pause_text,center_loc.x,center_loc.y);
  SDL_RenderPresent(sdl_renderer); //puts image on screen

}

void Renderer::ClearScreen(){
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);
}
void Renderer::RenderText(Text text, int x, int y){
  text.set_text_rect(x,y);
  SDL_Rect r = text.get_text_rect();
  SDL_RenderCopy(sdl_renderer,text.get_text_texture(),nullptr,&r);
  
}
void Renderer::UpdateWindowTitle(int score, int fps)
{
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
