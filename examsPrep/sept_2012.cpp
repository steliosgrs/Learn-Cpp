#include<iostream>
using namespace std;

class A {
public:
	virtual  void h ( ) {  cout  <<   1  <<  endl;  }
};

class B: public A {
public:
	virtual void h ( ) {  cout  <<  2  <<  endl;  }
};

template <typename T>  class C  {
	T  x;
public:
	C  (T  y):  x(y)   {  x.h(  );  }
};

template   <typename  T>  class  D  {
	T  *x;
public:
	D  (T  *y) :  x(y)  {  x->h (  );  }
};

int main(  )  {
A  a1;
B  b1;
A  *a2=new A;
B  *b2=new B;
A  *c=new B;

C<A>  s1  (a1);
C<A>  s2  (b1);
C<A>  s3  (*a2);
C<A>  s4  (*b2);
C<A>  s5  (*c);
C<B>  t1 ( (B) a1);
C<B>  t2  (b1);
C<B>  t3  ( (B) *a2);
C<B>  t4  (* b2);
C<B>  t5  ( (B) *c);
D<A>  u1  ( &a1 );
D<A>  u2  ( &b1 );
D<A>  u3  ( a2 );
D<A>  u4  ( b2 );
D<A>  u5  ( c );
D<B>  v1  ( (B* ) &a1 );
D<B>  v2  ( &b1 );
D<B>  v3  ( (B* ) a2 );
D<B>  v4  (b2 );
D<B>  v5  ( (B* ) c );
return 0;
}
