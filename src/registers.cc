#include <array>
#include <iostream>

enum Registers {
    A, B, C, D, E,
};

std::array<int, 5> registers;

void dump() {
    static const std::array<char, 5> names {'A', 'B', 'C', 'D', 'E'};
    for (unsigned int i = 0; i < registers.size(); ++i) {
        std::cout << "Register " 
        << names.at(i) 
        << ": " << registers.at(i) << std::endl;
    }
}