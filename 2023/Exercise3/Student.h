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
    // Exercise 3
    std::vector<std::pair<Course*, float>> courses;
    std::vector<std::pair<Course*, float>> pass_courses;

public:
// Constructors
    Student(const char *, std::string);
    Student(const char *, std::string, unsigned int);
    Student(const Student&);

    // Exercise 3
    Student(const char *, std::string, unsigned int, std::vector<std::pair<Course*, float>> );
    Student &operator=(const Student &);

// Destructor
    ~Student();

// ======Setters Getters Μέθοδοι======

    // Setters
    void setAM(const char *);
    void setName(const std::string);
    void setSemester(const unsigned int);

    // Getters
    char* getAM();
    std::string getName();
    unsigned int getSemester();
    
    // Μέθοδοι
    // Semester Operations - Exercise 2
    void next_semester();
    void operator++ (int);
    void operator+= (unsigned int);
    void operator-= (unsigned int);

    // Semester Operations - Exercise 3
    bool operator==(const Student & );
    bool operator!=(const Student & );
    bool operator<(const Student & );
    bool operator<=(const Student & );
    bool operator>(const Student & );
    bool operator>=(const Student & );

    // Overload +=
    void operator+=(const std::pair<Course*, float> &);
};



#endif // STUDENT_H