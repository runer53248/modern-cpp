#include "Shape.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Color color) {
    const char* colors[] = {
        "Black",
        "Red",
        "White"
    };
    os << colors[static_cast<unsigned char>(color)];
    return os;
}

Shape::Shape(Color color)
    : color_{color} {}

void Shape::print() const {
    std::cout << "Unknown Shape" << std::endl;
}
