#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include "Student.h"

using namespace std;

// Constructors
Student::Student(const char *am, string n){
    cout << " Δημιουργία Φοιτητή" << endl;
    int size;
    size = strlen(am);
    AM = new char[size+1];
    strcpy(AM,am);
    name = n;
    semester = 1;
}

Student::Student(const char *am, string n,unsigned int s){
    cout << " Δημιουργία Φοιτητή με εξάμηνο" << endl;
    int size;
    size = strlen(am);
    AM = new char[size+1];
    strcpy(AM,am);
    name = n;
    semester = s;
}

Student::Student(const Student &s){
    cout << "Copy Constructor" <<endl;
    AM = new char[strlen(s.AM)+1];
    strcpy(AM,s.AM);
    name = s.name;
    semester = s.semester;
}

// Destructor
Student::~Student(){
    cout << " Καταστροφή Φοιτητή" << endl;
    delete[] AM;
}

// Setters
void Student::setAM(const char *am) {
    delete[] AM;
    int size = strlen(am);
    AM = new char[size+1];
    strcpy(AM,am);
}

void Student::setName(const string n){
    name=n;
}

void Student::setSemester(const unsigned int s){
    semester = s;
}

//Getters
char* Student::getAM(){
    return AM;
}

string Student::getName(){
    return name;
}

unsigned int Student::getSemester(){
    return semester;
}



//Εμφάνιση των στοιχείων του φοιτητή
void Student::print_stud(ostream& os) { 
    os << "\tΑΜ:"<< AM <<endl;
    os << "\tΟνοματεπώνυμο: "<< name <<endl;
    os << "\tΕξάμηνο: "<< semester <<endl;
}

// Αύξηση του τρέχονοτος εξαμήνου
void Student::next_semester(){
    semester+=1;
}