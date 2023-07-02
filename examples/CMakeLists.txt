project(vector_math)

add_executable(main main.cpp ray.hpp)

target_link_libraries(main PRIVATE vector_math)