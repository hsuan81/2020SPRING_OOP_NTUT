#ifndef CONVEXPOLYGON_H
#define CONVEXPOLYGON_H
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "shape.h"
#include "vector.h"

class ConvexPolygon : public Shape{
public:
    ConvexPolygon(std::vector<Vector> vecs, std::string name = "anonymous"):Shape(name){
        _numOfVertices = vecs.size();
        Vector c = centroid(vecs, _numOfVertices);
        Vector basis = vecs[0] - c;
        AngleComparator comp(basis, c);
        std::sort(vecs.begin(), vecs.end(), comp);
        _vecs = vecs;
    }
    
    ~ConvexPolygon() override{
    }

    double perimeter() const override{
        double result = 0;
        for (int i=1; i<_numOfVertices; i++){
            result += (_vecs[i] - _vecs[i-1]).length();
        }
        result += (_vecs[_numOfVertices-1] - _vecs[0]).length();
        return result;
    }

    double area() const override{
        double result = 0;
        for (int i=1; i<_numOfVertices-1; i++){
            result += _vecs[0].area(_vecs[i], _vecs[i+1]);
        }
        return result;
    }

    std::string toString() const override{
        std::stringstream ss;
        ss << "convex polygon {\n" << name() << "\n";
        for (auto i:_vecs){
            ss << i.toString() << "\n";
        }
        ss << "}\n";
        return ss.str();
    }

private:
    std::vector<Vector> _vecs;
    int _numOfVertices;
};


#endif