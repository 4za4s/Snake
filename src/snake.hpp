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
    const int2 SIZE = {20, 20};
    const Color COLOUR = GREEN;
    const int2 WINDOW = {0, 0};
    int2 pos = {0, 0};
    int2 speed = {1, 0};
    int bodyPadding = 2; // space to leave between segments
    float scale = 1;

    vector<int2> tail = {};

public:
    Snake(int WINDOW_WIDTH, int WINDOW_HEIGHT):WINDOW({WINDOW_WIDTH, WINDOW_HEIGHT}) {};
    ~Snake() {};
    void DrawSnake();
    void UpdateSnake();
    int2 GetSpeed() {return speed;};
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void EatFruit();

    void UpdateWindow(int windowWidth, int windowHeight);
};

