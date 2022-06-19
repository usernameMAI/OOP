#include "octagon.h"

size_t Octagon::VertexesNumber() {
    return 8;
}

double Octagon::Area() {
    return SquareTriangle(a, b, c) + SquareTriangle(a, c, d) + SquareTriangle(a, d, e)
           + SquareTriangle(a, e, f) + SquareTriangle(a, f, g) + SquareTriangle(a, g, h);
}

void Octagon::Print(std::ostream &os) {
    os << "Octagon: " << a << b << c << d << e << f << g << h << std::endl;
}

Octagon::Octagon() {}

Octagon::Octagon(Point a_, Point b_, Point c_, Point d_, Point e_, Point f_, Point g_, Point h_) : a(a_), b(b_),
        c(c_), d(d_), e(e_), f(f_), g(g_), h(h_) {}

Octagon::Octagon(std::istream &is) {
    std::cout << "Enter data:" << std::endl;
    is >> a >> b >> c >> d >> e >> f >> g >> h;
    std::cout << "Octagon created via istream" << std::endl;
}

Octagon::Octagon(const Octagon &other) : Octagon(other.a, other.b, other.c, other.d,
                                                 other.e, other.f, other.g, other.h){
    std::cout << "Made copy of hexagon" << std::endl;
}

Octagon::~Octagon() {
    std::cout << "Octagon deleted" << std::endl;
}

double Octagon::SquareTriangle(Point a, Point b, Point c){
    double p = (a.dist(b) + b.dist(c) + c.dist(a)) / 2;
    return sqrt(p * (p - a.dist(b)) * (p - b.dist(c)) * (p - c.dist(a)));
}