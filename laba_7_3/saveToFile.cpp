//
// Created by Влад Ходоровский on 16.11.2024.
//
#include "header.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

void saveToFile(const string& filename, const Groups& groups) {
    ofstream outfile(filename);
    if (!outfile) {
        throw runtime_error("Cannot open file for writing: " + filename);
    }

    size_t numGroups = groups.size();
    outfile << numGroups << endl;

    for (const auto& groupPair : groups) {
        const string& groupName = groupPair.first;
        const vector<Student>& students = groupPair.second;

        outfile << "GroupName:" << groupName << endl;

        size_t numStudents = students.size();
        outfile << "NumStudents:" << numStudents << endl;

        for (const auto& student : students) {
            outfile << "StudentName:" << student.Name << "\t"
                    << "Year:" << student.Year << endl;

            size_t numRecords = student.RecordBook.size();
            outfile << "NumRecords:" << numRecords << endl;

            for (const auto& record : student.RecordBook) {
                outfile << "Subject:" << record.first << "\t"
                        << "Score:" << static_cast<int>(record.second) << endl;
            }
        }
    }

    outfile.close();
}