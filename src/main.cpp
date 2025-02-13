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
    Snake snake;

    // Main game loop
    while (!WindowShouldClose()) 
    {
        // Events

        // Update
        if (frame % 10 == 0)
        {
            snake.updateSnake(frame);
        }
        
        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        snake.drawSnake();
        EndDrawing();
        
        frame++;
    }
    
    CloseWindow();
}