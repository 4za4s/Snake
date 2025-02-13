#include "snake.hpp"
#include <cassert>
#include <iostream>


void Snake::DrawSnake()
{
    DrawRectangleV(pos, SIZE, COLOUR);
    for (Vector2 tailPos: tail)
    {
        DrawRectangleV(tailPos, SIZE, COLOUR);
    }
}

void Snake::UpdateSnake(int frame)
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

    pos.x += speed.x * (SIZE.x + 10);
    pos.y += speed.y * (SIZE.y + 10); 
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
