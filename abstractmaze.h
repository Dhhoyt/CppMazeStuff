#ifndef __maze_h_
#define __maze_h_

#include <vector>

class AbstractMaze
{
    public:
        AbstractMaze(int _width, int _height);
        void print_maze();

        virtual void generate(int seed) = 0;
        int width;
        int height;
        std::vector<std::vector<bool>> horizontal_gates;
        std::vector<std::vector<bool>> vertical_gates;
        struct Wall {
            int x;
            int y;
            bool is_horizontal;
            Wall(int _x, int _y, bool _is_horizontal) : x(_x), y(_y), is_horizontal(_is_horizontal) {}
        };
        struct Cell {
            int x;
            int y;
            Cell(int _x, int _y) : x(_x), y(_y) {}
        };
        struct Cell index_to_cell(int index);
        int cell_to_index(Cell incell);
};

#endif