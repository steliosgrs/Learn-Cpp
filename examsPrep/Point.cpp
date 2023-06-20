#include <iostream>
#include "Point.h"
 
void LabeledPoint::display() const {
    cout << "label: " << label << ", ";
    // cout << x << y; // Λάθος. Ιδιωτικά μέλη της Point.
    // cout << getX() << getY(); // ΟΚ, αλλά καλύτερα το ακόλουθο:
    Point::display(); // Κλήση της αρχικής μορφής της μεθόδου.
}

void test_Point() {
    Point* p2 = new LabeledPoint(1, 2, "test");
    p2->setX(3); p2->setY(4); // Κληρονομημένες μέθοδοι.    
    //cout << p2->getLabel() << endl; // Τυπώνει «other».
    p2->display(); // Κληρονομημένη. Δεν τυπώνει το label.
    
}

int main() {
	// Δοκιμη: Βγάζουμε από την Point τη λέξη virtual από τη display
	Point* p1 = new LabeledPoint(1, 2, "test");
	Point* p2 = new Point(1, 2);
	p1->display();
	p2->display();
	
	return 0;
}
