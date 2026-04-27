#pragma once
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct CompareWords {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

class WordCounter {
private:
    map<string, int> word_counts;

public:
    void parse_text(const string& text);
    void print_results();
};