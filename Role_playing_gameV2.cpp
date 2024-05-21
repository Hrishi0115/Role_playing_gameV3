// Role_playing_gameV2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "raylib.h"

// Define screen dimensions
const int screenWidth = 800;
const int screenHeight = 450;

// in C++, 'main' is the entry point for a C++ program. It's a special function where the execution of the program begins.
// the 'main' function returns an integer - typically this is 0 to indicate successful termination, although it can return other integer values to indicate 
// errors or abnormal terminations.

// the 'main' function can accept command-line (CMD) arguments. There are two common forms:
// int main(): indicates the program does not accept any command-line arguements
// int main(int argc, char* argv[]): indicates the program accepts command-line arguments. 
// 'argc' is the count of arguments
// 'argv' is an array of strings containing the arguments

int main() {
    // Initialization
    InitWindow(screenWidth, screenHeight, "Raylib RPG - Virus Survival");
    // this is used to initialise and open a game window
    // the dimensions of the game window and title are defined

// Main Game Loop: every game runs in what's called a "game loop", a continuous cycle that processes input, updates game state, and renders
// graphics frame by frame - in raylib this loop is structured as follows:

    while (!WindowShouldClose()) {
        // Input handling: detect user interactions
        // Game logic updates: adjust your game state based on inputs and other factors
        // Rendering: draw your game state to the screen

        // Drawing on the Screen: 
        BeginDrawing();
        ClearBackground(RAYWHITE); // Clear the screen with a solid colour
        DrawText("Welcome to the game!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    return 0;
}