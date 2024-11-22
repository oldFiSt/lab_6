#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iostream>

class Rectangle : public Shape {
public:
    Rectangle(const std::string& color) : Shape(color) {}

    void Draw() override {
        std::cout << "Drawing a " << color << " rectangle." << std::endl;
    }

    void Erase() override {
        std::cout << "Erasing a " << color << " rectangle." << std::endl;
    }
};

#endif // RECTANGLE_H
