#ifndef __primsmaze_h_
#define __primsmaze_h_

#include "abstractmaze.h"

class PrimsMaze: public AbstractMaze
{

    public:
        using AbstractMaze::AbstractMaze;
        void generate(int seed);
    private:
        std::vector<AbstractMaze::Wall> walls;
        std::vector<AbstractMaze::Cell> cells;
        void add_walls(AbstractMaze::Cell incell);
        bool in_walls(AbstractMaze::Wall inwall);
        bool in_cells(AbstractMaze::Cell incell);
};

#endif