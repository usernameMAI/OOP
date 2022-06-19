#include "pentagon.h"

std::istream& operator>>(std::istream& is, Pentagon& p) {
    std::cout << "Enter data:" << std::endl;
    is >> p.a >> p.b >> p.c >> p.d >> p.e;
//    std::cout << "Pentagon created via istream" << std::endl;
    return is;
}

std::ostream& operator<<(std::ostream& os, Pentagon& p) {
    os << "Pentagon: " << p.a << p.b << p.c << p.d << p.e << std::endl;
    return os;
}


Pentagon& Pentagon::operator=(const Pentagon &other) {
    this->a = other.a;
    this->b = other.b;
    this->c = other.c;
    this->d = other.d;
    this->e = other.e;
    return *this;
}

bool Pentagon::operator==(const Pentagon &other) {
    return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e;
}

size_t Pentagon::VertexesNumber() {
    return 5;
}

double Pentagon::SquareTriangle(Point a, Point b, Point c){
    double p = (a.dist(b) + b.dist(c) + c.dist(a)) / 2;
    return sqrt(p * (p - a.dist(b)) * (p - b.dist(c)) * (p - c.dist(a)));
}

double Pentagon::Area() {
    return SquareTriangle(a, b, c) + SquareTriangle(a, c, d) + SquareTriangle(a, d, e);
}

void Pentagon::Print(std::ostream &os) {
    os << "Pentagon: " << a << b << c << d << e << std::endl;
}

Pentagon::Pentagon(){}

Pentagon::Pentagon(Point a_, Point b_, Point c_, Point d_, Point e_) : a(a_), b(b_), c(c_), d(d_), e(e_) {}

Pentagon::Pentagon(const Pentagon &other) : Pentagon(other.a, other.b, other.c, other.d, other.e) {
}

Pentagon::Pentagon(std::istream &is) {
    std::cout << "Enter data:" << std::endl;
    is >> a >> b >> c >> d >> e;
//    std::cout << "Pentagon created via istream" << std::endl;
}

Pentagon::~Pentagon() {
//    std::cout << "Pentagon deleted" << std::endl;
}
