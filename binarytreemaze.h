#ifndef __binarytreemaze_h_
#define __binarytreemaze_h_

#include "abstractmaze.h"

class BinaryTreeMaze: public AbstractMaze
{
    public:
        using AbstractMaze::AbstractMaze;
        virtual void generate(int seed);
};

#endif