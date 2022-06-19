#include "pentagon.h"
#include "TVector.h"
#include "TStack.h"

int main() {
    TVector<Pentagon> t;

    t.InsertLast(std::shared_ptr<Pentagon>(new Pentagon(
            {1.f, 9.f}, {8.f, 7.f}, {6.f, 5.f}, {4.f, 3.f}, {2.f, 1.f})));

    t.InsertLast(std::shared_ptr<Pentagon>(new Pentagon(
            {1.f, 9.f}, {8.f, 7.f}, {6.f, 5.f}, {4.f, 3.f}, {2.f, 1.f})));

    t.InsertLast(std::shared_ptr<Pentagon>(new Pentagon(
            {1.f, 9.f}, {8.f, 7.f}, {6.f, 5.f}, {4.f, 3.f}, {2.f, 1.f})));

    std::cout << t << std::endl;

    for (auto i = t.begin(); i != t.end(); ++i)
        (*i).Print(std::cout);
}
