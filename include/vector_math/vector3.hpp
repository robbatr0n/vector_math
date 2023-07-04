/**
 * @file vector3.hpp
 * @author Rob Barton (@robmakesgames)
 * @brief Mathematical vector library
 * @version 0.2
 * @date 2023-06-25
 */

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <ostream>
#include <iostream>
#include <cmath>

/**
 * @brief A mathematical vector class with N dimensions.
 * @tparam dim The number of dimensions of the vector.
 * @tparam T The type of the vector elements.
 */
template <unsigned dim, typename T> class Vector {

  public:

    /**
     * @brief Construct a new Vector object setting all values to 0.
     */
    Vector() {
        for (unsigned i = 0; i < dim; i++) {
            data[i] = 0;
        }
    }

    /**
     * @brief Construct a new Vector object using the provided arguments.
     * @tparam Args The types of the vector values.
     * @param args The vector values.
     */
    template <typename... Args> Vector(Args... args) : data{args...} {}

    /**
     * @brief Returns the x component of the vector.
     * @return const auto&
     */
    const auto &X() const {
        return data[0];
    }

    /**
     * @brief Returns the y component of the vector if the vector size is at least 2.
     * @tparam D
     * @return const auto&
     */
    template <unsigned D = dim> typename std::enable_if<D >= 2, T>::type const &Y() const {
        return data[1];
    }

    /**
     * @brief Returns the z component of the vector if the vector size is at least 3.
     * @tparam D
     * @return const auto&
     */
    template <unsigned D = dim> typename std::enable_if<D >= 3, T>::type const &Z() const {
        return data[2];
    }

    /**
     * @brief Returns the w component of the vector if the vector size is at least 4.
     * @tparam D
     * @return const auto&
     */
    template <unsigned D = dim> typename std::enable_if<D >= 4, T>::type const &W() const {
        return data[3];
    }

    /**
     * @brief Overload subscript operator to access individual vector elements by their index.
     * @param index The index of the vector element.
     * @return auto&
     */
    auto &operator[](unsigned index) {
        return data[index];
    }

    /**
     * @brief Overload the << operator to print out the vector to stdout.
     * @param os The output stream.
     * @param vec The vector to print.
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Vector &vec) {
        os << "[";
        for (unsigned i = 0; i < dim; i++) {
            os << vec.data[i];
            if (i != dim - 1) {
                os << " ";
            }
        }
        os << "]";
        return os;
    }

    /**
     * @brief Overloads the + operator to add vectors together.
     * @param lhs The left hand side vector.
     * @param rhs The right hand side vector.
     * @return Vector - The result of the addition.
     */
    friend Vector operator+(const Vector &lhs, const Vector &rhs) {
        Vector result;
        for (unsigned i = 0; i < dim; ++i) {
            result.data[i] = lhs.data[i] + rhs.data[i];
        }
        return result;
    }

    /**
     * @brief Overloads the - operator to subtract vectors from one another.
     * @param lhs The left hand side vector.
     * @param rhs The right hand side vector.
     * @return Vector - The result of the subtraction.
     */
    friend Vector operator-(const Vector &lhs, const Vector &rhs) {
        Vector result;
        for (unsigned i = 0; i < dim; ++i) {
            result.data[i] = lhs.data[i] - rhs.data[i];
        }
        return result;
    }

    /**
     * @brief Overload the * operator to multiply a vector by a scalar.
     * @param vec The vector.
     * @param scalar The scalar value.
     * @return Vector<dim, T> - The result of the multiplication.
     */
    friend Vector operator*(const Vector &vec, const T &scalar) {
        Vector result;
        for (unsigned i = 0; i < dim; ++i) {
            result.data[i] = vec.data[i] * scalar;
        }
        return result;
    }

    /**
     * @brief Overload the * operator to multiply a scalar by a vector.
     * @param scalar The scalar value.
     * @param vec The vector.
     * @return Vector - The result of the multiplication.
     */
    friend Vector operator*(const T &scalar, const Vector &vec) {
        Vector result;
        for (unsigned i = 0; i < dim; ++i) {
            result.data[i] = scalar * vec.data[i];
        }
        return result;
    }

    /**
     * @brief Overload the / operator to divide a vector by a scalar.
     *
     * @param vec The vector.
     * @param scalar The scalar value.
     * @return Vector<dim, T> - The result of the division.
     */
    friend Vector operator/(const Vector &vec, const T &scalar) {
        Vector result;
        for (unsigned i = 0; i < dim; ++i) {
            result.data[i] = vec.data[i] / scalar;
        }
        return result;
    }

    /**
     * @brief Overloads the += operator to add a vector to the current vector.
     * @param rhs The vector to be added.
     * @return Vector& - Reference to the current vector.
     */
    Vector &operator+=(const Vector &rhs) {
        for (unsigned i = 0; i < dim; ++i) {
            data[i] += rhs.data[i];
        }
        return *this;
    }

    /**
     * @brief Overloads the -= operator to subtract a vector from the current vector.
     * @param rhs The vector to be subtracted.
     * @return Vector& - Reference to the current vector.
     */
    Vector &operator-=(const Vector &rhs) {
        for (unsigned i = 0; i < dim; ++i) {
            data[i] -= rhs.data[i];
        }
        return *this;
    }

    /**
     * @brief Overloads the /= operator to divide the current vector by a scalar.
     * @param scalar The scalar value for division.
     * @return Vector& - Reference to the current vector.
     */
    Vector &operator/=(const T &scalar) {
        for (unsigned i = 0; i < dim; ++i) {
            data[i] /= scalar;
        }
        return *this;
    }

    /**
     * @brief Overloads the *= operator to multiply the current vector by a scalar.
     * @param scalar The scalar value for multiplication.
     * @return Vector& - Reference to the current vector.
     */
    Vector &operator*=(const T &scalar) {
        for (unsigned i = 0; i < dim; ++i) {
            data[i] *= scalar;
        }
        return *this;
    }

    /**
     * @brief Calculates the length of the vector.
     * @return auto - The length of the vector.
     */
    inline auto Length() const {
        return std::sqrt(LengthSquared());
    }

    /**
     * @brief Calculates the squared length of the vector.
     * @return auto - The squared length of the vector.
     */
    inline auto LengthSquared() const {
        auto length = 0;
        for (unsigned i = 0; i < dim; i++) {
            length += data[i] * data[i];
        }
        return length;
    }

    /**
     * @brief Calculates the cross product between two vectors.
     * This function is only defined for 3D vectors.
     * @param rhs The right-hand side vector.
     * @return Vector<dim, T> - The cross product vector.
     */
    Vector Cross(const Vector &rhs) const {
        static_assert(dim == 3, "Cross product is only defined for 3D vectors.");
        Vector result;
        result[0] = data[1] * rhs.data[2] - data[2] * rhs.data[1];
        result[1] = data[2] * rhs.data[0] - data[0] * rhs.data[2];
        result[2] = data[0] * rhs.data[1] - data[1] * rhs.data[0];
        return result;
    }

    /**
     * @brief Calculates the dot product between two vectors.
     * @param rhs The right-hand side vector.
     * @return T - The dot product value.
     */
    T Dot(const Vector &rhs) const {
        T result = 0;
        for (unsigned i = 0; i < dim; ++i) {
            result += data[i] * rhs.data[i];
        }
        return result;
    }

    /**
     * @brief Calculates the dot product between two vectors.
     * @param lhs The left-hand side vector.
     * @param rhs The right-hand side vector.
     * @return T - The dot product value.
     */
    friend T Dot(const Vector &lhs, const Vector &rhs) {
        T result = 0;
        for (unsigned i = 0; i < dim; ++i) {
            result += lhs.data[i] * rhs.data[i];
        }
        return result;
    }

  private:

    T data[dim];
};

/**
 * @brief Creates a unit vector from the provided vector.
 * If the provided vector has a length of zero, the original vector is returned.
 * @tparam dim The dimension of the vector.
 * @tparam T The type of the vector components.
 * @param vec The input vector.
 * @return Vector<dim, T> - The unit vector.
 */
template <unsigned dim, typename T> Vector<dim, T> unit_vector(const Vector<dim, T> &vec) {
    T length = vec.Length();
    if (length != 0.0f) {
        return vec / length;
    }
    return vec;
}

using Vec2f = Vector<2, float>;
using Vec3f = Vector<3, float>;
using Vec4f = Vector<4, float>;

using Vec2d = Vector<2, double>;
using Vec3d = Vector<3, double>;
using Vec4d = Vector<4, double>;

#endif   // VECTOR3_HPP
