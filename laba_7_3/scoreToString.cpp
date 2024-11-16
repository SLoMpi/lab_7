//
// Created by Влад Ходоровский on 16.11.2024.
//
#include "header.h"
#include <string>

std::string scoreToString(Score score) {
    switch (score) {
        case Unsatisfactorily:
            return "Unsatisfactorily";
        case Satisfactorily:
            return "Satisfactorily";
        case Good:
            return "Good";
        case Excellent:
            return "Excellent";
        default:
            return "Unknown";
    }
}