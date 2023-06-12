#include <iostream>
#include <string>

using namespace std;
class Timestamp {

private:
    unsigned int hours;
    unsigned int min;
    unsigned int sec;

public:

    Timestamp(unsigned int ,unsigned int,unsigned int);
    Timestamp(const Timestamp &);
    ~Timestamp();
    // void getHour() const;
    // void getMin() const;
    // void getSec() const;

    // unsigned int setHour(unsigned int);
    // unsigned int setMin(unsigned int) ;
    // unsigned int setSec(unsigned int) ;

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

const Timestamp Timestamp::operator+(unsigned int sec){
    unsigned int s = this->sec + sec;
    unsigned int m = this->min + sec /60;
    unsigned int h = this->hours + m / 60;

    m = m % 60;
    s = s % 60;
    Timestamp timestamp(h,m,s);

    return timestamp;
}
const Timestamp Timestamp::operator+(const Timestamp &t){
    unsigned int s = this->sec + t.sec;
    unsigned int m = this->min + t.min + sec /60;
    unsigned int h = this->hours + t.hours + m / 60;

    m = m % 60;
    s = s % 60;
    Timestamp timestamp(h,m,s);

    return timestamp;
}
string Timestamp::getTime(){
    return 
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

}