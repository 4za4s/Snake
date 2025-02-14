#pragma once

#include <raylib.h>
#include <vector>
#include <cstddef>

using namespace std;

struct int2 
{
    int x = 0;
    int y = 0;
};

class Snake
{
private:
    const int2 SIZE = {40, 40};
    const Color COLOUR = GREEN;
    int2 window = {0, 0};
    int2 pos = {5, 5};
    int2 speed = {1, 0};
    int bodyPadding = 5; // space to leave between segments

    vector<int2> tail = {};

public:
    Snake(int WINDOW_WIDTH, int WINDOW_HEIGHT):window({WINDOW_WIDTH, WINDOW_HEIGHT}) {};
    ~Snake() {};
    void DrawSnake();
    void UpdateSnake();
    int2 GetSpeed() {return speed;};
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void EatFruit();
};

