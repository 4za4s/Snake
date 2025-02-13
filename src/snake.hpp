#pragma once

#include <raylib.h>
#include <vector>
#include <cstddef>

using namespace std;

class Snake
{
private:
    const Vector2 SIZE = {30, 30};
    const Color COLOUR = GREEN;
    Vector2 pos = {5, 5};
    Vector2 speed = {1, 0};

    vector<Vector2> tail = {};

public:
    Snake() {};
    ~Snake() {};
    void DrawSnake();
    void UpdateSnake(int frame);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void EatFruit();
};

