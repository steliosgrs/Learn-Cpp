#include <iostream>
#include <cstring>

template <class Q>
class Queue{
    int len = 0;
    char * data;
}

int main(){
    Queue<int> q1(1);
    q1.enqueue(2);
    q1.dequeue(2);
    int length = q1.getlen()
    Queue<int> q2(3);
    q2.is_equal(q1);
    return 0;
}