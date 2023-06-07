#ifndef _COURSE_H_
#define _COURSE_H_
#include <vector>
#include <string>
/* Header file
    - Class Attributes
    - Functions Prototypes*/

class Course{

private:
// Στοιχεία μαθήματος
    char * AM;
    std::string name;
    unsigned int semester;

public:
// Constructors
    Course(const char *, std::string);
    Course(const char *, std::string, unsigned int);
    Course(const Course&);

// Destructor
    ~Course();

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
    // void print_stud  () const;
    void print_stud(std::ostream &);

};



#endif // STUDENT_H