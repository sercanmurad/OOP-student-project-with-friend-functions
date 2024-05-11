#include <iostream>

using namespace std;

class Point {
private:
    double x;
    double y;
public:
    // Default constructor
    Point() : x(0.0), y(0.0) {}

    // Parameterized constructor
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    // Friend functions for operator overloading
    friend Point operator+(const Point& p1, const Point& p2);
    friend Point operator*(const Point& p1, const Point& p2);
    friend Point operator*(const Point& p, double scalar);

    // Overloading the insertion operator for printing
    friend ostream& operator<<(ostream& out, const Point& p);

    // Getter methods for coordinates
    double getX() const { return x; }
    double getY() const { return y; }
};

// Overloading the addition operator for adding coordinates of two points
Point operator+(const Point& p1, const Point& p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

// Overloading the multiplication operator for multiplying coordinates of two points
Point operator*(const Point& p1, const Point& p2) {
    return Point(p1.x * p2.x, p1.y * p2.y);
}

// Overloading the multiplication operator for multiplying coordinates of a point with a scalar
Point operator*(const Point& p, double scalar) {
    return Point(p.x * scalar, p.y * scalar);
}

// Overloading the insertion operator for printing a point
ostream& operator<<(ostream& out, const Point& p) {
    out << "Point (" << p.x << ", " << p.y << ")";
    return out;
}

int main() {
    // Declaration of objects
    Point p1(2.5, 3.5);
    Point p2(1.0, 1.0);

    // Using overloaded operators
    Point sum = p1 + p2;
    Point product = p1 * p2;
    Point scaled = p1 * 2.0;

    // Printing the results
    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;
    cout << "Scaled: " << scaled << endl;

    return 0;
}

