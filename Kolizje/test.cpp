#include <iostream>
#include "collision.hpp"

bool runTest(const std::string& testName, bool (*testFunc)()) {
    bool passed = testFunc();
    std::cout << testName << ": " << (passed ? "PASS" : "FAIL") << "\n";
    return passed;
}

bool testOverlap() {
    Triangle a = {{{{0, 0}, {1, 0}, {0, 1}}}};
    Triangle b = {{{{0.5f, 0.5f}, {1.5f, 0.5f}, {0.5f, 1.5f}}}};
    return isColliding(a, b);
}

bool testNoOverlap() {
    Triangle a = {{{{0, 0}, {1, 0}, {0, 1}}}};
    Triangle b = {{{{5, 5}, {6, 5}, {5, 6}}}};
    return !isColliding(a, b);
}


bool testVertexTouch() {
    Triangle a = {{{{0, 0}, {1, 0}, {0, 1}}}};
    Triangle b = {{{{1, 1}, {2, 1}, {1, 2}}}};
    return !isColliding(a, b);
}

bool testContained() {
    Triangle outer = {{{{0, 0}, {5, 0}, {0, 5}}}};
    Triangle inner = {{{{1, 1}, {2, 1}, {1, 2}}}};
    return isColliding(outer, inner);
}

bool testEdgeOverlap() {
    Triangle a = {{{{0, 0}, {2, 0}, {1, 1}}}};
    Triangle b = {{{{1, 1}, {3, 1}, {2, 2}}}};
    return isColliding(a, b);
}

bool testDegenerate() {
    Triangle a = {{{{0, 0}, {1, 0}, {2, 0}}}};
    Triangle b = {{{{0, 0}, {1, 1}, {0, 1}}}};
    return !isColliding(a, b);
}

bool testNegativeCoordinates() {
    Triangle a = {{{{-3, -3}, {-2, -3}, {-2.5f, -2}}}};
    Triangle b = {{{{-2.6f, -2.5f}, {-1, -2.5f}, {-2, -1}}}};
    return isColliding(a, b);
}

int main() {
    int passed = 0, total = 0;

    passed += runTest("Overlap", testOverlap);
    total++;

    passed += runTest("No Overlap", testNoOverlap);
    total++;

    passed += runTest("Vertex Touch", testVertexTouch);
    total++;

    passed += runTest("Contained", testContained);
    total++;

    passed += runTest("Edge Overlap", testEdgeOverlap);
    total++;

    passed += runTest("Degenerate", testDegenerate);
    total++;

    passed += runTest("Negative Coordinates", testNegativeCoordinates);
    total++;

    std::cout << "\nPassed " << passed << " out of " << total << " tests.\n";
    return (passed == total) ? 0 : 1; // return 0 if all tests passed, return 1 if any failed
}