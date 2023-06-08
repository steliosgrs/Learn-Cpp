#include <iostream>
// #include <stdio.h>
#include <string.h>
#include <new>
#include "Student.h"

// Constructors
Student::Student(const char *AM, std::string name){
    std::cout << " Δημιουργία Φοιτητή" << std::endl;
    int size;
    size = strlen(AM);
    this->AM = new char[size+1];
    strcpy(this->AM,AM);
    this->name = name;
    semester = 1;
}

Student::Student(const char *AM, std::string name, unsigned int semester){
    std::cout << " Δημιουργία Φοιτητή με εξάμηνο" << std::endl;
    int size;
    size = strlen(AM);
    this->AM = new char[size+1];
    strcpy(this->AM,AM);
    this->name = name;
    this->semester = semester;
}

Student::Student(const Student &s){
    std::cout << "Copy Constructor" <<std::endl;
    this->AM = new char[strlen(s.AM)+1];
    strcpy(this->AM,s.AM);
    this->name = s.name;
    this->semester = s.semester;
}


// Destructor
Student::~Student(){
    std::cout << " Καταστροφή Φοιτητή " << this->name << std::endl;
    delete[] this->AM;
}

// Setters
void Student::setAM(const char *AM) {
    delete[] this->AM;
    int size = strlen(AM);
    this->AM = new char[size+1];
    strcpy(this->AM,AM);
}

void Student::setName(const std::string name){
    this->name = name;
}

void Student::setSemester(const unsigned int semester){
    this->semester = semester;
}

//Getters
char* Student::getAM(){
    return this->AM;
}

std::string Student::getName(){
    return this->name;
}

unsigned int Student::getSemester(){
    return this->semester;
}

//Εμφάνιση των στοιχείων του φοιτητή
std::ostream& operator<<(std::ostream &output, Student& student){
    output << student.getAM() << ", " << student.getName() << ", " << student.getSemester() << std::endl;
    return output;
}
// Αύξηση του τρέχονοτος εξαμήνου
void Student ::operator++ (int){
    this->semester++;
}
void Student ::operator+= (unsigned int semester){
    this->semester+=semester;
}
void Student ::operator-= (unsigned int semester){
    this->semester-=semester;
}

// Exercise 3
void Student::operator+=(const std::pair<Course*, float> &course){
    this->courses.push_back(course);
}


Student& Student::operator=(const Student &s){
    std::cout << "Copy Constructor" <<std::endl;
    if (this->AM){
        delete [] this->AM;
    }
    this->AM = new char[strlen(s.AM)+1];
    strcpy(this->AM,s.AM);
    this->name = s.name;
    this->semester = s.semester;
    return *this;
}

bool Student::operator== (const Student &stud){
    return this->semester==stud.semester;
}
bool Student::operator!= (const Student &stud){
    return this->semester!=stud.semester;
}
bool Student::operator< (const Student &stud){
    return this->semester<stud.semester;
}
bool Student::operator<= (const Student &stud){
    return this->semester<=stud.semester;
}
bool Student::operator> (const Student &stud){
    return this->semester>stud.semester;
}
bool Student::operator>= (const Student &stud){
    return this->semester>=stud.semester;
}