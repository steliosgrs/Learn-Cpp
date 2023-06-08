#include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <string>
#include <new>
#include "Student.h"

/* Στέλιος Γεωργαράς ΑΜ:45354 ΠΑΔΑ*/

// Overload for <<
std::ostream& operator<< (std::ostream &,  Student&);

int main(int argc, char const *argv[]) {
    //system ("chcp 1253");

    // Constructor Μόνο το ΑΜ και το Ονοματεπώνυμο
    Student ste("cse45354","Στέλιος Γεωργαράς");
    std::cout << ste;
    std::cout <<std::endl;

    // Constructor για όλα τα χαρακτηριστικά
    Student kiri("kiri12345","Κυριάκος Παπαδόπουλος", 4);
    std::cout << kiri;
    std::cout << std::endl;

    // Αύξηση εξαμήνου
    kiri++;
    std::cout << "Αύξηση εξαμήνου" << std::endl;
    std::cout << kiri;
    std::cout << std::endl;

    // Copy Constructor 
    Student test(kiri);
    std::cout << "Υπερφόρτωση Τελεστή +=" << std::endl;
    test+=5;
    std::cout<<test;

    std::cout << "Υπερφόρτωση Τελεστή -=" << std::endl;
    test-=5;
    std::cout<<test;
    std::cout << std::endl;
    return 0;
}
