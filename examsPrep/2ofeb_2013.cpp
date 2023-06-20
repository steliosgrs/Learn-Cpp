#include <iostream>
using namespace std;

class A{
public:
    A(){cout << "A" << endl;};
    ~A(){cout << "~A"<< endl;};
};

class B{
public:
    B(){cout << "B" << endl;};
    ~B(){cout << "~B"<< endl;};
private:
    A a;
};

class C{
public:
    C(){cout << "C" << endl;};
    ~C(){cout << "~C"<< endl;};
private:
    A a;
    B b;
};

class D{
public:
    D(){cout << "D" << endl;};
    ~D(){cout << "~D"<< endl;};
private:
    A a;
    C c;
};

class E : public C{
public:
    E(){cout << "E" << endl;};
    ~E(){cout << "~E"<< endl;};
private:
    A a;
    C c;
    D d;
};


int main (){
    E e;

    cout << endl;

    // C c;

    return 0;
}