#include <raylib.h>
#include <iostream>

int main() 
{
    const Color GREY = {29, 29, 29, 255};

    // Initialize window
    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 1000;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) 
    {
        // Events
        

        // Update
       
        // Draw
        BeginDrawing();
        EndDrawing();
    }
    
    CloseWindow();
}