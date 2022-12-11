#include <iostream>
#include <SDL2/SDL.h>
#include "headers/snake.h"
#include "headers/controller.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const
{
  if (snake.direction != opposite || snake.size == 1)
    snake.direction = input;
  return;
}
void Controller::SnakeUnpause(Snake &snake) const
{
  snake.speed = snake.prev_speed;
  // don't want to put in prev speed 0 because pause 'stops time' so snake would be at previous speed and never know of the 0 speed
  return;
}

void Controller::SnakePause(Snake &snake) const
{
  snake.prev_speed = snake.speed;
  snake.speed = 0.0;
  return;
}

// bool isInRect(SDL_Event &e, Widget w) const{
//   // check page's current widgets
//   while(w.prev != nullptr){
//     //
//   }
//   return false;
// }

void Controller::HandleInput(bool &running, Snake &snake, bool &paused) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      running = false;
    }
    else if (e.type == SDL_KEYDOWN)
    {
      switch (e.key.keysym.sym)
      {
      case SDLK_UP:
        if (!paused)
        {
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
        }
        break;

      case SDLK_DOWN:
        if (!paused)
        {
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
        }
        break;

      case SDLK_LEFT:
        if (!paused)
        {
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
        }
        break;

      case SDLK_RIGHT:
        if (!paused)
        {
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
        }
        break;
      case SDLK_k:
        if (!paused)
        {
          snake.alive = false;
        }
        break;

      // escape only works in game
      case SDLK_ESCAPE:
        if (paused)
        {
          // already paused, unpaused
          paused = false;
          SnakeUnpause(snake);
          //maybe undo the game paused texture here
        }
        else
        {
          paused = true;
          SnakePause(snake);
        }

        break;
      }
    }
    else if (e.type == SDL_MOUSEBUTTONUP)
    {
      std::cout << "Pressed the mouse!" << std::endl;
    }
  }
}