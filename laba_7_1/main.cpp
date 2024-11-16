#include "header.h"
#include <iostream>
using namespace std;
int main() {
    vector<string> words = {"apple", "banana", "cherry", "date"};
    string fname = "ot.txt";

    saveToFile(fname, words);
    cout << "Save:" << endl;
    vector<string> loadedWords;
    loadFromFile(fname, loadedWords);

    cout << "Load:" << endl;
    for (const auto& word : loadedWords) {
        cout << word << endl;
    }

    return 0;
}

