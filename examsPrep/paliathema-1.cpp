#include <iostream>
using namespace std;
class A
{
public:
    A() {cout << "A ctor" << endl;}
    A(const A& a) {cout << "A copy ctor" << endl; }
    virtual ~A() {cout << "A dector" << endl;}
    virtual void foo() {cout << "A foo()" << endl;}
    virtual A& operator=(const A& rhs) {cout << "A op=" << endl;}
};

class B : public A
{
public:
    B() {cout << "B ctor" << endl;}
    virtual ~B() {cout << "B dector" << endl;}
    virtual void foo() {cout << "B foo()" << endl;}
protected:
    A mInstanceofA;
};

A foo(A& input){
    cout << "PRIN" << endl;
    input.foo();
    cout << "META" << endl;
    return input;
}

int main(){
    B myB; // A - > A -> B
    cout << "=================" << endl;
    B myOtherB; // A - > A -> B
    cout << "=================" << endl;
    A myA; // A
    cout << "=================" << endl;
    myOtherB = myB; // A op= -> // A op= 
    cout << "=================" << endl;
    myA = foo(myOtherB); // B foo() -> A copy ctor -> A op= 
    cout << "=================" << endl;

}