#include "WordCounter.h"
#include <iostream>

using namespace std;

void WordCounter::parse_text(const string& text) {
    string separators = " ,?!.";
    size_t start = text.find_first_not_of(separators);

    while (start != string::npos) {
        size_t end = text.find_first_of(separators, start);
        string word;

        if (end == string::npos) {
            word = text.substr(start);
        }
        else {
            word = text.substr(start, end - start);
        }

        for (size_t i = 0; i < word.length(); i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                word[i] = word[i] + 32;
            }
        }

        word_counts[word]++;

        if (end == string::npos) {
            break;
        }
        start = text.find_first_not_of(separators, end);
    }
}

void WordCounter::print_results() {
    priority_queue<pair<string, int>, vector<pair<string, int>>, CompareWords> pq;

    map<string, int>::iterator it;
    for (it = word_counts.begin(); it != word_counts.end(); it++) {
        pq.push(*it);
    }

    while (!pq.empty()) {
        pair<string, int> top_element = pq.top();
        pq.pop();

        cout << top_element.first << " => " << top_element.second << "\n";
    }
}