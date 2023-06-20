#pragma once
#include <iostream>
#include <string>

using namespace std;

class Point {
private:
    int x, y;
public:
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
    int getX() const { return x; }
    int getY() const { return y; }

    virtual void display() const { cout << "x: " << x << ", y: " << y << endl; }    
    Point(int newX = 0, int newY = 0) : x(newX), y(newY) {}

    Point(const Point& original) : x(original.x), y(original.y) {}
};



class LabeledPoint : public Point {
    string label; 

public:
    void setLabel(const string& newLabel) { label = newLabel; }
    string getLabel() const { return label; }
    LabeledPoint(int newX = 0, int newY = 0,
        const string& newLabel = "label") :Point(newX, newY), label(newLabel) { }

    void display() const;
};


void test_Point();
