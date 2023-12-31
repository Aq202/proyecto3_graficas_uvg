cmake_minimum_required(VERSION 3.22)

project(GAME VERSION 1.0)


# Enable C++20 features
set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

# Set SDL2_DIR if SDL2 is installed in a non-standard location
set(SDL2_DIR "D:/development/SDL2-2.28.1/cmake") # Replace with the actual path
set(SDL2_image_DIR "D:/development/SDL2_image/cmake") 


# Find SDL2
find_package(SDL2 REQUIRED PATHS "D:/development/SDL2-2.28.1")
find_package(SDL2_image REQUIRED PATHS "D:/development/SDL2_image")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(${PROJECT_NAME}
    src/main.cpp
    ${SOURCES}
)

# Link against SDL2 libraries
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main SDL2::SDL2)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2_image::SDL2_image)
