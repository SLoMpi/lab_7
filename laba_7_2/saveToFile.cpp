//
// Created by Влад Ходоровский on 16.11.2024.
//

#include "header.h"
#include <fstream>
#include <iostream>
using namespace std;

void saveToFile(const string& fname, const vector<Book>& data) {
    ofstream outfile(fname);
    if (!outfile) {
        throw runtime_error("Cannot open file for writing: " + fname);
    }
    size_t numBooks = data.size();
    outfile << numBooks << endl;
    for (const auto& book : data) {
        outfile << "Author: " << book.Author << "\t\t"
                << "Title: " << book.Title << "\t\t"
                << "Year: " << book.Year << endl;
    }
    outfile.close();
}