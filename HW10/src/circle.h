#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include <sstream>
#include "shape.h"
#include "vector.h"

class Circle : public Shape{
public:
    Circle(double r, std::string name = "anonymous", Vector origin = Vector(2)):Shape(name){
        _r = r;
        _origin = origin;
    }
 
    ~Circle() override {
    }

    double perimeter() const override{
        return M_PI * 2 * _r;
    }

    double area() const override{
        // std::cout << _r <<std::endl;
        return M_PI * _r * _r;
    }

    std::string toString() const override{
        std::stringstream ss;
        ss << "circle {\n" << name() << "\n" << _origin.toString() << "\n" << _r << "\n}\n";
        return ss.str();
    }

private:
    double _r;
    Vector _origin;
};


#endif