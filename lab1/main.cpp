#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"

int main() {
    //Pentagon
    Pentagon p(std::cin);
    p.Print(std::cout);
    std::cout << "Number of vertex is " << p.VertexesNumber() << std::endl;
    std::cout << "Area is " << p.Area() << std::endl;

    std::cout << "---------------------------" << std::endl;
    //Hexagon
    Hexagon h(std::cin);
    h.Print(std::cout);
    std::cout << "Number of vertex is " << h.VertexesNumber() << std::endl;
    std::cout << "Area is " << h.Area() << std::endl;

    std::cout << "---------------------------" << std::endl;
    //Octagon
    Octagon o(std::cin);
    o.Print(std::cout);
    std::cout << "Number of vertex is " << o.VertexesNumber() << std::endl;
    std::cout << "Area is " << o.Area() << std::endl;

    std::cout << "---------------------------" << std::endl;
}
