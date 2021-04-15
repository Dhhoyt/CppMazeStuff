#include "abstractmaze.h"
#include <iostream>

//the numbers here refer to how many cells wide the maze is
AbstractMaze::AbstractMaze(int _width, int _height)
    : width(_width), height(_height), 
    horizontal_gates(width, std::vector<bool>(height - 1, true)), vertical_gates(width - 1, std::vector<bool>(height, true)) {}

void AbstractMaze::print_maze()
{
    char intersection[16][4] = {" ", "│", "│", "│", "─", "┘", "┐", "┤", "─", "└", "┌", "├", "─", "┴", "┬", "┼"};
    std::cout << "─";
    for(int j = 0; j < width- 1; j++)
    {
        std::cout << "─";
        if(vertical_gates[j][0])
        {
            std::cout << "┬";
        }else
        {
            std::cout << "─";
        }
    }
    std::cout << "─┐" << std::endl;
    for(int i = 0; i < height; i++)
    {
        if(i != 0)
        {
            if(horizontal_gates[0][i-1])
            {
                std::cout << "├";
            }else
            {
                std::cout << "│";
            }
            for(int j = 0; j < width; j++)
            {
                if(j != 0){
                    int mask = 0;
                    //Up
                    if(vertical_gates[j-1][i-1]){
                        mask += 1;  
                    }
                    //Down
                    if(vertical_gates[j-1][i]){
                        mask += 2;
                    }
                    //Left
                    if(horizontal_gates[j-1][i-1]){
                        mask += 4;
                    }
                    //Right
                    if(horizontal_gates[j][i-1]){
                        mask += 8;
                    }
                    std::cout << intersection[mask];
                }
                if(horizontal_gates[j][i-1])
                {
                    std::cout << "─";
                }else
                {
                    std::cout << " ";
                }
            }
            if(horizontal_gates[width - 1][i-1])
            {
                std::cout << "┤";
            }else
            {
                std::cout << "│";
            }
            std::cout << std::endl;
        }
        std::cout << "│";
        for(int j = 0; j < width - 1; j++)
        {
            std::cout << " ";
            if(vertical_gates[j][i])
            {
                std::cout << "│";
            }else
            {
                std::cout << " ";
            }
        }
        std::cout << " │";
        std::cout << std::endl;
    }
    std::cout << "└";
    for(int i = 0; i < width - 1; i++)
    {
        std::cout << "─";
        if(vertical_gates[i][height - 1])
        {
            std::cout << "┴";
        }else
        {
            std::cout << "─";
        }
    }
    std::cout << "──" << std::endl;
}
struct AbstractMaze::Cell AbstractMaze::index_to_cell(int index){
    struct Cell converted(
    converted.x = index % width,
    converted.y = index/width);
    return converted;
}
int AbstractMaze::cell_to_index(AbstractMaze::Cell incell){
    int converted = incell.x;
    converted += incell.y * width;
    return converted;
}