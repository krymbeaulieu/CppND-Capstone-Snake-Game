#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake, bool &paused) const;

 private:
    void SnakeUnpause(Snake &snake) const;
    void SnakePause(Snake &snake) const;
    void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif