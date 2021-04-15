#include "primsmaze.h"  

#include <algorithm>
#include <random>
#include <vector>
#include <stdlib.h> 
#include <iostream>

std::vector<AbstractMaze::Wall> walls;
std::vector<AbstractMaze::Cell> cells;

void PrimsMaze::generate(int seed){
    for(int i; i < horizontal_gates.size(); i++){
        for(int j; j < horizontal_gates[0].size(); j++){
            horizontal_gates[i][j] = false;
        }
    }
    for(int i; i < vertical_gates.size(); i++){
        for(int j; j < vertical_gates[0].size(); j++){
            vertical_gates[i][j] = false;
        }
    }
    std::mt19937 rand(seed);

    Cell init_cell(
    init_cell.x = rand() % width,
    init_cell.y = rand() % height);
    add_cell(init_cell);
    add_walls(init_cell);
    while (walls.size() > 0){
        //std::cout << walls.size() << "\r";
        Wall current = walls.random_element<std::mt19937>(rand);
        if(current.is_horizontal){
            AbstractMaze::Cell upper(current.x, current.y);
            if(!in_cells(upper)){
                horizontal_gates[current.x][current.y] = false;
                add_cell(upper);
                add_walls(upper);
            }
            AbstractMaze::Cell lower(current.x, current.y+1);
            if(!in_cells(lower)){
                horizontal_gates[current.x][current.y] = false;
                add_cell(lower);
                add_walls(lower);
            }
        }else{
            AbstractMaze::Cell left(current.x, current.y);
            if(!in_cells(left)){
                
                vertical_gates[current.x][current.y] = false;
                add_cell(left);
                add_walls(left);
            }
            AbstractMaze::Cell right(current.x+1, current.y);
            if(!in_cells(right)){
                vertical_gates[current.x][current.y] = false;
                add_cell(right);
                add_walls(right);
            }
        }
        walls.erase(current);
    }
    
}

void PrimsMaze::add_walls(AbstractMaze::Cell incell){
    AbstractMaze::Wall upper(incell.x, incell.y -1, true);
    if(incell.y > 0){
        walls.insert(upper);
    }
    AbstractMaze::Wall lower(incell.x, incell.y, true);
    if(incell.y < height - 1){
        walls.insert(lower);
    }
    AbstractMaze::Wall left(incell.x - 1, incell.y, false);
    if(incell.x > 0){
        walls.insert(left);
    }
    AbstractMaze::Wall right(incell.x, incell.y, false);
    if(incell.x < width - 1){
        walls.insert(right);
    }
}

bool PrimsMaze::in_walls(AbstractMaze::Wall inwall){
    return walls.has(inwall);
}

bool PrimsMaze::in_cells(AbstractMaze::Cell incell){
    return cells.find(incell) != cells.end();
}

void PrimsMaze::add_cell(AbstractMaze::Cell incell){
    cells.insert(incell);
}
