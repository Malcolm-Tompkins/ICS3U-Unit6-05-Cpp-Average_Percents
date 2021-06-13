// Copyright (c) 2021 Malcolm Tompkins All rights reserved
//
// Created by Malcolm Tompkins
// Created on June 13, 2021
// Calculates the average of percent marks

#include <iostream>
#include <string>
#include <list>
#include <numeric>


double average_of_percents(std::list<int> marks_list) {
    // Function that calculates the average
    double sum_of_marks;
    sum_of_marks = std::accumulate(std::begin(marks_list),
    std::end(marks_list), 0.0);
    return sum_of_marks / marks_list.size();
}

main() {
    // Function for input and output
    int temp_mark;
    double final_average;
    std::list<int> marks_list;
    std::string user_mark;
    std::cout << "Enter your numbers 1 at a time, enter -1 to stop";
    std::cout << "\nEnter your number in percent: ";
    std::cin >> user_mark;
    try {
        temp_mark = std::stoi(user_mark);
        marks_list.push_back(temp_mark);
        while (temp_mark != -1) {
            std::cout << "Enter your number in percent: ";
            std::cin >> user_mark;
            try {
                temp_mark = std::stoi(user_mark);
                if (temp_mark != -1) {
                    marks_list.push_back(temp_mark);
                } else {
                    break;
                }
            }catch (std::invalid_argument) {
                std::cout << user_mark;
                std::cout << " is not a postive integer\n";
                break;
            }
        }
    } catch (std::invalid_argument) {
        std::cout << user_mark;
        std::cout << " is not a postive integer\n";
    }
    final_average = average_of_percents(marks_list);
    std::cout << "The average of your marks is: ";
    std::cout << final_average << "%";
    std::cout << "\nDone.";
}
