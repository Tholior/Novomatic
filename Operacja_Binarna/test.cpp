#include <iostream>
#include "calculate.hpp"

struct MyType {
    int val;
    MyType(int v = 0) : val(v) {}

    static MyType identity() { return MyType(0); }

    friend MyType operator+(const MyType& a, const MyType& b) {
        return MyType(a.val + b.val);
    }

    bool operator==(const MyType& other) const {
        return val == other.val;
    }
};

bool testCalculate() {
    MyType x(2);
    auto result = calculate(3, x, [](const MyType& a, const MyType& b) {
        return a + b;
    });

    if (result == MyType(6)) {
        std::cout << "testCalculate passed.\n";
        return true;
    }
    std::cout << "testCalculate FAILED. Expected 6, got " << result.val << "\n";
    return false;
}

bool testIdentity() {
    MyType x(5);
    auto result = calculate(0, x, [](const MyType& a, const MyType& b) {
        return a + b;
    });

    if (result == MyType::identity()) {
        std::cout << "testIdentity passed.\n";
        return true;
    }
    std::cout << "testIdentity FAILED. Expected identity (0), got " << result.val << "\n";
    return false;
}

bool testEdgeLarge() {
    MyType x(100000000);
    auto result = calculate(6, x, [](const MyType& a, const MyType& b) {
        return a + b;
    });

    if (result == MyType(600000000)) {
        std::cout << "testEdgeLarge passed.\n";
        return true;
    }
    std::cout << "testEdgeLarge FAILED. Expected 600000000, got " << result.val << "\n";
    return false;
}

bool testEdgeNegative() {
    MyType x(-4);
    auto result = calculate(3, x, [](const MyType& a, const MyType& b) {
        return a + b;
    });

    if (result == MyType(-12)) {
        std::cout << "testEdgeNegative passed.\n";
        return true;
    }
    std::cout << "testEdgeNegative FAILED. Expected -12, got " << result.val << "\n";
    return false;
}

int main() {
    bool all_passed = true;

    if (!testCalculate()) all_passed = false;
    if (!testIdentity()) all_passed = false;
    if (!testEdgeLarge()) all_passed = false;
    if (!testEdgeNegative()) all_passed = false;

    if (all_passed) {
        std::cout << "All tests passed.\n";
        return 0;
    }
    std::cout << "Some tests failed.\n";
    return 1;

}