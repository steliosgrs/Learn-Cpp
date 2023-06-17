#include <iostream>
using namespace std;

class  Mom{
public:
    Mom(){cout<<"Mom is here!"<<endl;}
    Mom(const Mom& a){cout<<"Like anothermom"<<endl;}
    virtual ~Mom(){cout<<"Mom is leaving!"<<endl;}
    virtual void foo(){cout<<"Mom cooking()"<<endl;}
    virtual Mom& operator=(const Mom& rhs){cout<<"Mom op="<<endl;}
};

class Child: public Mom{
    public:Child(){cout<<"Child is here!"<<endl;}
    virtual ~Child(){cout<<"Child is leaving"<<endl;}
    virtual void foo(){cout<<"Child playing"<<endl;}
protected:
    Mom mInstanceOfMom;
};

Mom foo(Mom& input){
    cout << "PRIN" << endl;
    input.foo();
    cout << "META" << endl;
    return input;
}
int main(){
    Child myChild;
    cout << "=================" << endl;
    Child myOtherChild;
    cout << "=================" << endl;
    Mom myMom;
    cout << "=================" << endl;
    myOtherChild = myChild;
    cout << "=================" << endl;
    myMom = foo(myOtherChild); // child.foo --> Copy Mom --> Mom op= --> Mom ~
    cout << "=================" << endl;
    }