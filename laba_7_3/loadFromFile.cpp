//
// Created by Влад Ходоровский on 16.11.2024.
//


#include "header.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

using namespace std;

void loadFromFile(const string& filename, Groups& outGroups) {
    ifstream infile(filename);
    if (!infile) {
        throw runtime_error("Cannot open file for reading: " + filename);
    }

    outGroups.clear();

    size_t numGroups;
    infile >> numGroups;
    infile.ignore(numeric_limits<streamsize>::max(), '\n');

    for (size_t i = 0; i < numGroups; ++i) {
        string line;

        getline(infile, line);
        size_t posGroupName = line.find("GroupName:");
        if (posGroupName == string::npos) {
            throw runtime_error("Invalid format: GroupName not found");
        }
        string groupName = line.substr(posGroupName + 10);

        getline(infile, line);
        size_t posNumStudents = line.find("NumStudents:");
        if (posNumStudents == string::npos) {
            throw runtime_error("Invalid format: NumStudents not found");
        }
        size_t numStudents = stoi(line.substr(posNumStudents + 12));

        vector<Student> students;
        for (size_t j = 0; j < numStudents; ++j) {
            Student student;

            getline(infile, line);
            size_t posStudentName = line.find("StudentName:");
            size_t posYear = line.find("\tYear:");
            if (posStudentName == string::npos || posYear == string::npos) {
                throw runtime_error("Invalid format: StudentName or Year not found");
            }
            student.Name = line.substr(posStudentName + 12, posYear - (posStudentName + 12));
            student.Year = stoi(line.substr(posYear + 6));

            getline(infile, line);
            size_t posNumRecords = line.find("NumRecords:");
            if (posNumRecords == string::npos) {
                throw runtime_error("Invalid format: NumRecords not found");
            }
            size_t numRecords = stoi(line.substr(posNumRecords + 11));

            for (size_t k = 0; k < numRecords; ++k) {
                getline(infile, line);
                size_t posSubject = line.find("Subject:");
                size_t posScore = line.find("\tScore:");
                if (posSubject == string::npos || posScore == string::npos) {
                    throw runtime_error("Invalid format: Subject or Score not found");
                }
                string subject = line.substr(posSubject + 8, posScore - (posSubject + 8));
                int scoreValue = stoi(line.substr(posScore + 7));
                Score score = static_cast<Score>(scoreValue);

                student.RecordBook[subject] = score;
            }

            students.push_back(student);
        }

        outGroups[groupName] = students;
    }

    infile.close();
}