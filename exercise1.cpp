#include <iostream>
#include <stdio.h>

using namespace std;

struct Person
{
    int id;
    std::string Name;
    std::string Last;
    float height;
};

// Prototypes
Person * initPeople(int);
Person &change_name(Person[]);
void multiply(double &,double &, double &);
double perimeter(double, double, double w=4.8, double z = 5.9);

int main(int argc, char const *argv[])
{
    system("chcp 1253>nul");
    cout << "\n1� ���������: ������ ����� �� const double " << endl ;
    // ������ const double ��� ���� Pointer ��� ������� �� double
    const double num = 2.2;
    double *point;

    point = (double *)&num; // To casting ����� ���������� 
                          // double �� �� const double ����� ������������ ����� ���������.

    // ������ ��� ����� �������� ����� ��� Pointer
    *point = 90.2;

    cout << "Num =" << num; 
    cout << "*point =" << *point << endl;


    cout << "\n2� ���������: ����� �������� new,new[],delete ��� delete[] " << endl ;
    // new & delete
    int *year;
    year = new int;
    *year = 2022;
    cout << "To year = " << *year << endl;
    delete year;

    // new[] & delete[]
    int p;
    cout << "\n���� ����������� Person �� �������������; " << endl ;
    cin >> p;
    Person *person = initPeople(p);
    
    delete[] person; 


    cout << "\n3� ���������: ����� ��� �������� ���� ����������� ��� ��� ���� ���������� ��� �����������" << endl ;

    // ����� �������� ���� �����������
    cout << "\n��������������� 2 �������" << endl;
    double num1,num2,res;
    cout << "���� 1� ������: ";
    cin >> num1;
    cout << "\n���� 2� ������: ";
    cin >> num2; 
    multiply(num1,num2,res);
    cout << res << endl;


    cout << "\n4� ���������: ����������� ���������� ��� �� ����������� �� ����������� �� ������ ����� default �����" << endl ;

    perimeter(2.2,3.2,2.3,4.2);
    perimeter(2.2,3.2,2.3);
    perimeter(2.2,3.2);
    return 0;
}

// ��������� ��� ��� ������������ ��� ������������ Person
Person *initPeople(int p){
    string fname,lname;
    float height;
    // �������� ������� ������ p ������
    Person *temp = new Person[p];
    // ���������� ������������ Person ��� ��� ������
    for (int i = 0; i < p; i++){
        cout << "Person " << i+1 << endl ;
        temp[i].id = i;
        cout <<"�����: ";
        cin >> fname;
        temp[i].Name  = fname;
        cout <<"�������: ";
        cin >> lname;
        temp[i].Last = lname;
        cout <<"����: ";
        cin >> height;
        temp[i].height = height;
    }
    return temp;
}

// ��������� ��������������� �������� ����� �������� ���� �����������
void multiply(double &num1, double &num2, double &res){
    res = num1 * num2;
}


// ��������� ����������� ���������� 
double perimeter(double x, double y, double w, double z){
    double res = x + y + w + z;
    return res;
}

