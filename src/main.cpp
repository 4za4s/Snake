#include <raylib.h>
#include <iostream>
#include "snake.hpp"

int main() 
{
    // Initialize window
    const int WINDOW_WIDTH = 3000;
    const int WINDOW_HEIGHT = 1000;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake");
    SetTargetFPS(60);

    Color fruit =  {200, 80, 100, 255};

    int frame = 1;
    int keyPressed[2] = {0, 0};
    int keysPressed = 0;
    Snake snake(WINDOW_WIDTH, WINDOW_HEIGHT);
    snake.EatFruit();
    snake.EatFruit();
    snake.EatFruit();
    snake.EatFruit();
    snake.EatFruit();
    snake.EatFruit();
    snake.EatFruit();
    snake.EatFruit();
    snake.EatFruit();
    snake.EatFruit();

    // Main game loop
    while (!WindowShouldClose()) 
    {
        // Events
        if (keysPressed < 2)
        {
            keyPressed[keysPressed] = GetKeyPressed();

            if (keyPressed[keysPressed] > 0)
            {
                keysPressed++;
            }
        }
        // Update
        if (frame % 5 == 0)
        {
            
            if ((IsKeyDown(KEY_LEFT) || keyPressed[0] == KEY_LEFT)  && snake.GetSpeed().x == 0) snake.MoveLeft();
            else if ((IsKeyDown(KEY_RIGHT) || keyPressed[0] == KEY_RIGHT)  && snake.GetSpeed().x == 0) snake.MoveRight();
            else if ((IsKeyDown(KEY_UP) || keyPressed[0] == KEY_UP)  && snake.GetSpeed().y == 0) snake.MoveUp();
            else if ((IsKeyDown(KEY_DOWN) || keyPressed[0] == KEY_DOWN)  && snake.GetSpeed().y == 0) snake.MoveDown();
            if (keysPressed > 0)
            {
                keyPressed[0] = keyPressed[1];
                keyPressed[1] = 0;
                keysPressed--;
            }

            snake.UpdateSnake();
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        snake.DrawSnake();
        EndDrawing();
        
        frame++;
    }
    
    CloseWindow();
}