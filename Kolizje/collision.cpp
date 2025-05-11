#include "Collision.hpp"

static vec2 getNormal(const vec2& edge) {
    return {-edge.y, edge.x};
}

static void projectShape(const std::array<vec2, 3>& pts, const vec2& axis, float& min, float& max) {
    min = max = pts[0].dot(axis);
    for (int i = 1; i < 3; ++i) {
        float proj = pts[i].dot(axis);
        if (proj < min) min = proj;
        if (proj > max) max = proj;
    }
}

static bool overlapping(float minA, float maxA, float minB, float maxB) {
    return !(maxA < minB || maxB < minA);
}

static bool isDegenerate(const Triangle& triangle) {
    const auto& p1 = triangle.points[0];
    const auto& p2 = triangle.points[1];
    const auto& p3 = triangle.points[2];

    float area = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    return area == 0;
}

bool isColliding(const Triangle& triangle1, const Triangle& triangle2) {
    // Check if either triangle is degenerate(has zero area)
    if (isDegenerate(triangle1) || isDegenerate(triangle2)) {
        // No collision if either triangle is degenerate
        return false;
    }

    const auto& pts1 = triangle1.points;
    const auto& pts2 = triangle2.points;

    for (int i = 0; i < 3; ++i) {
        vec2 edge = pts1[(i + 1) % 3] - pts1[i];
        vec2 axis = getNormal(edge);
        float minA, maxA, minB, maxB;
        projectShape(pts1, axis, minA, maxA);
        projectShape(pts2, axis, minB, maxB);
        if (!overlapping(minA, maxA, minB, maxB)) return false;
    }

    for (int i = 0; i < 3; ++i) {
        vec2 edge = pts2[(i + 1) % 3] - pts2[i];
        vec2 axis = getNormal(edge);
        float minA, maxA, minB, maxB;
        projectShape(pts1, axis, minA, maxA);
        projectShape(pts2, axis, minB, maxB);
        if (!overlapping(minA, maxA, minB, maxB)) return false;
    }
    return true;
}