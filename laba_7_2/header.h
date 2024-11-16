//
// Created by Влад Ходоровский on 16.11.2024.
//

#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <vector>
#include "book.h"

using namespace std;
void saveToFile(const std::string& filename, const std::vector<Book>& data);
void loadFromFile(const std::string& filename, std::vector<Book>& outData);
#endif//HEADER_H
