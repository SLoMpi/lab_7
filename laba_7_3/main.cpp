#include "header.h"
#include <iostream>
using namespace std;


int main() {
    Groups groups;
    Student student1 = {"Vladislav Khodorovskiy", 1, {{"Math", Good}, {"Physics", Excellent}}};
    Student student2 = {"Danil Nestirenko", 1, {{"Math", Unsatisfactorily}, {"Physics", Good}}};
    Student student3 = {"Lev Nekrsov", 1, {{"Math", Excellent}, {"Physics", Unsatisfactorily}}};
    groups["Group 1"].push_back(student1);
    groups["Group 1"].push_back(student2);
    groups["Group 1"].push_back(student3);
    saveToFile("groups.txt", groups);
    Groups loadedGroups;
    loadFromFile("groups.txt", loadedGroups);
    for (const auto &group : loadedGroups) {
        cout << "Group Name: " << group.first << endl;
        for (const auto &student : group.second) {
            cout << "Student Name: " << student.Name << ", Year: " << student.Year << endl;
            for (const auto &record : student.RecordBook) {
                cout << "Subject: " << record.first << ", Score: " << scoreToString(record.second) << endl;
            }
            cout << endl;
        }
    }

    return 0;
}