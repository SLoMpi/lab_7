//
// Created by Влад Ходоровский on 16.11.2024.
//
#include "header.h"
#include <fstream>

using namespace std;

void saveToFile(const string& fname, const vector<string>& data) {
    ofstream outfile(fname);
    if (!outfile) {
        throw runtime_error("Cannot open file for writing: " + fname);
    }
    for (const auto& word : data) {
        outfile << word << endl;
    }
}
