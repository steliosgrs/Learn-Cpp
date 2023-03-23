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

    // Constructor 1
    Student a("cse45354","Στέλιος Γεωργαράς");
    // a.print_stud();
    a.print_stud(cout);
    cout <<endl;

    // Constructor 2
    Student b("cse12345","Νίκος Γεωργίου",16);
    // b.print_stud();
    b.print_stud(cout);
    cout << endl;
    // Αύξηση εξαμήνου
    b.next_semester();
    b.print_stud(cout);
    cout << endl;

    // // Constructor 4
    Student c(b);
    // c.print_stud();
    c.print_stud(cout);
    cout << endl;
    return 0;
}
