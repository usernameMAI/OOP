#include "hexagon.h"

size_t Hexagon::VertexesNumber() {
    return 6;
}

double Hexagon::Area() {
    return SquareTriangle(a, b, c) + SquareTriangle(a, c, d) + SquareTriangle(a, d, e)
    + SquareTriangle(a, e, f);
}

void Hexagon::Print(std::ostream &os) {
    os << "Hexagon: " << a << b << c << d << e << f << std::endl;
}

Hexagon::Hexagon() {}

Hexagon::Hexagon(Point a_, Point b_, Point c_, Point d_, Point e_, Point f_) : a(a_), b(b_),
                                                c(c_), d(d_), e(e_), f(f_) {}

Hexagon::Hexagon(std::istream &is) {
    std::cout << "Enter data:" << std::endl;
    is >> a >> b >> c >> d >> e >> f;
    std::cout << "Hexagon created via istream" << std::endl;
}

Hexagon::Hexagon(const Hexagon &other) : Hexagon(other.a, other.b, other.c, other.d, other.e, other.f){
    std::cout << "Made copy of hexagon" << std::endl;
}

Hexagon::~Hexagon() {
    std::cout << "Hexagon deleted" << std::endl;
}

double Hexagon::SquareTriangle(Point a, Point b, Point c){
    double p = (a.dist(b) + b.dist(c) + c.dist(a)) / 2;
    return sqrt(p * (p - a.dist(b)) * (p - b.dist(c)) * (p - c.dist(a)));
}