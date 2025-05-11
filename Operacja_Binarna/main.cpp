#include <iostream>
#include "calculate.hpp"

struct MyType {
    int val;

    MyType(int v = 0) : val(v) {}

    static MyType identity() {
        return MyType(0);
    }

    friend MyType operator+(const MyType& a, const MyType& b) {
        return MyType(a.val + b.val);
    }
};

int main() {
    MyType x(2);
    auto result = calculate(3, x, [](const MyType& a, const MyType& b) {
        return a + b;
    });
    // should print 6
    std::cout << "Result: " << result.val << std::endl;
}