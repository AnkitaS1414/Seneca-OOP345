/***********************************************************************
// OOP345 Workshop #1 lab
//
// File  event.h
// Name- -Ankita
// Email- ankita8@myseneca.ca
// Student ID- 169726213
// Date- 29/01/2024

// Citation:

//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/


#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

namespace seneca {

    // Global variable representing the system clock
    extern unsigned int g_sysClock;

    class Event {
        char* description;     // Dynamic C-style string
        unsigned int startTime; // time when the event starts (in seconds)

    public:
        // Default constructor
        Event();

        // Copy constructor
        Event(const Event& other);

        // Copy assignment operator
        Event& operator=(const Event& other);

        // Destructor
        ~Event();

        // Display function
        void display() const;

        // Set function
        void set(const char* desc = nullptr);
    };

} // namespace seneca

#endif // SENECA_EVENT_H
