//
// Created by Влад Ходоровский on 16.11.2024.
//
#include "header.h"
#include <fstream>
#include <iostream>

using namespace std;

void loadFromFile(const string& fname, vector<Book>& outData) {
    ifstream infile(fname);
    if (!infile) {
        throw runtime_error("Не удалось открыть файл для чтения: " + fname);
    }

    outData.clear();

    size_t numBooks;
    infile >> numBooks;
    infile.ignore();

    for (uint32_t i = 0; i < numBooks; ++i) {
        string line;
        if (getline(infile, line)) {
            Book book;
            size_t posAuthor = line.find("Author:");
            size_t posTitle = line.find("\tTitle:");
            size_t posYear = line.find("\tYear:");

            if (posAuthor != string::npos && posTitle != string::npos && posYear != string::npos) {
                book.Author = line.substr(posAuthor + 7, posTitle - (posAuthor + 7));
                book.Title = line.substr(posTitle + 7, posYear - (posTitle + 7));
                book.Year = stoi(line.substr(posYear + 6));

                outData.push_back(book);
            }
        }
    }

    infile.close();
}