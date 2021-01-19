#ifndef SHAPE_H
#define SHAPE_H

class Shape{
protected:
    Shape(std::string name){
        _name = name;
    }

public:
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
    virtual std::string toString() const = 0;
    virtual ~Shape(){}

    std::string name() const{
        return _name;
    }

private:
    std::string _name;
};

#endif