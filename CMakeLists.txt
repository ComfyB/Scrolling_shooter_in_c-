cmake_minimum_required(VERSION 3.21)
project(cpp_eksamen3)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_eksamen3 main.cpp src/Game/Game.cpp src/Game/Game.h src/Game/TextureManager.cpp src/Game/TextureManager.h src/SupportClasses/Vector2D.h src/GameObjects/GameObject.cpp src/GameObjects/GameObject.h src/SupportClasses/ObjectParamLoader.h src/GameObjects/Player.cpp src/GameObjects/Player.h src/InputHandler/InputHandler.cpp src/InputHandler/InputHandler.h src/GameObjects/Enemy.cpp src/GameObjects/Enemy.h src/SupportClasses/Randomizer.cpp src/SupportClasses/Randomizer.h src/GameObjects/Projectile.cpp src/GameObjects/Projectile.h src/GameObjects/HealthBar.cpp src/GameObjects/HealthBar.h src/SupportClasses/SoundLoader.cpp src/SupportClasses/SoundLoader.h)



INCLUDE(FindPkgConfig)
find_package(SDL2 REQUIRED)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
include_directories(${SDL2_INCLUDE_DIRS}
        ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS} )

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LINK_LIBRARIES} ${SDL2TTF_LINK_LIBRARIES} ${SDL2MIXER_LINK_LIBRARIES})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")