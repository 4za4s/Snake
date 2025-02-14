#include "snake.hpp"
#include <cassert>
#include <iostream>


void Snake::DrawSnake()
{
    for (int2 tailPos: tail)
    {
        DrawRectangle(tailPos.x, tailPos.y, SIZE.x, SIZE.y, COLOUR);
    }

    DrawRectangle(pos.x, pos.y, SIZE.x, SIZE.y, { 0, 200, 150, 255 });
}

void Snake::UpdateSnake()
{
    //only move in one direction
    assert((abs(speed.x) == 1 && speed.y == 0) || (speed.x == 0 && abs(speed.y) == 1));

    for (int i = tail.size(); i > 0; i--)
    {
        tail[i] = tail[i-1];
    }

    if (tail.size() > 0)
    {
        tail[0] = pos;
    }

    pos.x += (speed.x * (SIZE.x + bodyPadding*2));
    pos.x = (pos.x % window.x);
    pos.y += (speed.y * (SIZE.y + bodyPadding*2)); 
    pos.y = (pos.y % window.y);
}

void Snake::MoveUp()
{
    speed.x = 0;
    speed.y = -1;
}

void Snake::MoveDown()
{
    speed.x = 0;
    speed.y = 1;
}

void Snake::MoveLeft()
{
    speed.x = -1;
    speed.y = 0;
}

void Snake::MoveRight()
{
    speed.x = 1;
    speed.y = 0;
}

void Snake::EatFruit()
{
    tail.push_back(pos);
}
