#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include "Student.h"
using namespace std;

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
    kiri.next_semester();
    kiri.print_stud(cout);
    cout << endl;

    // Copy Constructor 
    Student test(kiri);
    // c.print_stud();
    test.print_stud(cout);
    cout << endl;
    return 0;
}
