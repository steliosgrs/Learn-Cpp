#include <iostream>
#include <string>

using namespace std;
class Timestamp {

// private:

public:
    unsigned int hours;
    unsigned int min;
    unsigned int sec;

    Timestamp(unsigned int ,unsigned int,unsigned int);
    Timestamp(const Timestamp &);
    ~Timestamp();

    const Timestamp operator+(unsigned int);
    const Timestamp operator+(const Timestamp &);
    string getTime();
    bool operator==(const Timestamp &);


};

Timestamp::Timestamp(unsigned int h, unsigned int m, unsigned int s){
    if (h < 23 && m < 60 && s < 60){
        this->hours = h;
        this->min = m;
        this->sec = s;

    }else{
        this->hours = this->min = this->sec = 0 ;
    }

}
Timestamp::Timestamp(const Timestamp &t){
    this->hours = t.hours;
    this->min = t.min;
    this->sec = t.sec;
}

Timestamp::~Timestamp(){

}

const Timestamp Timestamp::operator+(unsigned int sec){
    unsigned int s = this->sec + sec;
    unsigned int m = this->min + sec /60;
    unsigned int h = this->hours + m / 60;

    m = m % 60;
    s = s % 60;
    h = h % 24;
    Timestamp timestamp(h,m,s);

    return timestamp;
}
const Timestamp Timestamp::operator+(const Timestamp &t){
    unsigned int s = this->sec + t.sec;
    unsigned int m = this->min + t.min + sec /60;
    unsigned int h = this->hours + t.hours + m / 60;

    m = m % 60;
    s = s % 60;
    h = h % 24;
    // cout << h<< m<< s<<endl;
    Timestamp timestamp(h,m,s);

    return timestamp;
}
string Timestamp::getTime(){
    return "ώρα " + to_string(this->hours) +" λεπτά " +to_string(this->min)+" δευτερολεπτα " +to_string(this->sec);
}
bool Timestamp::operator==(const Timestamp &t){
    if (this->hours == t.hours && this->min == t.min && this->sec == t.sec){
        return true;
    }
    else{
        return false;

    }
}

int main (){
    Timestamp t1(12,23,23);
    Timestamp t2(t1);
    cout <<t1.getTime() <<endl;
    Timestamp t3 = t1+60;
    
    cout <<t3.getTime() <<endl;

    Timestamp t4 = t1+t2;
    cout <<t4.getTime() <<endl;

    if (t4 == t3){
        cout << "Ίσες" << endl;
    }
    else{
        cout << "όχι Ίσες" << endl;

    }


}