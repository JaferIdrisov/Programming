#include "cmath"
#include "iostream"

using namespace std;


class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0);

    void move(double dx, double dy);
};

class IBaseShape {
public:
    virtual void draw() = 0;

    virtual void erase() = 0;

    virtual void move(double dx, double dy) = 0;

    virtual void rotate(double angle) = 0;

    virtual ~IBaseShape() {}
};


class Line : public IBaseShape {
protected:
    Point points[2];
public:
    Line(Point p1, Point p2);

    void erase() override;

    void draw() override;

    void move(double dx, double dy) override;

    void rotate(double angle) override;
};

class Square : public IBaseShape {
public:
    Point points[4];
public:
    Square(Point p1, Point p2, Point p3, Point p4);

    void draw() override;

    void erase() override;

    void move(double dx, double dy) override;

    void rotate(double angle);

};

class Rectangle : public IBaseShape {
public:
    Point points[4];
public:
    Rectangle(Point p1, Point p2, Point p3, Point p4);

    void erase() override;

    void draw() override;

    void move(double dx, double dy) override;

    void rotate(double angle) override;
};

class Parallelogram : public IBaseShape {
public:
    Point points[4];
public:
    Parallelogram(Point p1, Point p2, Point p3, Point p4);

    void erase() override;

    void draw() override;

    void move(double dx, double dy) override;

    void rotate(double angle) override;
};

class Rhombus : public IBaseShape {
public:
    Point points[4];
public:
    Rhombus(Point p1, Point p2, Point p3, Point p4);

    void erase() override;

    void draw() override;

    void move(double dx, double dy) override;

    void rotate(double angle) override;
};



