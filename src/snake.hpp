#pragma once

#include <raylib.h>
#include <vector>
#include <cstddef>

using namespace std;

class Snake
{
private:
    Vector2 pos = {10, 10};
    Vector2 size = {50, 50};
    Color colour = GREEN;
    Vector2 speed = {1, 0};

    vector<Snake> tail = {};

public:
    Snake() {};
    void drawSnake();
    void updateSnake(int frame);
};

