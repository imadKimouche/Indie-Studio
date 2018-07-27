cmake_minimum_required(VERSION 3.0)
PROJECT(bomberman)
SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}" "${CMAKE_MODULE_PATH}")
set(LIBRARY_SEARCH_PATH
  /usr/local
  /opt/local
  /usr
  /opt
)


set(HEADER_SEARCH_PATH
  /usr/local
  /opt/local
  /usr
  /opt
)

FIND_PACKAGE(Irrlicht)
find_package(OpenGL)
find_package(X11)


find_path(GLFW_INCLUDE_DIR GLFW/glfw3.h ${HEADER_SEARCH_PATH})


find_library(GLFW_LIBRARIES glfw3 ${LIBRARY_SEARCH_PATH})


set( ADDITIONAL_LIBS 
     -lGLU 
     -pthread
     -lrt
     -lXinerama
     -lXrandr
     -lXxf86vm
     -lXi
     -lIrrlicht
     -lGL
     -lXext
     -lX11
     -lXcursor
     -lsfml-system
     -lsfml-audio
)


set(INCLUDE_PATH
  ${OPENGL_INCLUDE_DIR}
)


set(LIBRARIES
  ${OPENGL_LIBRARIES}
  ${X11_LIBRARIES}
  ${ADDITIONAL_LIBS}  
)


find_path(GLEW_INCLUDE_DIR GL/glew.h
    ${HEADER_SEARCH_PATH}
)


set(INCLUDE_PATH ${INCUDE_PATH}
    ${GLEW_INCLUDE_DIR} 
    )
set(EXECUTABLE_OUTPUT_PATH ../)

INCLUDE_DIRECTORIES(
  ../includes
  "./include/irr/irrlicht"
  ${SFML_INCLUDE_DIR}
  )
SET(bomberman_SOURCE_FILES
  ../includes/Engine/AEngine.hpp
  ../includes/Engine/IEngine.hpp
  ../includes/Engine/MyEventReceiver.hpp
  ../includes/Engine/IInput.hpp
  ../includes/Engine/Irrlicht.hpp
  ../includes/Engine/SoundSfml.hpp
  ../includes/Engine/ICamera.hpp
  ../includes/Engine/IGui.hpp
  ../includes/Engine/IrrlichtEngine.hpp
  ../includes/Engine/ISound.hpp
  ../includes/Bomberman/GameObject/Floor.hpp
  ../includes/Bomberman/GameObject/Trap.hpp
  ../includes/Bomberman/Job/Builder.hpp
  ../includes/Bomberman/Job/Hunter.hpp
  ../includes/Bomberman/Job/Illusioniste.hpp
  ../includes/Bomberman/Job/Marathonian.hpp
  ../includes/Scenes/SoloModeGameScene.hpp
  ../includes/Scenes/VSModeGameScene.hpp
  ../includes/Scenes/IScene.hpp
  ../includes/Scenes/SetTypeGameScene.hpp
  ../includes/Scenes/SoloModeSettingScene.hpp
  ../includes/Scenes/PlayerSetting.hpp
  ../includes/Scenes/VSModeSettingScene.hpp
  ../includes/Scenes/SoloModeGameScene.hpp
  ../includes/Scenes/PlayerSetting.hpp
  ../includes/States/IState.hpp
  ../includes/States/MainMenu.hpp
  ../includes/States/VSModeGameState.hpp
  ../includes/States/IStateProtocol.hpp
  ../includes/States/SoloModeGameState.hpp
  ../includes/States/VSModeSetting.hpp
  ../includes/ABomb.hpp
  ../includes/AObject2D.hpp
  ../includes/AObject3D.hpp
  ../includes/AObjectText.hpp
  ../includes/APowerUp.hpp
  ../includes/Behavior.hpp
  ../includes/Bomberman.hpp
  ../includes/BombermanProtocol.hpp
  ../includes/Bomb.hpp
  ../includes/Background.hpp
  ../includes/Behavior.hpp
  ../includes/Character.hpp
  ../includes/Coord.hpp
  ../includes/GameMode.hpp
  ../includes/GameModeProtocol.hpp
  ../includes/IAController.hpp
  ../includes/IController.hpp
  ../includes/Image.hpp
  ../includes/IObject.hpp
  ../includes/MapObserver.hpp
  ../includes/Musician.hpp
  ../includes/ObjTest.hpp
  ../includes/PlayerController.hpp
  ../includes/Player.hpp
  ../includes/PowerStat.hpp
  ../includes/Text.hpp
  ../includes/Wall.hpp
  ../srcs/Bomberman.cpp
  ../srcs/bomberman/Floor.cpp
  ../srcs/bomberman/Trap.cpp
  ../srcs/bomberman/GameMode.cpp
  ../srcs/bomberman/IAController.cpp
  ../srcs/bomberman/Wall.cpp
  ../srcs/bomberman/MapObserver.cpp
  ../srcs/bomberman/Character.cpp
  ../srcs/bomberman/Player.cpp
  ../srcs/bomberman/Bomb.cpp
  ../srcs/bomberman/ABomb.cpp
  ../srcs/bomberman/PowerStat.cpp
  ../srcs/bomberman/Job/Builder.cpp
  ../srcs/bomberman/Job/Hunter.cpp
  ../srcs/bomberman/Job/Illusioniste.cpp
  ../srcs/bomberman/Job/Marathonian.cpp
  ../srcs/bomberman/Job/Thief.cpp
  ../srcs/States/MainMenu.cpp
  ../srcs/States/SoloModeGameState.cpp
  ../srcs/States/VSModeGameState.cpp
  ../srcs/Scenes/SetTypeGameScene.cpp
  ../srcs/Scenes/SoloModeSettingScene.cpp
  ../srcs/Scenes/PlayerSetting.cpp
  ../srcs/Scenes/VSModeGameScene.cpp
  ../srcs/Scenes/SoloModeGameScene.cpp
  ../srcs/Scenes/VSModeSettingScene.cpp
  ../srcs/Scenes/PlayerSetting.cpp
  ../srcs/PlayerController.cpp
  ../srcs/main.cpp
  ../srcs/engine/AEngine.cpp
  ../srcs/engine/MyEventReceiver.cpp
  ../srcs/PlayerController.cpp
  ../srcs/engine/Irrlicht.cpp
  ../srcs/engine/IrrlichtEngine.cpp
  ../srcs/engine/SoundSfml.cpp
  ../srcs/IA/Behavior.cpp
  )

ADD_EXECUTABLE(bomberman WIN32  ${bomberman_SOURCE_FILES})

TARGET_LINK_LIBRARIES(bomberman
 ${IRRLICHT_LIBRARIES}
 ${LIBRARIES}
 )
