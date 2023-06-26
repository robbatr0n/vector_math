/**
 * @file vector3.hpp
 * @author Rob Barton (@robmakesgames)
 * @brief Mathematical vector libnary
 * @version 0.1
 * @date 2023-06-25
 *
 */

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <ostream>
#include <iostream>
#include <cmath>

template <typename T> class Vector3 {

  public:
    // Vector components
    T x;
    T y;
    T z;

    /**
     * @brief Construct a new Vector 3 object.
     * @param _x - Vector's x component
     * @param _y - Vector's y component
     * @param _z - Vector's z component
     */
    Vector3(T _x = 0, T _y = 0, T _z = 0) : x(_x), y(_y), z(_z) {}

    /**
     * @brief Calculates the dot product of the vector with another
     * @param other
     * @return T - dot product is always a scalar
     */
    T Dot(const Vector3<T> &other) const {
        return (x * other.x) + (y * other.y) + (z * other.z);
    }

    /**
     * @brief
     * @param other
     * @return Vector3<T>
     */
    Vector3<T> Cross(const Vector3<T> &other) const {
        T cx = y * other.z - z * other.y;
        T cy = z * other.x - x * other.z;
        T cz = x * other.y - y * other.x;
        return Vector3<T>(cx, cy, cz);
    }

    /**
     * @brief Operator overload to add two vectors together
     * @param other
     * @return Vector3<T>
     */
    Vector3<T> operator+(const Vector3<T> &other) const {
        return Vector3<T>(x + other.x, y + other.y, z + other.z);
    }

    /**
     * @brief Operator overload to subtract two vectors
     * @param other
     * @return Vector3<T>
     */
    Vector3<T> operator-(const Vector3<T> &other) const {
        return Vector3<T>(x - other.x, y - other.y, z - other.z);
    }

    /**
     * @brief Operator overload to multiply a vector and a scalar
     * @param other
     * @return Vector3<T>
     */
    Vector3<T> operator*(const T &scalar) const {
        return Vector3<T>(x * scalar, y * scalar, z * scalar);
    }

    /**
     * @brief Operator overload to print a vector to stdout
     * @param os
     * @param vec
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Vector3<T> &vec) {
        os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return os;
    }

    /**
     * @brief Gets the length of a vector
     * @return T
     */
    T Length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    /**
     * @brief Gets a normalised version of a vector
     * @return Vector3<T>
     */
    Vector3<T> Normalize() const {
        T vector_length = Length();
        T nx = x / vector_length;
        T ny = y / vector_length;
        T nz = z / vector_length;
        return Vector3<T>(nx, ny, nz);
    }
};

#endif

//////
// normalize
// cross
// dot
// overload operators
// vectort length
// aliases