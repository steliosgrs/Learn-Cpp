#include <iostream>
#include <stdio.h>

using namespace std;

struct Person
{
    int id;
    std::string Name;
    std::string Last;
    float height;
};

// Prototypes
Person * initPeople(int);
Person &change_name(Person[]);
void multiply(double &,double &, double &);
double perimeter(double, double, double w=4.8, double z = 5.9);

int main(int argc, char const *argv[])
{
    system("chcp 65001>nul");
    cout << "\n1ο ζητούμενο: αλλάγη τιμής σε const double " << endl ;
    // Δήλωση const double και ενός Pointer που δείχνει σε double
    const double num = 2.2;
    double *point;

    point = (double *)&num; // To casting είναι απαραίτητο
                          // double με το const double είναι διαφορετικός τύπος δεδομένων.

    // Αλλαγή της τιμής κάνοντας χρήση του Pointer
    *point = 90.2;

    cout << "Num =" << num << endl;
    cout << "*point = " << *point << endl;


    cout << "\n2ο ζητούμενο: χρήση τελεστών new,new[],delete και delete[] " << endl ;
    // new & delete
    int *year;
    year = new int;
    *year = 2022;
    cout << "To year = " << *year << endl;
    delete year;

    // new[] & delete[]
    int p;
    cout << "\nΠόσα αντικείμενα Person να δημιουργηθούν; " << endl ;
    cin >> p;
    Person *person = initPeople(p);
    delete[] person;


    cout << "\n3ο ζητούμενο: χρήση της αναφοράς στις παραμέτρους" << endl ;

    // Χρήση αναφοράς στις παραμέτρους
    cout << "\nΠολλαπλασιασμός 2 αριθμών" << endl;
    double num1,num2,res;
    cout << "Δώσε 1ο αριθμό: ";
    cin >> num1;
    cout << "\nΔώσε 2ο αριθμό: ";
    cin >> num2;
    multiply(num1,num2,res);
    cout << "Αποτέλεσμα:" << res << endl;

    cout << "\n3ο ζητούμενο: Επιστροφή αναφοράς " << endl ;
    // Επιστροφή αναφοράς
    Person *me = new Person [1];
    me[0].id = 11111;
    me[0].Name = "Στέλιος";
    me[0].Last = "Γεωργαράς";
    me[0].height = 1.67;
    cout << "Αρχικό όνομα: " << me[0].Last << " " << me[0].Name << endl;
    Person &s = change_name(me);
    s.Name = "NO";
    s.Last = "NAME";
    cout << "Τροποποιημένο όνομα: " << me[0].Name << " " << me[0].Last << endl;
    delete[] me;

    cout << "\n4ο ζητούμενο: υπερφόρτωση συνάρτησης και οι συναρτήσεις με παραμέτρους οι οποίες έχουν default τιμές" << endl ;

    double result;
    cout << "\nΥπολογισμός περιμέτρου" << endl;
    result = perimeter(2.2,3.2,2.3,4.2);
    cout << "Η περίμετρος με 4 τιμές και καθόλου default τιμές είναι " << result << endl;
    result = perimeter(2.2,3.2,2.3);
    cout << "Η περίμετρος με 3 τιμές και 1 default τιμές είναι\t" << result << endl;
    result = perimeter(2.2,3.2);
    cout << "Η περίμετρος με 2 τιμές και 2 default τιμές είναι\t" << result << endl;
    
    return 0;
}

// Συνάρτηση για την αρχικοποίηση του αντικειμένου Person
Person *initPeople(int p){
    string fname,lname;
    float height;
    // Δυναμική δεύμεση πίνακα p θέσεων
    Person *temp = new Person[p];
    // Δημιουργία αντικειμένων Person από τον χρήστη
    for (int i = 0; i < p; i++){
        cout << "Person " << i+1 << endl ;
        temp[i].id = i;
        cout <<"Όνομα: ";
        cin >> fname;
        temp[i].Name  = fname;
        cout <<"Επώνυμο: ";
        cin >> lname;
        temp[i].Last = lname;
        cout <<"Ύψος: ";
        cin >> height;
        temp[i].height = height;
        cout << "===Δημιουργήθηκε==="<<endl;
        cout << "Όνοματεπώνυμο: " << temp[i].Name <<" "<< temp[i].Last<<endl;
        cout << "Ύψος: "<<temp[i].height<<endl;
    }
    return temp;
}

// Για Ζητούμενο 3
// Συνάρτηση πολλαπλασιασμού κάνοντας χρήση αναφορών στις παραμέτρους
void multiply(double &num1, double &num2, double &res){
    res = num1 * num2;
}
// Επιστροφή αναφοράς
Person &change_name(Person per[]){
    return per[0];
}

// Για Ζητούμενο 4
// Συνάρτηση υπολογισμός περιμέτρου
double perimeter(double x, double y, double w, double z){
    double res = x + y + w + z;
    return res;
}