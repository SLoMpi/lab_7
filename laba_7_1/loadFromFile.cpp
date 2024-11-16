//
// Created by Влад Ходоровский on 16.11.2024.
//
#include "header.h"
#include <fstream>

using namespace std;

void loadFromFile(const string& flname, vector<string>& Data) {
    ifstream infile(flname);
    if (!infile) {
        throw runtime_error("Cannot open file for reading: " + flname);
        return;
    }
    Data.clear();
    ifstream in(flname);
    string word;
    if (in.is_open())
    {
        while (getline(in, word)){
        Data.push_back(word);
        }
    }
    in.close();
}