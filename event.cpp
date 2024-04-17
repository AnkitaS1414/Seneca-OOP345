/***********************************************************************
// OOP345 Workshop #1 lab
//
// File  event.cpp
// Name- -Ankita
// Email- ankita8@myseneca.ca
// Student ID- 169726213
// Date- 29/01/2024

// Citation:

//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace seneca {

    // Global variable representing the system clock
    unsigned int g_sysClock = 0;

    // Default constructor
    Event::Event() : description(nullptr), startTime(0) {}

    // Copy constructor
    Event::Event(const Event& other) : description(nullptr), startTime(other.startTime) {
        if (other.description != nullptr) {
            description = new char[std::strlen(other.description) + 1];
            std::strcpy(description, other.description);
        }
    }

    // Copy assignment operator
    Event& Event::operator=(const Event& other) {
        if (this != &other) { // Avoid self-assignment
            startTime = other.startTime;

            // Deallocate existing memory
            delete[] description;

            // Allocate new memory and copy the description
            if (other.description != nullptr) {
                description = new char[std::strlen(other.description) + 1];
                std::strcpy(description, other.description);
            }
            else {
                description = nullptr;
            }
        }
        return *this;
    }

    // Destructor
    Event::~Event() {
        delete[] description;
    }

    // Display function
    void Event::display() const {
        static int counter = 1; // Local counter variable
        std::cout << std::setfill(' ') << std::setw(2) << counter << ". ";

        if (description != nullptr && description[0] != '\0') {
            // Calculate hours, minutes, and seconds from startTime
            unsigned int hours = startTime / 3600;
            unsigned int minutes = (startTime % 3600) / 60;
            unsigned int seconds = startTime % 60;


            std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                << std::setw(2) << minutes << ":" << std::setw(2) << seconds
                << " => " << description;
        }
        else {
            std::cout << "| No Event |";
        }

        std::cout << std::endl;
        counter++;
    }

    // Set function
    void Event::set(const char* desc) {
        delete[] description; // Release previously allocated memory

        if (desc != nullptr && desc[0] != '\0') {
            // Start a new event
            description = new char[std::strlen(desc) + 1];
            std::strcpy(description, desc);
            startTime = g_sysClock;
        }
        else {
            // Reset to an empty state
            description = nullptr;
            startTime = 0;
        }
    }

} // namespace seneca
