#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

class Student{

private:
    int AM;
    char * name;
    int semester;
    bool active;
public:
    void setAM(const int);
    void setName(const char * );
    void setSemester(const int);
    void setActive(const bool);


    Student(const int, const char *, const int, const bool );
    ~Student();
};

// vector read_csv();
void getInfo(const string);
void printInfo(const string);

Student::Student(const int AM, const char *name, const int semester, const bool active ){
    this->AM = AM;

    int size = strlen(name);
    // delete name;
    this->name = new char[size + 1];
    strcpy(this->name,name);
    this->semester = semester;
    this->active = active;
}

Student::~Student(){}

string getInfo(const string filename){
    
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string column;
        CSVRow row;

        getline(iss, row.column1, ',');
        getline(iss, row.column2, ',');
        // Add more lines to extract additional columns

        csvData.push_back(row);
    return csvData;
    }
    // ifstream file;
    // file.open(filename);
    // if (file.is_open()){
    //     string line;
    //     getline(file,line);

    // }
    // for (int i = 0; i < )

}

void Student::printInfo(vector csvData){
    for (const auto& row : csvData) {
        cout << "Column 1: " << row.column1 << ", Column 2: " << row.column2  ;
        cout << "Column 3: " << row.column3 << ", Column 4: " << row.column4 ;
        cout << endl;
    }
}
int main (){
    ifstream file("student.csv");
    // string data = getInfo("student.csv");
    // printInfo(data);
    
}