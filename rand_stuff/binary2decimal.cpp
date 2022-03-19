#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[]) {

    cout << "\t~~~Decimal to Binary~~~" << "\n\n";
    cout << "Enter a Decimal number: " ;

    int x,num,remainder,binary_num=0;
    cin >> x ;
    num = x;
    int mul=1;
    do {
        remainder = num%2;
        num = num/2;
        //cout << num << "\n"; // Verification
        binary_num = (remainder*mul) + binary_num;
        cout << binary_num <<endl;
        mul*=10;
    } while(num!=0);
    cout << "The number " << x << " in binary is " << binary_num;

    return 0;
}
