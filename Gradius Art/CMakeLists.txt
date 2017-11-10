cmake_minimum_required(VERSION 3.8)
project(Gradius)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Game.cpp Game.h Display.cpp Display.h Player.cpp Player.h Enemy.cpp Enemy.h Enemy_manager.cpp Enemy_manager.h Event.cpp Event.h Bullet.cpp Bullet.h Bullet_manager.cpp Bullet_manager.h)
add_executable(Gradius ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Gradius ${SFML_LIBRARIES})
endif()