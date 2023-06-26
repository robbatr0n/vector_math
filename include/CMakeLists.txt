project(vector_math)

add_library(vector_math INTERFACE ${INTERFACE_FILES})

set(INTERFACE_FILES vector_math/vector3.hpp)

target_sources(vector_math
  INTERFACE 
  vector_math/vector3.hpp
)

target_include_directories(vector_math
    INTERFACE
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>)