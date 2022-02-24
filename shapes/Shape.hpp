#pragma once
#include <ostream>

enum class Color : unsigned char {
    Black,
    Red,
    White
};

std::ostream& operator<<(std::ostream& os, Color color);

class Shape {
public:
    Shape() = default;
    Shape(const Shape&) = default;
    Shape(Color color);
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

protected:
    Color color_{Color::White};
};
