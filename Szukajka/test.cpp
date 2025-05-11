#include <cassert>
#include <iostream>
#include "searchengine.hpp"

void testAddAndAsk() {
    SearchEngine engine;
    engine.add("Kiedy jest nowy rok w Chinach?");
    engine.add("Kiedy jest nowy rok w Tajlandii?");

    auto results = engine.ask("Kiedy jest nowy rok");

    assert(results.size() == 2);
    assert(results[0] == "kiedy jest nowy rok w chinach?" || results[1] == "kiedy jest nowy rok w chinach?");
    assert(results[0] == "kiedy jest nowy rok w tajlandii?" || results[1] == "kiedy jest nowy rok w tajlandii?");

    std::cout << "Test passed: testAddAndAsk" << std::endl;
}

void testAskEmpty() {
    SearchEngine engine;

    auto results = engine.ask("Kiedy jest nowy");

    assert(results.empty());

    std::cout << "Test passed: testAskEmpty" << std::endl;
}

void testMatchPrefix() {
    SearchEngine engine;
    engine.add("Co jest stolica Czech?");
    engine.add("Co jest stolica Polski?");
    engine.add("Kiedy jest nowy rok w Chinach?");

    auto results = engine.ask("Co jest stolica");

    assert(results.size() == 2);
    assert(results[0] == "co jest stolica czech?" || results[1] == "co jest stolica czech?");
    assert(results[0] == "co jest stolica polski?" || results[1] == "co jest stolica polski?");
    
    std::cout << "Test passed: testMatchPrefix" << std::endl;
}
void testCaseInsensitivity() {
    SearchEngine engine;

    engine.add("Kiedy jest nowy rok w Chinach?");
    engine.add("kiedy jest nowy rok w chinach?");
    engine.add("KIEDY JEST NOWY ROK W CHINACH?");
    engine.add("Kiedy jest nowy rok w Tajlandii?");
    engine.add("Kiedy jest nowy rok w Polsce?");
    engine.add("Kiedy jest nowy rok w Polsce?");

    auto results = engine.ask("Kiedy jest nowy");

    assert(results.size() == 3);
    assert(results[0] == "kiedy jest nowy rok w chinach?" && results[1] == "kiedy jest nowy rok w polsce?" && results[2] == "kiedy jest nowy rok w tajlandii?");
    std::cout << "Test passed: testCaseInsensitivity" << std::endl;
}

int main() {
    testAddAndAsk();
    testAskEmpty();
    testMatchPrefix();
    testCaseInsensitivity();

    return 0;
}