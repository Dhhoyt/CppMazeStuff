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
    cells.push_back(init_cell);
    add_walls(init_cell);
    while (walls.size() > 0){
        std::cout << walls.size() << "\r";
        int wall_index = rand() % walls.size();
        Wall current = walls.at(wall_index);
        if(current.is_horizontal){
            AbstractMaze::Cell upper(current.x, current.y);
            if(!in_cells(upper)){
                horizontal_gates[current.x][current.y] = false;
                cells.push_back(upper);
                add_walls(upper);
            }
            AbstractMaze::Cell lower(current.x, current.y+1);
            if(!in_cells(lower)){
                horizontal_gates[current.x][current.y] = false;
                cells.push_back(lower);
                add_walls(lower);
            }
        }else{
            AbstractMaze::Cell left(current.x, current.y);
            if(!in_cells(left)){
                
                vertical_gates[current.x][current.y] = false;
                cells.push_back(left);
                add_walls(left);
            }
            AbstractMaze::Cell right(current.x+1, current.y);
            if(!in_cells(right)){
                vertical_gates[current.x][current.y] = false;
                cells.push_back(right);
                add_walls(right);
            }
        }
        walls.erase(walls.begin() + wall_index);
    }
    
}

void PrimsMaze::add_walls(AbstractMaze::Cell incell){
    AbstractMaze::Wall upper(incell.x, incell.y -1, true);
    if(incell.y > 0 && !in_walls(upper)){
        walls.push_back(upper);
    }
    AbstractMaze::Wall lower(incell.x, incell.y, true);
    if(incell.y < height - 1 && !in_walls(lower)){
        walls.push_back(lower);
    }
    AbstractMaze::Wall left(incell.x - 1, incell.y, false);
    if(incell.x > 0 && !in_walls(left)){
        walls.push_back(left);
    }
    AbstractMaze::Wall right(incell.x, incell.y, false);
    if(incell.x < width - 1 && !in_walls(right)){
        walls.push_back(right);
    }
}

bool PrimsMaze::in_walls(AbstractMaze::Wall inwall){
    for(int i = 0; i < walls.size(); i++){
        AbstractMaze::Wall& current_wall = walls.at(i);
        if(inwall.x == current_wall.x && inwall.y == current_wall.y && inwall.is_horizontal == current_wall.is_horizontal){
            return true;
        }
    }
    return false;
}

bool PrimsMaze::in_cells(AbstractMaze::Cell incell){
    for(int i = 0; i < cells.size(); i++){
        AbstractMaze::Cell& current_cell = cells.at(i);
        if(incell.x == current_cell.x && incell.y == current_cell.y){
            return true;
        }
    }
    return false;
}