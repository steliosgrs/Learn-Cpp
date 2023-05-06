#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <new>

using namespace std;

class Student{

private:
// Στοιχεία φοιτητή
    char * AM;
    string name;
    unsigned int semester;

public:
// Constructors
    Student(const char *, string);
    Student(const char *, string, unsigned int);
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
    void operator++ (int);
    void operator+= (unsigned int);
    void operator-= (unsigned int);

};
// Overload for <<
ostream& operator<< (ostream &,  Student&);

// Constructors
Student::Student(const char *AM, string name){
    cout << " Δημιουργία Φοιτητή" << endl;
    int size;
    size = strlen(AM);
    this->AM = new char[size+1];
    strcpy(this->AM,AM);
    this->name = name;
    semester = 1;
}

Student::Student(const char *AM, string name, unsigned int semester){
    cout << " Δημιουργία Φοιτητή με εξάμηνο" << endl;
    int size;
    size = strlen(AM);
    this->AM = new char[size+1];
    strcpy(this->AM,AM);
    this->name = name;
    this->semester = semester;
}

Student::Student(const Student &s){
    cout << "Copy Constructor" <<endl;
    this->AM = new char[strlen(s.AM)+1];
    strcpy(this->AM,s.AM);
    this->name = s.name;
    this->semester = s.semester;
}

// Destructor
Student::~Student(){
    cout << " Καταστροφή Φοιτητή " << this->name << endl;
    delete[] this->AM;
}

// Setters
void Student::setAM(const char *AM) {
    delete[] this->AM;
    int size = strlen(AM);
    this->AM = new char[size+1];
    strcpy(this->AM,AM);
}

void Student::setName(const string name){
    this->name = name;
}

void Student::setSemester(const unsigned int semester){
    this->semester = semester;
}

//Getters
char* Student::getAM(){
    return this->AM;
}

string Student::getName(){
    return this->name;
}

unsigned int Student::getSemester(){
    return this->semester;
}

//Εμφάνιση των στοιχείων του φοιτητή
ostream& operator<<(ostream &output, Student& student){
    output << student.getAM() << ", " << student.getName() << ", " << student.getSemester() << endl;
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

/* Στέλιος Γεωργαράς ΑΜ:45354 ΠΑΔΑ*/

int main(int argc, char const *argv[]) {
    //system ("chcp 1253");

    // Constructor Μόνο το ΑΜ και το Ονοματεπώνυμο
    Student ste("cse45354","Στέλιος Γεωργαράς");
    cout << ste;
    cout <<endl;

    // Constructor για όλα τα χαρακτηριστικά
    Student kiri("kiri12345","Κυριάκος Παπαδόπουλος", 4);
    cout << kiri;
    cout << endl;

    // Αύξηση εξαμήνου
    kiri++;
    cout << "Αύξηση εξαμήνου" << endl;
    cout << kiri;
    cout << endl;

    // Copy Constructor 
    Student test(kiri);
    cout << "Υπερφόρτωση Τελεστή +=" << endl;
    test+=5;
    cout<<test;

    cout << "Υπερφόρτωση Τελεστή -=" << endl;
    test-=5;
    cout<<test;
    cout << endl;
    return 0;
}
