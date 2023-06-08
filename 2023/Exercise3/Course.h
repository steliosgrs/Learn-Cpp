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
    std::string code;
    std::string name;
    unsigned int hours;
    bool semester;
    // enum semester{Χειμερινό, Εαρινό};
        // enum semester{Xeimerino = "Χειμερινό",
        //             Earino = "Εαρινό"};

public:
// Constructors
    Course(const std::string, const std::string, unsigned int, bool);

// Destructor
    virtual ~Course();

// ======Setters Getters Μέθοδοι======

    // Setters
    void setCode(const std::string);
    void setName(const std::string);
    void setHours(const unsigned int);
    void setSemester(const bool);

    // Getters
    std::string getCode() const;
    std::string getName() const;
    unsigned int getHours() const;
    bool getSemester() const;
    
    // Μέθοδοι

};



#endif // STUDENT_H