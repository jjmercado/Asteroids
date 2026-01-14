cmake_minimum_required(VERSION 3.10)

project(Asteroids)

add_executable(Asteroid.x
    Asteroids/Asteroid.cpp
    Asteroids/Bullet.cpp
    Asteroids/Game.cpp
    Asteroids/Main.cpp
    Asteroids/Ship.cpp
)

target_link_libraries(Asteroid.x 
    PRIVATE 
        sfml-graphics 
        sfml-window 
        sfml-system
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/assets)

file(COPY assets/ DESTINATION ${CMAKE_BINARY_DIR}/assets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)