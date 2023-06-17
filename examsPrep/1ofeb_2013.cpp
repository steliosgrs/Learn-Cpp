#include <iostream>

using namespace std;

class B{
public:
    // virtual int ft(int i ){ cout << "int"; return 0;}
};

class D: public B{
public:
    int ft(int i) { cout << "int doubl"; return 0;}
    double ft(double i){cout << "double"; return 0.0;}
};

int main (){
    B *pB = new D;
    pB->ft(2.3);
    // system("PAUSE");
}
