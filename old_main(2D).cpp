// Role_playing_gameV2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "raylib.h"

// Define screen dimensions
const int screenWidth = 800;
const int screenHeight = 450;

// Developing the Game World!!!

// 1. start by defining the World Dimensions

const int worldWidth = 1200;
const int worldHeight = 800;

// 2. Creating a Background: starting with a simple colour: plans to transition to a textured background that looks like an overgrown city

void DrawBackground() {
    // simple background for now
    DrawRectangle(0, 0, worldWidth, worldHeight, DARKGREEN); 
}

// 3. Viewing the world: since the world dimensions might be larger than the window, we should implement a simple camera or viewpoint
// mechanism. This allows the player to explore the world by moving around within these larger dimensions.

// define the camera (viewpoint)

void SetupCamera(Camera2D& camera) {
    camera.target = { (float)screenWidth / 2.0f, (float)screenHeight / 2.0f };
    // this is where the camera is looking - set to the centre of the screen (makes sense for a centred view)
    camera.offset = { (float)screenWidth / 2.0f, (float)screenHeight / 2.0f };
    // this determines the offset of the camera - also centred - keeps the player/main focus of the game in the centre of the screen
    camera.rotation = 0.0f;
    // no rotation in the camera's view
    camera.zoom = 1.0f;
    // no zoom in or out - keeps view normal
}

void DrawGame(Camera2D& camera) {
    BeginDrawing();
    ClearBackground(RAYWHITE); // Clear the background

    BeginMode2D(camera); // Begin 2D mode using the camera
    DrawBackground();    // Draw the world background
    EndMode2D();         // End 2D mode

    EndDrawing();
}


// in C++, 'main' is the entry point for a C++ program. It's a special function where the execution of the program begins.
// the 'main' function returns an integer - typically this is 0 to indicate successful termination, although it can return other integer values to indicate 
// errors or abnormal terminations.

// the 'main' function can accept command-line (CMD) arguments. There are two common forms:
// int main(): indicates the program does not accept any command-line arguements
// int main(int argc, char* argv[]): indicates the program accepts command-line arguments. 
// 'argc' is the count of arguments
// 'argv' is an array of strings containing the arguments

//int main() {
//    // Initialization
//    InitWindow(screenWidth, screenHeight, "Raylib RPG - Virus Survival");
//    SetTargetFPS(60);
//    // this is used to initialise and open a game window
//    // the dimensions of the game window and title are defined
//
//    // declaring and setting up camera
//    Camera2D camera = { 0 };
//    SetupCamera(camera);
//    
//    // sets the frame rate for the application to 60 frames per second
//
//// Main Game Loop: every game runs in what's called a "game loop", a continuous cycle that processes input, updates game state, and renders
//// graphics frame by frame - in raylib this loop is structured as follows:
//
//    while (!WindowShouldClose()) {
//        // Input handling: detect user interactions
//        // Game logic updates: adjust your game state based on inputs and other factors
//        // Rendering: draw your game state to the screen
//
//        // UpdateCamera(&camera); optionally update camera based on player movements
//
//        // Drawing on the Screen: 
//        DrawGame(camera);
//    }
//
//    CloseWindow();
//    return 0;
//}


