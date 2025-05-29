#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <ranges>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> keywordWeights;
};

class SearchEngine {
public:
    SearchEngine();
    ~SearchEngine();

    void add(const string& keyword);
    vector<string> ask(const string& prefix);
    void deleteTrie(TrieNode* node);
    string toLower(const string& str);

private:
    void collectAllKeywords(TrieNode* node, vector<pair<string, int>>& weightedKeywords);

    TrieNode* root;
    vector<int> weight;;
};