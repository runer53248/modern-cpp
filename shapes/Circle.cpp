#include "Circle.hpp"
#include <numbers>
#include <iostream>

static_assert( std::numbers::pi != 3.14, "M_PI should be more precise than 3.14");

Circle::Circle(double r)
    : r_(r) {}

double Circle::getArea() const {
    return std::numbers::pi * r_ * r_;
}

double Circle::getPerimeter() const {
    return 2 * std::numbers::pi * r_;
}

double Circle::getRadius() const {
    return r_;
}

void Circle::print() const {
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl
              << "         color: " << color_ << std::endl;
}

double Circle::getPi() {
    return std::numbers::pi;
}