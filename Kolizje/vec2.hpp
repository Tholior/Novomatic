#pragma once

struct vec2 {
    float x, y;

    vec2 operator-(const vec2& other) const { return {x - other.x, y - other.y}; }
    float dot(const vec2& other) const { return x * other.x + y * other.y; }
};