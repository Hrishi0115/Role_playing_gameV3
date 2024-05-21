// Role_playing_gameV2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "raylib.h"

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Simple Program - Welcome to raylib");

    SetTargetFPS(60);  // Set the game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update (Not needed for this simple program, but normally logic goes here)

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE); // Set background color
        DrawText("Hello from Raylib", 190, 200, 20, LIGHTGRAY); // Draw some text

        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}