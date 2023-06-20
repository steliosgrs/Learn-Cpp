#include <iostream>
#include "Point.h"
 
void LabeledPoint::display() const {
    cout << "label: " << label << ", ";
    // cout << x << y; // �����. �������� ���� ��� Point.
    // cout << getX() << getY(); // ��, ���� �������� �� ��������:
    Point::display(); // ����� ��� ������� ������ ��� �������.
}

void test_Point() {
    Point* p2 = new LabeledPoint(1, 2, "test");
    p2->setX(3); p2->setY(4); // �������������� �������.    
    //cout << p2->getLabel() << endl; // ������� �other�.
    p2->display(); // �������������. ��� ������� �� label.
    
}

int main() {
	// ������: �������� ��� ��� Point �� ���� virtual ��� �� display
	Point* p1 = new LabeledPoint(1, 2, "test");
	Point* p2 = new Point(1, 2);
	p1->display();
	p2->display();
	
	return 0;
}
