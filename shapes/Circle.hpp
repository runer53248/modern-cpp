#pragma once

#include "Shape.hpp"

class Circle : public Shape {
public:
    Circle() = delete;
    Circle(double r);
    Circle(const Circle& other) = default;

    double getArea() const;
    double getPerimeter() const;
    double getRadius() const;
    void print() const;

private:
    double r_;
};
