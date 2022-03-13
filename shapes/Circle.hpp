#pragma once
#include "Shape.hpp"

class alignas(8) Circle final : public Shape {
public:
    using Shape::Shape;
    Circle() = delete;
    Circle(double r);
    Circle(const Circle& other) = default;

    double getArea() const override;
    double getPerimeter() const override;
    void print() const override;
    
    double getRadius() const;
    [[deprecated]]static double getPi();

private:
    double r_{};
};
