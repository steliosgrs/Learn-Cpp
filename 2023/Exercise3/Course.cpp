#include "Course.h"

Course::Course(const std::string code, const std::string name, unsigned int hours, bool semester){
    this->code = code;
    this->name = name;
    this->hours = hours;
    this->semester = semester;
}

Course::~Course(){
    std::cout << "Καταστροφή Μαθήματος " << this->name << std::endl;
}


void Course::setCode(const std::string code){
    this->code = code;

}
void Course::setName(const std::string name){
    this->name = name;

}
void Course::setHours(const unsigned int hours){
    this->hours = hours;

}
void Course::setSemester(const bool semester){
    this->semester = semester;

}
std::string Course::getCode() const{
    return this->code;
}
std::string Course::getName() const{
    return this->name;
}
unsigned int Course::getHours() const{
    return this->hours;
}
bool Course::getSemester() const{
    return this->semester;
}







