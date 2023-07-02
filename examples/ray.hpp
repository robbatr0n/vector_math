// #ifndef RAY_H
// #define RAY_H

// #include <vector_math/vector3.hpp>

// class ray {
//   public:
//     ray() {}
//     ray(const Vector3<float> &origin, const Vector3<float> &direction) : ray_origin(origin), ray_direction(direction)
//     {}

//     Vector3<float> get_origin() const {
//         return ray_origin;
//     }
//     Vector3<float> get_direction() const {
//         return ray_direction;
//     }

//     Vector3<float> get_point_at(float t) const {
//         return ray_origin + t * ray_direction;
//     }

//   private:
//     Vector3<float> ray_origin;
//     Vector3<float> ray_direction;
// };

// #endif