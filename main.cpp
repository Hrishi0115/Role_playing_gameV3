#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;

// 1. Adding a Player Character - initially I'll use a cube to represent the player for simplicity - will replace with more detailed model later
// Player Setup:
// 1. Player Model: We will use a cube to represent the player
// 2. Player Position: Initially place player at the centre of the grid

struct Player // Player Structure - similar to class, members of class are private by default, members of a structure are public by default
{
    Vector3 position;
    float speed;
    Model model;
};

// Initialise the player
Player InitPlayer() {
    Player player;
    player.position = Vector3{ 0.0f, 0.5f, 0.0f }; // Slightly above the ground to see on the grid
    player.speed = 5.0f; // Movement spped
    player.model = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f)); // 1x1x1 cube
    return player;
}

// Draw the player
void DrawPlayer(Player player) {
    DrawModel(player.model, player.position, 1.0f, WHITE); // draw player model at its position
}

// 2. Implementing Basic Movement - control the player using the keyboard

void UpdatePlayer(Player& player, float deltaTime) {
    if (IsKeyDown(KEY_W)) player.position.z -= player.speed * deltaTime;
    if (IsKeyDown(KEY_S)) player.position.z += player.speed * deltaTime;
    if (IsKeyDown(KEY_A)) player.position.x -= player.speed * deltaTime;
    if (IsKeyDown(KEY_D)) player.position.x += player.speed * deltaTime;
}

int main() {

    InitWindow(screenWidth, screenHeight, "Raylib 3D RPG - Virus Survival");
    SetTargetFPS(60);

    // Setup 3D camera
    Camera camera = { 0 };  // Initialize the camera to zero
    camera.position = Vector3{ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = Vector3{ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards sky)
    camera.fovy = 45.0f;                              // Field of view Y
    camera.projection = CAMERA_PERSPECTIVE;           // Camera mode

    Player player = InitPlayer(); 

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime(); // Get time between frames

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        DrawGrid(10, 1.0f); // Draw a grid
        UpdatePlayer(player, deltaTime);
        DrawPlayer(player);

        EndMode3D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
