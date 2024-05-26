#include <iostream>
#include <cmath>
#include <math.h>
# define M_PI           3
class Point
{
public:
    double x_coor;
    double y_coor;
    Point() {};
};

class Line : public Point // класс линии
{
public:
    double x_2_coor;
    double y_2_coor;
    Line() {};
    Line(double x1, double y1, double x2, double y2) {
        x_coor = x1;
        y_coor = y1;
        x_2_coor = x2;
        y_2_coor = y2;
    }

    void move(double x_move, double y_move) {
        std::cin >> x_move;
        std::cin >> y_move;
        x_coor += x_move;
        y_coor += y_move;
        x_2_coor += x_move;
        y_2_coor += y_move;
    }

    void rotate(double angle) {
        angle = angle * M_PI / 180;
        x_2_coor = (x_2_coor - x_coor) * cos(angle) - (y_2_coor - y_coor) * sin(angle) + x_2_coor;
        y_2_coor = (x_2_coor - x_coor) * sin(angle) + (y_2_coor - y_coor) * cos(angle) + y_2_coor;
    }

    void draw() {
        std::cout << "point1" << x_coor << y_coor;
        std::cout << "point2" << x_2_coor << y_2_coor;

    }
};

class Parallelogram : public Line {
public:

    double x_3_coor;
    double y_3_coor;
    double x_4_coor;
    double y_4_coor;
    Parallelogram() {};
    Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        x_coor = x1;
        y_coor = y1;
        x_2_coor = x2;
        y_2_coor = y2;
        x_3_coor = x3;
        y_3_coor = y3;
        x_4_coor = x4;
        y_4_coor = y4;
    }
    void move(double x_move, double y_move) {
        std::cin >> x_move;
        std::cin >> y_move;
        x_coor += x_move;
        y_coor += y_move;
        x_2_coor += x_move;
        y_2_coor += y_move;
        x_3_coor += x_move;
        y_3_coor += y_move;
        x_4_coor += x_move;
        y_4_coor += y_move;
    }

    void rotate(double angle) {
        angle = angle * M_PI / 180;
        x_2_coor = (x_2_coor - x_coor) * cos(angle) - (y_2_coor - y_coor) * sin(angle) + x_2_coor;
        y_2_coor = (x_2_coor - x_coor) * sin(angle) + (y_2_coor - y_coor) * cos(angle) + y_2_coor;
        x_3_coor = (x_3_coor - x_coor) * cos(angle) - (y_3_coor - y_coor) * sin(angle) + x_3_coor;
        y_3_coor = (x_3_coor - x_coor) * sin(angle) + (y_3_coor - y_coor) * cos(angle) + y_3_coor;
        x_4_coor = (x_4_coor - x_coor) * cos(angle) - (y_4_coor - y_coor) * sin(angle) + x_4_coor;
        y_4_coor = (x_4_coor - x_coor) * sin(angle) + (y_4_coor - y_coor) * cos(angle) + y_4_coor;
    }
    void draw() {
        std::cout << "Точка1: " << x_coor <<" "<< y_coor << std::endl;
        std::cout << "Точка2: " << x_2_coor << " " << y_2_coor << std::endl;
        std::cout << "Точка3: " << x_3_coor << " " << y_3_coor << std::endl;
        std::cout << "Точка4: " << x_4_coor << " " << y_4_coor << std::endl;

    }
};

class Rhomb : public Parallelogram {
public:
    Rhomb(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        x_coor = x1;
        y_coor = y1;
        x_2_coor = x2;
        y_2_coor = y2;
        x_3_coor = x3;
        y_3_coor = y3;
        x_4_coor = x4;
        y_4_coor = y4;
    }
};


class Rectangle : public Parallelogram {
public:
    Rectangle() {};
    Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        x_coor = x1;
        y_coor = y1;
        x_2_coor = x2;
        y_2_coor = y2;
        x_3_coor = x3;
        y_3_coor = y3;
        x_4_coor = x4;
        y_4_coor = y4;
    }
};

class Square : public Parallelogram {
public:
    Square() {};
    Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        x_coor = x1;
        y_coor = y1;
        x_2_coor = x2;
        y_2_coor = y2;
        x_3_coor = x3;
        y_3_coor = y3;
        x_4_coor = x4;
        y_4_coor = y4;
    }
};


int main()
{
    Parallelogram sq(0, 0, 1, 0, 1, 1, 0, 1);
    sq.rotate(90);
    sq.draw();

}

