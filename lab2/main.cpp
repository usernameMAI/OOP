#include "pentagon.h"
#include "TVector.h"
#include <string>

int main() {

    std::string command;
    TVector v;

    while (std::cin >> command){
        if(command == "print")
            std::cout << v;
        else if(command == "insertlast"){
            Pentagon p;
            std::cin >> p;
            v.InsertLast(p);
        }
        else if(command == "removelast"){
            v.RemoveLast();
        }
        else if(command == "last"){
            std::cout << v.Last();
        }
        else if(command == "idx"){
            int idx;
            std::cin >> idx;
            std::cout << v[idx];
        }
        else if(command == "length"){
            std::cout << v.Length() << std::endl;
        }
        else if(command == "clear"){
            v.Clear();
        }
        else if(command == "empty"){
            if(v.Empty()) std::cout << "Yes" << std::endl;
            else std::cout << "No" << std::endl;
        }
    }

}
