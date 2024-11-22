#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <iostream>

class Circle : public Shape {
public:
    Circle(const std::string& color) : Shape(color) {}

    void Draw() override {
        std::cout << "Drawing a " << color << " circle." << std::endl;
    }

    void Erase() override {
        std::cout << "Erasing a " << color << " circle." << std::endl;
    }
};

#endif // CIRCLE_H
