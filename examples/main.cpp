/**
 * @file main.cpp
 * @author Rob Barton (@robmakesgames)
 * @brief Simple ray tracer built as a useage example for the vector library
 * @version 0.1
 * @date 2023-06-28
 */

#include <iostream>
#include <vector_math/vector3.hpp>
#include "ray.hpp"

bool hit_sphere(const Vec3f &center, double radius, const ray &r) {
    Vec3f oc = r.GetOrigin() - center;
    auto a = Dot(r.GetDirection(), r.GetDirection());
    auto b = 2.0f * Dot(oc, r.GetDirection());
    auto c = Dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4.0f * a * c;
    return (discriminant > 0.0f);
}

Vec3f ray_color(const ray &r) {
    if (hit_sphere(Vec3f(0.0f, 0.0f, -1.0f), 0.5f, r))
        return Vec3f(1.0f, 0.0f, 0.0f);
    Vec3f unit_direction = unit_vector(r.GetDirection());
    auto t = 0.5f * (unit_direction.Y() + 1.0f);
    return (1.0f - t) * Vec3f(1.0f, 1.0f, 1.0f) + t * Vec3f(0.5f, 0.7f, 1.0f);
}

void write_color(std::ostream &out, Vec3f pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.X()) << ' ' << static_cast<int>(255.999 * pixel_color.Y()) << ' '
        << static_cast<int>(255.999 * pixel_color.Z()) << '\n';
}

int main() {

    // Image
    const auto aspect_ratio = 16.0f / 9.0f;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // Camera
    float viewport_height = 2.0f;
    float viewport_width = aspect_ratio * viewport_height;
    float focal_length = 1.0f;

    auto origin = Vec3f(0.0f, 0.0f, 0.0f);
    auto horizontal = Vec3f(viewport_width, 0.0f, 0.0f);
    auto vertical = Vec3f(0.0f, viewport_height, 0.0f);
    auto lower_left_corner = origin - horizontal / 2.0f - vertical / 2.0f - Vec3f(0.0f, 0.0f, focal_length);

    // Write output.ppm header
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // Loop through each image pixel - left to right, top to bottom
    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            // Calculate each pixels colour value and write it to stdout
            auto u = float(i) / (image_width - 1);
            auto v = float(j) / (image_height - 1);
            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            Vec3f pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
    return 0;
}