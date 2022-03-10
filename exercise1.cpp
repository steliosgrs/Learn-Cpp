#include <iostream>
#include <stdio.h>

using namespace std;

struct Person
{
    int id;
    string Name;
    string Last;
    float height;
};

// Prototypes
Person * initPeople(int);
Person &change_name(Person[]);

int main(int argc, char const *argv[])
{
    system("chcp 1253>nul");
    cout << "1� ���������: ������ ����� �� const double " << endl ;
    // ������ const double ��� ���� Pointer ��� ������� �� double
    const double num = 2.2;
    double *point;

    point = (double *)&num; // To casting ����� ���������� 
                          // double �� �� const double ����� ������������ ����� ���������.

    // ������ ��� ����� �������� ����� ��� Pointer
    *point = 90.2;

    cout << num << " " << *point << endl;


    cout << "2� ���������: ����� �������� new,new[],delete ��� delete[] " << endl ;
    // new & delete
    int *year;
    year = new int;
    *year = 2022;
    cout << "To year = " << *year << endl;
    delete year;

    // new[] & delete[]
    int p;
    cout << "����� ������ �� �������;" << endl ;
    cin >> p;
    Person *person = initPeople(p);
    delete[] person; 


    cout << "3� ���������: ����� ��� �������� ���� ����������� ��� ��� ���� ���������� ��� �����������" << endl ;

    cout << "4� ���������: ����������� ���������� ��� �� ����������� �� ����������� �� ������ ����� default �����" << endl ;

    return 0;
}

Person *initPeople(int p){
    string fname,lname;
    float height;
    // �������� ������� ������ p ������
    Person *temp = new Person[p];
    // ���������� ������������ Person ��� ��� ������
    for (int i = 0; i < p; i++){
        cout << i+1 <<"�� Person" << endl;
        temp[i].id = i;
        cout <<"�����: " << endl;
        cin >> fname;
        temp[i].Name  = fname;
        cout <<"�������: " << endl;
        cin >> lname;
        temp[i].Last = lname;
        cout <<"����: " << endl;
        cin >> height;
        temp[i].height = height;
    }
    return temp;
}
