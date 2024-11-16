//
// Created by Влад Ходоровский on 16.11.2024.
//

#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>

void saveToFile(const std::string& filename, const std::vector<std::string>& data);
void loadFromFile(const std::string& filename, std::vector<std::string>& outData);

#endif