#include "searchengine.hpp"

SearchEngine::SearchEngine() {
    root = new TrieNode();
}

SearchEngine::~SearchEngine() {
    deleteTrie(root);
}

void SearchEngine::add(const string &keyword) {
    string lowerKeyword = toLower(keyword);
    TrieNode* current = root;

    for (char c : lowerKeyword) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    // if keyword already exists add +1 to weight
    current->keywordWeights[lowerKeyword]++;
}

vector<string> SearchEngine::ask(const string& prefix) {
    string lowerPrefix = toLower(prefix);
    TrieNode* current = root;

    for (char c : lowerPrefix) {
        if (current->children.find(c) == current->children.end()) {
            return {};
        }
        current = current->children[c];
    }

    vector<pair<string, int>> weightedKeywords;
    collectAllKeywords(current, weightedKeywords);

    sort(weightedKeywords.begin(), weightedKeywords.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) {
                    return a.second > b.second;
         });

    vector<string> results;
    for (const auto& entry : weightedKeywords) {
        results.push_back(entry.first);
    }
    return results;
}

void SearchEngine::deleteTrie(TrieNode *node) {
    for (auto& child : node->children) {
        deleteTrie(child.second);
    }
    delete node;
}

string SearchEngine::toLower(const string &str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

void SearchEngine::collectAllKeywords(TrieNode* node, vector<pair<string, int>>& weightedKeywords) {
    for (const auto& entry : node->keywordWeights) {
        weightedKeywords.push_back(entry);
    }

    for (auto& pair : node->children) {
        collectAllKeywords(pair.second, weightedKeywords);
    }
}