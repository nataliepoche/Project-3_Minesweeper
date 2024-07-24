cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Project_3)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "C:/Users/Owner/CLionProjects/Project_3/SFML-2.5.1/lib/cmake/SFML")

# links library components to the program
find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)
add_executable(Project_3 main.cpp
        project.cpp
        welcomeWindow.h
        Project/project.cpp
        gameWindow.h
        class/colorChangingPikachu.cpp
        class/class.cpp
        class/cardGame.cpp
        class/card.h
        class/card.cpp
        leaderBoard.h)
target_link_libraries(Project_3 sfml-system sfml-window sfml-graphics sfml-audio)