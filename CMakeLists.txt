# Legt die minimal erforderliche CMake-Version fest.
cmake_minimum_required(VERSION 3.10)

# Definiert den Projektnamen.
project(Asteroids)

# Fügt die ausführbare Datei "Snake" hinzu und listet alle Quelldateien auf,
# die zum Kompilieren benötigt werden.
add_executable(Asteroid.x
    Asteroid/Asteroid.cpp
    Asteroid/Bullet.cpp
    Asteroid/Game.cpp
    Asteroid/Main.cpp
    Asteroid/Ship.cpp
)

target_link_libraries(Asteroid.x 
    PRIVATE 
        sfml-graphics 
        sfml-window 
        sfml-system
)

# Setzt den C++ Standard. C++11, 14, 17 oder 20 sind übliche Werte.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)