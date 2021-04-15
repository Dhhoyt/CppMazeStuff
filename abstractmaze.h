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

        class Wall {
            public:
                int x;
                int y;  
                bool is_horizontal;
                Wall(int _x, int _y, bool _is_horizontal) : x(_x), y(_y), is_horizontal(_is_horizontal) {}
                bool operator==(const Wall& other) const{
                    return x == other.x && y == other.y && is_horizontal == other.is_horizontal;
                }
                
        };
        class Cell {
            public:
                int x;
                int y;
                Cell(int _x, int _y) : x(_x), y(_y) {}
                bool operator<(const Cell& other) const {
                    if(x == other.x){
                        return y < other.y;
                    }
                    return x < other.x;
                }
        };
        struct Cell index_to_cell(int index);
        int cell_to_index(Cell incell);
};
namespace std {

    template <>
    struct hash<AbstractMaze::Wall>{
        std::size_t operator()(const AbstractMaze::Wall& inwall) const {
            return ((std::hash<int>()(inwall.x)
                ^ (std::hash<int>()(inwall.y) << 1)) >> 1)
                ^ (std::hash<bool>()(inwall.is_horizontal) << 1);
        }
    };
};
#endif
