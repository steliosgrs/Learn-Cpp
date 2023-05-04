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
    // void print_stud  () const;
    void print_stud(ostream &);
    void operator++ (int);
    void operator+= (int);
    void operator-= (int);

};

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

Student::Student(const char *am, string n, unsigned int s){
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
    cout << " Καταστροφή Φοιτητή " << this->name << endl;
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
    os << "ΑΜ:"<< AM <<endl;
    os << "Ονοματεπώνυμο: "<< name <<endl;
    os << "Εξάμηνο: "<< semester <<endl;
}

// Αύξηση του τρέχονοτος εξαμήνου
void Student ::operator++ (int){
    this->semester++;
}
void Student ::operator+= (int s){
    semester+=s;
}
void Student ::operator-= (int s){
    semester-=s;
}

// void operator++ (Student&){
//     // this->semester++;
// }

/* Στέλιος Γεωργαράς ΑΜ:45354 ΠΑΔΑ*/

int main(int argc, char const *argv[]) {
    //system ("chcp 1253");

    // Constructor Μόνο το ΑΜ και το Ονοματεπώνυμο
    Student ste("cse45354","Στέλιος Γεωργαράς");
    // ste.print_stud();
    ste.print_stud(cout);
    cout <<endl;

    // Constructor για όλα τα χαρακτηριστικά
    Student kiri("kiri12345","Κυριάκος Παπαδόπουλος", 4);
    // kiri.print_stud();
    kiri.print_stud(cout);
    cout << endl;
    // Αύξηση εξαμήνου
    // kiri.next_semester();
    kiri++;
    kiri.print_stud(cout);
    cout << endl;

    // Copy Constructor 
    Student test(kiri);
    // c.print_stud();
    test+=5;
    test.print_stud(cout);
    test-=5;
    test.print_stud(cout);
    cout << endl;
    return 0;
}
