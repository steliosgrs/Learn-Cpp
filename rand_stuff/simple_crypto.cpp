#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]) {

    int num1,num2;
    cout << "Enter 2 numbers" << '\n';
    cout << "First number: ";
    cin >> num1;
    cout << "\nSecond number :";
    cin >> num2;
    num1 = num1^num2;
    //num2 = num1^num2;
    //num1 = num1^num2;

    cout << "\nEncrypted First number: " << num1 << endl;
    num1 = num1^num2;
    cout << "\nOriginal First number: " << num1 << endl;
    return 0;
}
