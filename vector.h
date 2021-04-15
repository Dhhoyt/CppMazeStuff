#ifndef __vector_h_
#define __vector_h_

#include <ostream>

template<class T>
class Vector3
{
    public:
        T x;
        T y;
        T z;
        Vector3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
        Vector3() : x(0), y(0), z(0) {}
        Vector3<T> operator+(const Vector3<T> &other)
        {
            return Vector3<T>(x + other.x, y + other.y, z + other.z);
        }
        friend std::ostream &operator<<(std::ostream &os, const Vector3<T> &vec)
        {
            os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
            return os; 
        }
};

#endif