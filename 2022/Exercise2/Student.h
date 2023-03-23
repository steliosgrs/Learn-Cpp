#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
/* Header file
    - Class Attributes
    - Functions Prototypes*/

class Student{

private:
// Στοιχεία φοιτητή
    char * AM;
    string name;
    unsigned int semester;

public:
// Constructors
    Student(const char *, string);
    Student(const char *, string,unsigned int);
    Student(const Student&);


// Destructor
    ~Student();

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