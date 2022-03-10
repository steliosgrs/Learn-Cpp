#include <iostream>
#include <stdio.h>

using namespace std;

struct Person
{
    int id;
    string Name;
    string Last;
    float height;
};

// Prototypes
Person * initPeople(int);
Person &change_name(Person[]);

int main(int argc, char const *argv[])
{
    system("chcp 1253>nul");
    cout << "1ο ζητούμενο: αλλάγη τιμής σε const double " << endl ;
    // Δήλωση const double και ενός Pointer που δείχνει σε double
    const double num = 2.2;
    double *point;

    point = (double *)&num; // To casting είναι απαραίτητο 
                          // double με το const double είναι διαφορετικός τύπος δεδομένων.

    // Αλλαγή της τιμής κάνοντας χρήση του Pointer
    *point = 90.2;

    cout << num << " " << *point << endl;


    cout << "2ο ζητούμενο: χρήση τελεστών new,new[],delete και delete[] " << endl ;
    // new & delete
    int *year;
    year = new int;
    *year = 2022;
    cout << "To year = " << *year << endl;
    delete year;

    // new[] & delete[]
    int p;
    cout << "Πόσες θέσεις να δεσμέσω;" << endl ;
    cin >> p;
    Person *person = initPeople(p);
    delete[] person; 


    cout << "3ο ζητούμενο: χρήση της αναφοράς στις παραμέτρους και τον τύπο επιστροφής των συναρτήσεων" << endl ;

    cout << "4ο ζητούμενο: υπερφόρτωση συνάρτησης και οι συναρτήσεις με παραμέτρους οι οποίες έχουν default τιμές" << endl ;

    return 0;
}

Person *initPeople(int p){
    string fname,lname;
    float height;
    // Δυναμική δεύμεση πίνακα p θέσεων
    Person *temp = new Person[p];
    // Δημιουργία αντικειμένων Person από τον χρήστη
    for (int i = 0; i < p; i++){
        cout << i+1 <<"ος Person" << endl;
        temp[i].id = i;
        cout <<"Όνομα: " << endl;
        cin >> fname;
        temp[i].Name  = fname;
        cout <<"Επώνυμο: " << endl;
        cin >> lname;
        temp[i].Last = lname;
        cout <<"Ύψος: " << endl;
        cin >> height;
        temp[i].height = height;
    }
    return temp;
}
