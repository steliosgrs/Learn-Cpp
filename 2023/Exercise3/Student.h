#ifndef STUDENT_H
#define STUDENT_H
// #include <vector>
// #include <string>
#include <stdio.h>
#include "Course.h"
/* Header file
    - Class Attributes
    - Functions Prototypes*/

class Student{

private:
// Στοιχεία φοιτητή
    char * AM;
    std::string name;
    unsigned int semester;
    std::vector<std::pair<Course, float>> Courses;

public:
// Constructors
    Student(const char *, std::string);
    Student(const char *, std::string, unsigned int);
    Student(const Student&);
    Student &operator=(const Student &);

// Destructor
    ~Student();

// ======Setters Getters Μέθsοδοι======

    // Setters
    void setAM(const char *);
    void setName(const std::string);
    void setSemester(const unsigned int);

    // Getters
    char* getAM();
    std::string getName();
    unsigned int getSemester();
    
    // Μέθοδοι
    void next_semester();
    void operator++ (int);
    void operator+= (unsigned int);
    void operator-= (unsigned int);
};



#endif // STUDENT_H