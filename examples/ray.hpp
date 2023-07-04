#ifndef RAY_H
#define RAY_H

#include <vector_math/vector3.hpp>

class ray {
  public:

    ray() {}
    ray(const Vec3f &origin, const Vec3f &direction) : ray_origin(origin), ray_direction(direction) {}

    Vec3f GetOrigin() const {
        return ray_origin;
    }
    Vec3f GetDirection() const {
        return ray_direction;
    }

    Vec3f GetPointAt(float t) const {
        return ray_origin + t * ray_direction;
    }

  private:

    Vec3f ray_origin;
    Vec3f ray_direction;
};

#endif