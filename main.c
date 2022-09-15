#include "raylib.h"
#include "rlgl.h"
#include <math.h>


int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    SetCameraMode(camera, CAMERA_FIRST_PERSON); // Set a free camera mode
    
    Model model = LoadModel("assets/dice.obj");
    // Texture2D texture = LoadTexture("resources/models/obj/castle_diffuse.png"); // Load model texture
    Texture2D texture = LoadTexture("assets/Material.png"); // Load model texture
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;



    float c = 0.0;


    while (!WindowShouldClose())
    {
        c+= 0.0001;

        UpdateCamera(&camera);

        // cubePosition.z = sin(c) * 10.0;

        BeginDrawing();

            ClearBackground(BLUE);
            BeginMode3D(camera);
                rlPushMatrix();
                rlRotatef(
                        sin(c) * 100,
                        cos(c) * 100,
                        -cos(c) * 100, -1);
                DrawModel(model, cubePosition, 1.0, WHITE);
                rlPopMatrix();
            EndMode3D();


                rlPushMatrix();
                rlRotatef(
                        0,
                        cos(c) * 10,
                        -sin(c) * 10, -1);
                        DrawRectangle(100,100,100,100, GREEN);
                rlPopMatrix();
                DrawText("Simple Window", 190, 200, 20, YELLOW);
        EndDrawing();
    }

    UnloadTexture(texture);
    UnloadModel(model);
    CloseWindow();

    return 0;
}
