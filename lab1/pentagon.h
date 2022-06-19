#ifndef LAB1_PENTAGON_H
#define LAB1_PENTAGON_H

#include "figure.h"

class Pentagon : Figure{
public:
    size_t VertexesNumber() override;
    double Area() override;
    void Print(std::ostream &os) override;

    Pentagon();
    Pentagon(Point a_, Point b_, Point c_, Point d_, Point e_);
    Pentagon(std::istream &is);
    Pentagon(const Pentagon &other);
    virtual ~Pentagon();
private:
    Point a, b, c, d, e;
    double SquareTriangle(Point a, Point b, Point c);
};

#endif //LAB1_PENTAGON_H
