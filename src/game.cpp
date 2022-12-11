#include <iostream>
#include <SDL2/SDL.h>
#include "headers/game.h"
#include "headers/defs.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1))
{
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool set_high_score = true;
  bool running = true;
  bool paused = false;
  bool game_lost = false;
  while (running)
  {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
  std::cout << "before input game lost: " << game_lost << std::endl;

    controller.HandleInput(running, snake, paused);
      std::cout << "before update game lost: " << game_lost << std::endl;

    game_lost = Update();
          std::cout << "after update game lost: " << game_lost << std::endl;
    if (paused)
    {
      renderer.RenderPauseMenu();
    }
    else if (game_lost)
    {
      std::cout << "in game lost if" << std::endl;
      //TODO: Lost. Handle scoring
      LoadScoresFile(SCORE_FILE);
      // set_high_score = checkScore(GetScore());
      if (set_high_score)
      {
        std::cout << "you set a high score" << std::endl;
      }
      renderer.RenderLoseScreen();
      
    }
    else
    {
      renderer.Render(snake, food);
    }

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000)
    {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration)
    {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

//! check if score is within ranking
bool checkScore(int score)
{
  return false;
}
//! load the scores file for the lose screen and writing a new high score
void Game::LoadScoresFile(std::string fname)
{
}

void Game::PlaceFood()
{
  int x, y;
  while (true)
  {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y))
    {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

//! Update the game states, 0 if snake is dead, 1 if was able to update snake
bool Game::Update()
{
  if (!snake.alive){
    //dead
        return true;
  }
  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y)
  {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.prev_speed = snake.speed;
    snake.speed += 0.02;
  }
  // not dead keep going
  return false;
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }