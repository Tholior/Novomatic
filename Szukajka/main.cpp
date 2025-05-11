#include <iostream>
#include "searchengine.hpp"

int main() {
    SearchEngine engine;
    string line;

std::cout << "Type 'add: ' to add keywords, type 'ask: ' to ask for results" << endl;

    while (getline(cin, line)) {
        if (line.rfind("add: ", 0) == 0) {
            string keyword = line.substr(5);
            engine.add(keyword);
        } else if (line.rfind("ask: ", 0) == 0) {
            string prefix = line.substr(5);
            vector<string> results = engine.ask(prefix);
            for (const string& res : results) {
                cout << "result: " << res << endl;
            }
        }
        else {std::cout << "Unknown command! Type 'add: ' to add keywords, type 'ask: ' to ask for results" << endl;}
    }
    return 0;
}