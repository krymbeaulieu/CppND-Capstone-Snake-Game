#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "text.h"

class Controller
{
public:
   void HandleInput(bool &running, Snake &snake, bool &paused, bool &game_lost, std::string &name_input, bool &name_done) const;

private:
   void SnakeUnpause(Snake &snake) const;
   void SnakePause(Snake &snake) const;
   void ChangeDirection(Snake &snake, Snake::Direction input,
                        Snake::Direction opposite) const;
};

#endif