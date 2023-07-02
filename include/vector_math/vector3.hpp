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

template <unsigned dim, typename T> class Vector {
  public:

    /**
     * @brief Construct a new Vector object setting all values to 0
     */
    Vector() {
        for (unsigned i = 0; i < dim; i++) {
            data[i] = 0;
        }
    }

    /**
     * @brief Construct a new Vector object using the provided arguments
     * @tparam Args - vector type
     * @param args - vector values
     */
    template <typename... Args> Vector(Args... args) : data{args...} {}

    /**
     * @brief returns the x component of a vector
     * @return const auto&
     */
    const auto &X() const {
        return data[0];
    }

    /**
     * @brief returns the y component of a vector if the vector size is at least 2
     * @tparam D
     */
    template <unsigned D = dim> typename std::enable_if<D >= 2, T>::type const &Y() const {
        return data[1];
    }

    /**
     * @brief returns the z component of a vector if the vector size is at least 3
     * @tparam D
     */
    template <unsigned D = dim> typename std::enable_if<D >= 3, T>::type const &Z() const {
        return data[2];
    }

    /**
     * @brief returns the w component of a vector if the vector size is at least 4
     * @tparam D
     */
    template <unsigned D = dim> typename std::enable_if<D >= 4, T>::type const &W() const {
        return data[3];
    }

    /**
     * @brief
     * @return auto
     */
    inline auto Length() const {
        return std::sqrt(LengthSquared());
    }

    /**
     * @brief
     * @return auto
     */
    inline auto LengthSquared() const {
        auto length = 0;
        for (unsigned i = 0; i < dim; i++) {
            length += data[i] * data[i];
        }

        return length;
    }

    /**
     * @brief Overload subscript operator to access individual vector elements
     * by their index
     * @param index
     * @return auto&
     */
    auto &operator[](unsigned index) {
        return data[index];
    }

    /**
     * @brief Overload the << operator to print out the vector to stdout
     * @param os - output stream
     * @param vec - vector to print
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
     * @brief Overloads the + operator to add vectors together
     * @param lhs - left hand side vector
     * @param rhs - right hand side vector
     * @return Vector - result
     */
    friend Vector operator+(const Vector &lhs, const Vector &rhs) {
        Vector result;
        for (unsigned i = 0; i < dim; ++i) {
            result.data[i] = lhs.data[i] + rhs.data[i];
        }
        return result;
    }

    /**
     * @brief Overloads the - operator to subtract vectors from one another
     * @param lhs - left hand side vector
     * @param rhs - right hand side vector
     * @return Vector - result
     */
    friend Vector operator-(const Vector &lhs, const Vector &rhs) {
        Vector result;
        for (unsigned i = 0; i < dim; ++i) {
            result.data[i] = lhs.data[i] - rhs.data[i];
        }
        return result;
    }

    /**
     * @brief Overload the * operator to multiply a vector by a scalar
     * @param vec - vector
     * @param scalar - scalar value
     * @return Vector<dim, T> - result of the multiplication
     */
    friend Vector operator*(const Vector &vec, const T &scalar) {
        Vector result;
        for (unsigned i = 0; i < dim; ++i) {
            result.data[i] = vec.data[i] * scalar;
        }
        return result;
    }

  private:

    T data[dim];
};

#endif
