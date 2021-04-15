#include "binarytreemaze.h"

#include <stdlib.h> 

void BinaryTreeMaze::generate(int seed){

    srand(seed);
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(i == 0 && j == 0){
                continue;
            }
            else if(j == 0)
            {
                horizontal_gates[0][i-1] = false;
                continue;
            }
            else if(i == 0)
            {
                vertical_gates[j-1][0] = false;
                continue;
            }
            if(rand() % 2 == 0)
            {
                vertical_gates[j-1][i] = false;
            }else
            {
                horizontal_gates[j][i-1] = false;
            }
        }
    }
}