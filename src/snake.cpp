#include "snake.hpp"
#include <cassert>
#include <iostream>


void Snake::DrawSnake()
{
    for (int2 tailPos: tail)
    {
        DrawRectangle(((tailPos.x * SIZE.x) + bodyPadding)*scale, ((tailPos.y * SIZE.y) + bodyPadding)*scale, (SIZE.x - bodyPadding*2)*scale, (SIZE.y - bodyPadding*2)*scale, COLOUR);
    }

    DrawRectangle(((pos.x * SIZE.x) + bodyPadding)*scale, ((pos.y * SIZE.y) + bodyPadding)*scale, (SIZE.x - bodyPadding*2)*scale, (SIZE.y - bodyPadding*2)*scale, { 0, 200, 150, 255 });
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

    pos.x += speed.x;
    pos.x = pos.x % (WINDOW.x / SIZE.x);
    if (pos.x < 0) pos.x = (WINDOW.x / SIZE.x)-1;
    
    pos.y += speed.y;
    pos.y = pos.y % (WINDOW.y / SIZE.y);
    if (pos.y < 0) pos.y = (WINDOW.y / SIZE.y)-1;

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

void Snake::UpdateWindow(int windowWidth, int windowHeight)
{
    scale = min((float)windowWidth / (float)WINDOW.x, (float)windowHeight / (float)WINDOW.y);
    cout << scale << '\n';
}
