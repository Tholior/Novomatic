#pragma once
#include "vec2.hpp"
#include <array>
#include "raylib.h"

struct Triangle {
    std::array<vec2, 3> points;

    void draw(Color color) const {
        DrawTriangle(
            {points[0].x, points[0].y},
            {points[1].x, points[1].y},
            {points[2].x, points[2].y},
            color
        );
    }

    void move(float dx, float dy) {
        for (auto& p : points) {
            p.x += dx;
            p.y += dy;
        }
    }
};