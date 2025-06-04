#include <raylib.h>
#include <iostream>
#include "snake.hpp"

int main() 
{
    //testing
    // Initialize window
    const int GAME_WIDTH = 640;
    const int GAME_HEIGHT = 360;
    int screenWidth = 0;
    int screenHeight = 0;

    SetConfigFlags (FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    InitWindow(GAME_WIDTH, GAME_HEIGHT, "Snake");
    SetTargetFPS(60);

    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    Color fruit = {200, 80, 100, 255};

    int frame = 1;
    int keyPressed[2] = {0, 0};
    int keysPressed = 0;
    Snake snake(GAME_WIDTH, GAME_HEIGHT);
    for (int i = 0; i < 20; i++)
    {
        snake.EatFruit();
    }
    
    // Main game loop
    while (!WindowShouldClose()) 
    {
        // Events
        if (IsWindowResized())
        {
            screenWidth = GetScreenWidth();
            screenHeight = GetScreenHeight();
            snake.UpdateWindow(screenWidth, screenHeight);
        }

        if (keysPressed < 2)
        {
            keyPressed[keysPressed] = GetKeyPressed();

            if (keyPressed[keysPressed] > 0)
            {
                keysPressed++;
            }
        }

        if (keyPressed[0] == KEY_F)
        {
            if (IsWindowFullscreen())
            {
                SetWindowSize(screenWidth, screenHeight);
                snake.UpdateWindow(screenWidth, screenHeight);
            }
            else 
            {
                int display = GetCurrentMonitor();
                int x = GetMonitorWidth(display);
                int y = GetMonitorHeight(display);
                SetWindowSize(x, y);
                snake.UpdateWindow(x, y);
            }
            ToggleFullscreen();
            keyPressed[0] = keyPressed[1];
            keyPressed[1] = 0;
            keysPressed--;
            cout << screenWidth << ", " << screenHeight << '\n';
            cout << GetScreenWidth() << ", " << GetScreenHeight() << '\n';
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