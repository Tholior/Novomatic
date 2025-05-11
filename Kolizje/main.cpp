#include "raylib.h"
#include "triangle.hpp"
#include "collision.hpp"

int main() {
    InitWindow(800, 600, "Triangle Collision - raylib");
    SetTargetFPS(60);

    Triangle stableTriangle = {{{{500, 300}, {600, 300}, {550, 250}}}};
    Triangle movingTriangle = {{{{200, 200}, {230, 250}, {250, 180}}}};

    while (!WindowShouldClose()) {
        float moveSpeed = 2.5f;
        if (IsKeyDown(KEY_RIGHT)) movingTriangle.move(moveSpeed, 0);
        if (IsKeyDown(KEY_LEFT)) movingTriangle.move(-moveSpeed, 0);
        if (IsKeyDown(KEY_UP)) movingTriangle.move(0, -moveSpeed);
        if (IsKeyDown(KEY_DOWN)) movingTriangle.move(0, moveSpeed);

        bool collision = isColliding(movingTriangle, stableTriangle);
        Color movingTriColor = collision ? RED : GREEN;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        stableTriangle.draw(DARKGRAY);
        movingTriangle.draw(movingTriColor);

        DrawText("Use arrow keys to move the triangle", 10, 10, 20, BLACK);
        if (collision) {
            DrawText("COLLISION!", 10, 40, 30, RED);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}