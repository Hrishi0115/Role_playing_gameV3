#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib 3D RPG - Virus Survival");
    SetTargetFPS(60);

    // Setup 3D camera
    Camera camera = { 0 };  // Initialize the camera to zero
    camera.position = Vector3{ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = Vector3{ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards sky)
    camera.fovy = 45.0f;                              // Field of view Y
    camera.projection = CAMERA_PERSPECTIVE;           // Camera mode

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        DrawGrid(10, 1.0f); // Draw a grid
        EndMode3D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
