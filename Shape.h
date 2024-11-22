#ifndef SHAPE_H
#define SHAPE_H

#include "IShape.h"
#include <string>

class Shape : public IShape {
protected:
    std::string color;

public:
    Shape(const std::string& color) : color(color) {}
    virtual ~Shape() = default;
};

#endif 
