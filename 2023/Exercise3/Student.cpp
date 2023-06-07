#include <iostream>
// #include <stdio.h>
#include <string.h>
#include <new>
#include "Student.h"

// Constructors
Student::Student(const char *am, std::string n){
    std::cout << " Δημιουργία Φοιτητή" << std::endl;
    int size;
    size = strlen(am);
    AM = new char[size+1];
    strcpy(AM,am);
    name = n;
    semester = 1;
}

Student::Student(const char *am, std::string n, unsigned int s){
    std::cout << " Δημιουργία Φοιτητή με εξάμηνο" << std::endl;
    int size;
    size = strlen(am);
    AM = new char[size+1];
    strcpy(AM,am);
    name = n;
    semester = s;
}

Student::Student(const Student &s){
    std::cout << "Copy Constructor" <<std::endl;
    AM = new char[strlen(s.AM)+1];
    strcpy(AM,s.AM);
    name = s.name;
    semester = s.semester;
}

// Destructor
Student::~Student(){
    std::cout << " Καταστροφή Φοιτητή" << std::endl;
    delete[] AM;
}

// Setters
void Student::setAM(const char *am) {
    delete[] AM;
    int size = strlen(am);
    AM = new char[size+1];
    strcpy(AM,am);
}

void Student::setName(const std::string n){
    name=n;
}

void Student::setSemester(const unsigned int s){
    semester = s;
}

//Getters
char* Student::getAM(){
    return AM;
}

std::string Student::getName(){
    return name;
}

unsigned int Student::getSemester(){
    return semester;
}

//Εμφάνιση των στοιχείων του φοιτητή
void Student::print_stud(std::ostream& os) { 
    os << "\tΑΜ:"<< AM <<std::endl;
    os << "\tΟνοματεπώνυμο: "<< name <<std::endl;
    os << "\tΕξάμηνο: "<< semester <<std::endl;
}

// Αύξηση του τρέχονοτος εξαμήνου
void Student::next_semester(){
    semester+=1;
}

