#ifndef UTIL_H
#define UTIL_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "shape.h"
#include "circle.h"
#include "convexPolygon.h"
#include "vector.h"

typedef bool (*Comp) (Shape *, Shape *);
Comp GreaterArea = [](Shape * a, Shape * b){
    return a->area() < b->area();
};

Comp GreaterPerimeter = [](Shape * a, Shape * b){
    return a->perimeter() < b->perimeter();
};

Comp LessArea = [](Shape * a, Shape * b){
    return a->area() > b->area();
};

Comp LessPerimeter = [](Shape * a, Shape * b){
    return a->perimeter() > b->perimeter();
};

std::vector<Shape *> handleSort(std::vector<Shape *> shapes, std::string compare, std::string order){
    std::vector<Shape *> result = shapes;
    if (order == "inc"){
        if (compare == "area"){
            std::sort(result.begin(), result.end(), GreaterArea);
        }
        else if (compare == "perimeter"){
            std::sort(result.begin(), result.end(), GreaterPerimeter);
        }
        else{
            throw "Undefined comparison type";
        }
    }
    else if (order == "dec"){
        if (compare == "area"){
            std::sort(result.begin(), result.end(), LessArea);
        }
        else if (compare == "perimeter"){
            std::sort(result.begin(), result.end(), LessPerimeter);
        }
        else{
            throw "Undefined comparison type";
        }
    }
    else{
        throw std::string("Undefined sorting order");
    }
    return result;
}

Vector stringToVector(std::string vectorInfo){
    std::stringstream ss(vectorInfo);
    char ch;
    double a[2];
    ss >> ch >> a[0] >> ch >> a[1] >> ch;
    return Vector(a, 2);
}

std::vector<Shape *> stringToShape(std::string shapeInfo){
    std::stringstream ss(shapeInfo);
    std::string line;
    std::getline(ss, line);
    std::vector<Shape *> result;
    while(!line.empty()){
        if (line == "circle {"){
            std::string name;
            std::getline(ss, name);
            std::getline(ss, line);
            Vector origin = stringToVector(line);
            std::getline(ss, line);
            double r = std::stod(line);
            result.push_back(new Circle(r, name, origin));
            std::getline(ss, line);
        }
        else if (line == "convex polygon {"){
            std::vector<Vector> points;
            std::string name;
            std::getline(ss, name);
            std::getline(ss, line);
            while(line != "}"){
                points.push_back(stringToVector(line));
                std::getline(ss, line);
            }
            result.push_back(new ConvexPolygon(points, name));
        }
        if (line != "}"){
            throw "format error";
        }
        std::getline(ss, line);
    }
    return result;
    
}

std::vector<Shape *> handleInput(std::string fileName){
    std::ifstream infs(fileName);
    if (!infs){
        throw std::string("File " + fileName + " doesn't exist.");
    }
    std::string lines;
    std::getline(infs, lines);
    std::string result;
    while(!infs.eof()){
        result = result + lines + "\n";
        std::getline(infs, lines);
    }
    std::vector<Shape *> shapes = stringToShape(result);
    return shapes;
}

void handleOutput(std::string fileName, std::vector<Shape *> shapes){
    std::ofstream ofs(fileName);
    if (!ofs){
        throw std::string("Problem opening file " + fileName + " for writing.");
    }
    for (Shape * s: shapes){
        ofs << s->toString();
    }
}


#endif