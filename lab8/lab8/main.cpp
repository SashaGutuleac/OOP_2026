#include <iostream>
#include <fstream>
#include <string>
#include "WordCounter.h"

using namespace std;

int main() {
    ifstream file("input.txt");

    if (!file.is_open()) {
        cout << "eroare la deschiderea fisierului\n";
        return 1;
    }

    string text = "";
    string line;

    while (getline(file, line)) {
        text += line + " ";
    }

    file.close();

    WordCounter counter;
    counter.parse_text(text);
    counter.print_results();

    return 0;
}