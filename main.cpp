#include <iostream>

#include "primsmaze.h"
#include "binarytreemaze.h"

int main(){
    int width, height;
    int seed;
    std::cout << "Width: ";
    std::cin >> width;
    std::cout << "Height: ";
    std::cin >> height;
    std::cout << "Seed: ";
    std::cin >> seed;

    PrimsMaze victor(width, height);
    victor.generate(seed);
    victor.print_maze();
}