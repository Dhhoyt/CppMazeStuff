#ifndef __primsmaze_h_
#define __primsmaze_h_

#include <set>

#include "abstractmaze.h"
#include "randomunorderedset.h"


class PrimsMaze: public AbstractMaze
{

    public:
        using AbstractMaze::AbstractMaze;
        void generate(int seed);
    private:
        RandomUnorderedSet<AbstractMaze::Wall> walls;
        std::set<AbstractMaze::Cell> cells;
        void add_cell(AbstractMaze::Cell incell);
        void add_walls(AbstractMaze::Cell incell);
        bool in_walls(AbstractMaze::Wall inwall);
        bool in_cells(AbstractMaze::Cell incell);
};

#endif
