#include "headers/controller.h"
#include <iostream>
#include "SDL.h"
#include "headers/snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}
void Controller::SnakeUnpause(Snake &snake) const{
  snake.speed = snake.prev_speed; 
  // don't want to put in prev speed 0 because pause 'stops time' so snake would be at previous speed and never know of the 0 speed
  return;
}

void Controller::SnakePause(Snake &snake) const{
  snake.prev_speed = snake.speed;
  snake.speed = 0.0;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake, bool &paused) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
        
        case SDLK_ESCAPE:
          if(paused){
            // already paused, unpaused
            std::cout << "PRESSED ESCAPE: Unpausing" << std::endl;
            paused = false;
            SnakeUnpause(snake);
          }else{
            std::cout << "PRESSED ESCAPE: Pausing" << std::endl;
            paused = true;
            SnakePause(snake);
          }
          break;
      }
    }
  }
}