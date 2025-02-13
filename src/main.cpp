#include <raylib.h>
#include <iostream>
#include "snake.hpp"

int main() 
{
    // Initialize window
    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 1000;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake");
    SetTargetFPS(60);

    int frame = 1;
    int keyPressed[2] = {0, 0};
    int keysPressed = 0;
    Snake snake;
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
            if (keysPressed > 0)
            {
                if (keyPressed[0] == KEY_LEFT) snake.MoveLeft();
                else if (keyPressed[0] == KEY_RIGHT) snake.MoveRight();
                else if (keyPressed[0] == KEY_UP) snake.MoveUp();
                else if (keyPressed[0] == KEY_DOWN) snake.MoveDown();
            
                keyPressed[0] = keyPressed[1];
                keyPressed[1] = 0;

                keysPressed--;
            }

            snake.UpdateSnake(frame);
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