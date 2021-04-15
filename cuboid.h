#ifndef __cuboid_h_
#define __cuboid_h_

#include <algorithm>
#include "vector.h"



template<class T>
class Cuboid
{
    public:
        Vector3<T> min;
        Vector3<T> max;
        Cuboid(Vector3<T> _min, Vector3<T> _max)
        {
            min.x = std::min(_min.x, _max.x);
            max.x = std::max(_min.x, _max.x);
            min.y = std::min(_min.y, _max.y);
            max.y = std::max(_min.y, _max.y);
            min.z = std::min(_min.z, _max.z);
            max.z = std::max(_min.z, _max.z);
        }
        friend std::ostream &operator<<(std::ostream &os, const Cuboid<T> &cub)
        {
            os << "Cube from " << cub.min << " to " << cub.max;
            return os; 
        }
        bool collides(const Cuboid<T> &second)
        {
            if(!(second.min.x < max.x && min.x < second.max.x)){ return false; }
            if(!(second.min.y < max.y && min.y < second.max.y)){ return false; }
            if(!(second.min.z < max.z && min.z < second.max.z)){ return false; }
            return true;
        }
};

#endif