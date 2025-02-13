#include "snake.hpp"
#include <cassert>


void Snake::drawSnake()
{

    DrawRectangleV(pos, size, colour);
}

void Snake::updateSnake(int frame)
{
    //only move in one direction
    assert((abs(speed.x) == 1 && speed.y == 0) || (speed.x == 0 && abs(speed.y == 1)));

    pos.x += speed.x * (size.x + 20);
    pos.y += speed.y * (size.y + 20);
    
}
