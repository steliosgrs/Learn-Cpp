#ifndef _COURSE_H_
#define _COURSE_H_

/* Header file
    - Class Attributes
    - Functions Prototypes*/

class Course{

private:
// Στοιχεία φοιτητή
    char * AM;
    string name;
    unsigned int semester;

public:
// Constructors
    Course(const char *, string);
    Course(const char *, string, unsigned int);
    Course(const Course&);

// Destructor
    ~Course();

// ======Setters Getters Μέθsοδοι======

    // Setters
    void setAM(const char *);
    void setName(const string);
    void setSemester(const unsigned int);

    // Getters
    char* getAM();
    string getName();
    unsigned int getSemester();
    
    // Μέθοδοι
    void next_semester();
    // void print_stud  () const;
    void print_stud(ostream &);

};



#endif // STUDENT_H