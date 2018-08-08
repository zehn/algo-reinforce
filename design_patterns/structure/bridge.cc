/**
 * The Bridge Pattern is used to separate out the interface from its
 * implementation. Doing this gives the flexibility so that both can vary
 * independently.
 */
#include <iostream>

// implementor
class DrawingAPI {
public:
    virtual void drawCircle(double x, double y, double radius) = 0;
    virtual ~DrawingAPI() {}
};

class DrawingAPI10 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) {
        std::cout << "API10.circle at " << x << ':' << y << ' ' << radius << std::endl;
    } 
};


class DrawingAPI20 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) {
        std::cout << "API20.circle at " << x << ':' << y << ' ' << radius << std::endl;
    } 
};

// abstraction
class Shape {
public:
    virtual ~Shape() {}
    virtual void draw() = 0;
    virtual void resizeByPercentage(double p) = 0;
};

class CircleShape : public Shape {
private:
    double _x;
    double _y;
    double _radius;
    DrawingAPI* _draw_api;

public:
    CircleShape(double x, double y, double radius, DrawingAPI* api) 
        : _x(x), _y(y), _radius(radius), _draw_api(api) {
    }
    void draw() {
        _draw_api->drawCircle(_x, _y, _radius);    
    }
    void resizeByPercentage(double p) {
        _radius *= p;
    }
};

int main(int argc, char* argv[])
{
    CircleShape circle1(1, 2, 3, new DrawingAPI10());
    CircleShape circle2(5, 7, 11, new DrawingAPI20());
    circle1.resizeByPercentage(2.5);
    circle2.resizeByPercentage(2.5);
    circle1.draw();
    circle2.draw();
    return 0;
}

