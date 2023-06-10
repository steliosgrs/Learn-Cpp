#include <iostream>
#include <string.h>
#include <new>
#include "Student.h"

// Constructors
Student::Student(const char *AM, std::string name){
    // std::cout << " Δημιουργία Φοιτητή" << std::endl;
    int size;
    size = strlen(AM);
    this->AM = new char[size+1];
    strcpy(this->AM,AM);
    this->name = name;
    semester = 1;
}

Student::Student(const char *AM, std::string name, unsigned int semester){
    // std::cout << " Δημιουργία Φοιτητή" << std::endl;
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
    std::cout << "Καταστροφή Φοιτητή " << this->name << std::endl;
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
char* Student::getAM() const{
    return this->AM;
}

std::string Student::getName() const{
    return this->name;
}

unsigned int Student::getSemester() const{
    return this->semester;
}

const std::vector<Course*> &Student::getCourses() const{
    return this->courses;
}
std::vector<std::pair<Course*, float>> &Student::getPassedCourses(){
    return this->passed_courses;

}

//Εμφάνιση των στοιχείων του φοιτητή
std::ostream& operator<<(std::ostream &output, Student& student){
    float sum = 0;
    int counter = 0 ;
    output << student.getAM() << ", " << student.getName() << ", " << student.getSemester() << std::endl;
    for (size_t i = 0; i < student.getPassedCourses().size(); i++){
        std::cout << student.getPassedCourses()[i].first->getName() << " ";
        std::cout << student.getPassedCourses()[i].second << std::endl;
        sum+=student.getPassedCourses()[i].second;
        counter+=1;
    }
    output << "Μέσος Όρος: " << float(sum / counter)<< std::endl;
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
Student& Student::operator+=(Course &course){
    courses.push_back(&course);
    return *this;
}

// Exercise 3 Overload =
Student& Student::operator=(const Student &s){
    // Έλεγχος για το εάν ο τελεστής = γίνεται σε ένα
    // αντικείμενο με τον ίδιο του τον εαυτό.
    if (this == &s){
        return *this; // Θεωρώ ότι έχει γίνει η εκχώρηση, επιστρέφω τον εαυτό του
    }
    delete []AM;
    this->AM = new char[strlen(s.AM)+1];
    strcpy(this->AM,s.AM);
    this->name = s.name;
    this->semester = s.semester;
    courses = s.courses;
    passed_courses = s.passed_courses;
    return *this; // S1 = S2 = S3 
}

// Semester Operations - Exercise 3
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

// Write to csv file
void Student::writeCSV(const std::string row){
    std::ofstream file(row + ".csv");
    if (file.is_open()){
        file << "Code," << "Name" << ",";
        file << "Hours" << "," << "Semester" << ",Grade"<<std::endl;
        for (size_t i = 0; i < this->getPassedCourses().size(); i++){
            file << this->getPassedCourses()[i].first->getCode() << ",";
            file << this->getPassedCourses()[i].first->getName() << ",";
            file << this->getPassedCourses()[i].first->getHours() << ",";
            if (this->getPassedCourses()[i].first->getSemester()){
                file << "Εαρινό" << ",";
            }
            else{
                file << "Χειμερινό" << ",";
            }
            file << this->getPassedCourses()[i].second << std::endl;
        }
        for (size_t i = 0; i < this->getCourses().size(); i++){
            file << this->getCourses()[i]->getCode() << ",";
            file << this->getCourses()[i]->getName() << ",";
            file << this->getCourses()[i]->getHours() << ",";
            if (this->getCourses()[i]->getSemester()){
                file << "Εαρινό" << ",";
            }
            else{
                file << "Χειμερινό" << ",";
            }
            file << " "<< std::endl; // Δεν υπάρχει βαθμός για τα δηλωμένα μαθήματα
        }
    }
    file.close();

}
