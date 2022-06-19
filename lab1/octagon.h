#ifndef LAB1_OCTAGON_H
#define LAB1_OCTAGON_H

#include "figure.h"

class Octagon : Figure{
public:
    size_t VertexesNumber() override;
    double Area() override;
    void Print(std::ostream &os) override;

    Octagon();
    Octagon(Point a_, Point b_, Point c_, Point d_, Point e_, Point f_, Point g_, Point h_);
    Octagon(std::istream &is);
    Octagon(const Octagon &other);
    virtual ~Octagon();

private:
    Point a, b, c, d, e, f, g, h;
    double SquareTriangle(Point a, Point b, Point c);
};

#endif //LAB1_OCTAGON_H
