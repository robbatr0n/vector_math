#include <iostream>
#include <vector_math/vector3.hpp>

int main() {
    Vector3 v1(10, 20, 30);
    std::cout << v1 << std::endl;
    Vector3 v2(40, 30, 20);
    std::cout << v2 << std::endl;
    std::cout << v1.Cross(v2) << std::endl;
    return 0;
}