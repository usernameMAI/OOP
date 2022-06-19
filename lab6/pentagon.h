#ifndef OOP5_PENTAGON_H
#define OOP5_PENTAGON_H

#include "figure.h"
#include "tallocation.h"

class Pentagon : Figure{
public:
    friend std::istream& operator>>(std::istream& is, Pentagon& p);
    friend std::ostream& operator<<(std::ostream& os, Pentagon& p);
    size_t VertexesNumber() override;
    double Area() override;
    void Print(std::ostream &os) override;
    bool operator==(const Pentagon& other);
    Pentagon();
    Pentagon(Point a_, Point b_, Point c_, Point d_, Point e_);
    Pentagon(std::istream &is);
    Pentagon(const Pentagon &other);
    Pentagon& operator=(const Pentagon& other);

    void *operator new(size_t size)
    {
        return _alloc_block.Allocate(size);
    }

    void operator delete(void *pointer)
    {
        _alloc_block.Free(pointer);
    }
private:
    Point a, b, c, d, e;
    double SquareTriangle(Point a, Point b, Point c);

    static TAllocationBlock _alloc_block;
};

#endif //OOP5_PENTAGON_H
