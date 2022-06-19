#ifndef LAB1_HEXAGON_H
#define LAB1_HEXAGON_H

#include "figure.h"

class Hexagon : Figure{
public:
    size_t VertexesNumber() override;
    double Area() override;
    void Print(std::ostream &os) override;

    Hexagon();
    Hexagon(Point a_, Point b_, Point c_, Point d_, Point e_, Point f_);
    Hexagon(std::istream &is);
    Hexagon(const Hexagon &other);
    virtual ~Hexagon();
private:
    Point a, b, c, d, e, f;
    double SquareTriangle(Point a, Point b, Point c);
};

#endif //LAB1_HEXAGON_H
