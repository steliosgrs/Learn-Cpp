#include <iostream>
#include <new>
#include "Student.h"

/* Στέλιος Γεωργαράς ΑΜ:45354 ΠΑΔΑ*/

// Overload for <<
std::ostream& operator<< (std::ostream &,  Student&);

int main(int argc, char const *argv[]) {
    // system ("chcp 1253");

    // Constructor Φοιτητών
    Student stelios("cse45354","Στέλιος Γεωργαράς", 4);
    Student kiri("kiri12345","Κυριάκος Παπαδόπουλος", 5);

    // Constructor Μαθημάτων
    Course c("c0", "C", 4, true);
    Course cpp("c1", "C++", 4, true);
    Course java("c2", "Java", 5, false);
    Course algebra("c3", "Άλγεβρα", 5, false);
    Course ls("c4", "Λειτουργικά Συστήματα", 6, true);

    // Υπερφόρτωση Τελεστή +=
    stelios+=c;
    stelios+=cpp;
    std::cout << "Υπερφόρτωση Τελεστή += Προσκήθηκη δηλωμένων μαθημάτων ";
    for (size_t i = 0; i < stelios.getCourses().size(); i++){
        std::cout << stelios.getCourses()[i]->getName() << " ";
    }
    std::cout << std::endl <<std::endl;
    
    srand(time(NULL));
    // Δημιουργία Περασμένων μαθημάτων
    for (size_t i = 0; i < stelios.getCourses().size(); i++){
        float grade;
        do {
            grade = float(rand() % 10);
        } while(grade <= 5);
        stelios.getPassedCourses().push_back(std::make_pair(stelios.getCourses()[i],grade));
    }

    // Υπερφόρτωση Τελεστή =
    std::cout << "Υπερφόρτωση Τελεστή = Εκχώρηση Κλάση Φοιτητής" << std::endl;
    Student marios("cse123","Μάριος",5);
    marios = stelios;
    Course * j = &java;
    marios.getPassedCourses().push_back(std::make_pair(j,float(8.0)));
    std::cout << marios;
    std::cout << std::endl <<std::endl;

    // Υπερφόρτωση Τελεστών ==, !=, <, <=, >, >=
    if (stelios == kiri){
    std::cout << "Είναι το ίδιο εξάμηνο" <<std::endl;
    }
    if (stelios != kiri){
    std::cout << "Είναι διαφορετικό εξάμηνο" <<std::endl;
    }
    if (stelios < kiri){
    std::cout << "Είναι μικρότερο εξάμηνο" <<std::endl;
    }
    if (stelios <= kiri){
    std::cout << "Είναι μικρότερο ή ίσο εξάμηνο" <<std::endl;
    }
    if (stelios > kiri){
    std::cout << "Είναι μεγαλύτερο εξάμηνο" <<std::endl;
    }
    if (stelios >= kiri){
    std::cout << "Είναι μεγαλύτερο ή ίσο εξάμηνο" <<std::endl;
    }
    std::cout << std::endl <<std::endl;

    // Υπερφόρτωση Τελεστή << για τα δηλωμένα μαθήματα
    std::cout << stelios; 


    stelios.writeCSV("Στέλιος");
    marios+=ls;
    marios+=algebra;
    marios.writeCSV("Μάριος");


    return 0;
}
