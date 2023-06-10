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

    // Constructor Φοιτητών
    Student stelios("cse45354","Στέλιος Γεωργαράς", 4);
    Student kiri("kiri12345","Κυριάκος Παπαδόπουλος", 4);

    // Constructor Μαθημάτων
    Course cpp("c1", "C++", 4, true);
    Course java("c2", "Java", 5, false);
    Course algebra("c3", "Άλγεβρα", 5, false);
    Course ls("c4", "Λειτουργικά Συστήματα", 6, true);

    // Υπερφόρτωση Τελεστή +=
    stelios+=cpp;
    stelios+=java;
    std::cout << "Υπερφόρτωση Τελεστή += Προσκήθηκη δηλωμένων μαθημάτων ";
    for (const auto & course: stelios.getCourses()){
        std::cout << course->getName() << " ";
    }
    std::cout << std::endl <<std::endl;

    // Υπερφόρτωση Τελεστή =
    std::cout << "Υπερφόρτωση Τελεστή = Εκχώρηση Κλάση Φοιτητής" << std::endl;
    Student marios("mar45354","Μάριος", 6);
    marios = stelios;
    std::cout << marios;
    std::cout << std::endl <<std::endl;

    // Υπερφόρτωση Τελεστή +=
    // // Copy Constructor 
    // std::cout << "Υπερφόρτωση Τελεστή +=" << std::endl;
    // test+=5;
    // std::cout<<test;

    // std::cout << "Υπερφόρτωση Τελεστή -=" << std::endl;
    // test-=5;
    // std::cout<<test;
    // std::cout << std::endl;
    return 0;
}
