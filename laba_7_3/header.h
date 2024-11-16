//
// Created by Влад Ходоровский on 16.11.2024.
//

#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <map>
#include <vector>
using namespace std;


enum Score {
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

std::string scoreToString(Score score);

struct Student
{
    std::string Name;
    int Year;
    std::map<std::string, Score> RecordBook;
};

using Groups = std::map<std::string, std::vector<Student>>;
void saveToFile(const std::string& filename, const Groups& groups);
void loadFromFile(const std::string& filename, Groups& outGroups);
string scoreToString(Score score);

#endif //HEADER_H
