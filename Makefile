##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC_DIR = $(realpath ./srcs)

SRC_DIR_ENGINE =	$(realpath ./srcs/engine)

SRC_DIR_GAME	=	$(realpath ./srcs/bomberman)

SRC_E	=	$(SRC_DIR_ENGINE)/SoundSfml.cpp \
			$(SRC_DIR_ENGINE)/Irrlicht.cpp \
			$(SRC_DIR_ENGINE)/AEngine.cpp \
			$(SRC_DIR_ENGINE)/MyEventReceiver.cpp \
			$(SRC_DIR_ENGINE)/IrrlichtEngine.cpp
OBJ_E	=	$(SRC_E:.cpp=.o)

SRC_G	=	$(SRC_DIR_GAME)/Wall.cpp \
		$(SRC_DIR)/Bomberman.cpp \
		$(SRC_DIR)/States/SoloModeGameState.cpp \
		$(SRC_DIR)/States/MainMenu.cpp \
		$(SRC_DIR)/States/VSModeGameState.cpp \
		$(SRC_DIR)/Scenes/SetTypeGameScene.cpp \
		$(SRC_DIR)/Scenes/SoloModeSettingScene.cpp \
		$(SRC_DIR)/Scenes/SoloModeGameScene.cpp \
		$(SRC_DIR)/Scenes/VSModeGameScene.cpp \
		$(SRC_DIR)/Scenes/PlayerSetting.cpp \
		$(SRC_DIR)/Scenes/VSModeSettingScene.cpp \
		$(SRC_DIR)/IA/Behavior.cpp \
		$(SRC_DIR_GAME)/MapObserver.cpp \
		$(SRC_DIR_GAME)/Character.cpp \
		$(SRC_DIR_GAME)/Player.cpp \
		$(SRC_DIR_GAME)/GameMode.cpp \
		$(SRC_DIR_GAME)/IAController.cpp \
		$(SRC_DIR_GAME)/Bomb.cpp \
		$(SRC_DIR_GAME)/ABomb.cpp \
		$(SRC_DIR_GAME)/PowerStat.cpp \
		$(SRC_DIR_GAME)/Trap.cpp \
		$(SRC_DIR_GAME)/Job/Marathonian.cpp \
		$(SRC_DIR_GAME)/Job/Illusioniste.cpp \
		$(SRC_DIR_GAME)/Job/Builder.cpp \
		$(SRC_DIR_GAME)/Job/Hunter.cpp \
		$(SRC_DIR_GAME)/Floor.cpp \
		$(SRC_DIR)/PlayerController.cpp \
		$(SRC_DIR)/main.cpp

##		$(SRC_DIR_GAME)/Bomb.cpp \
		$(SRC_DIR_GAME)/ABomb.cpp\
		$(SRC_DIR_GAME)/APowerUp.cpp \

OBJ_G	=	$(SRC_G:.cpp=.o)

LDFLAGS_E	=	-lsfml-system -lsfml-audio -lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXcursor -lpthread

CXXFLAGS =	-g -Wall -Wextra -Werror -std=c++17 -I ./includes

CC	=	g++

NAME	=	bomberman

GAME =	game

ENGINE = engine

all:	$(NAME)

$(NAME): $(OBJ_G) $(OBJ_E)
		@$(CC) -o $(NAME) $(OBJ_E) $(OBJ_G) $(LDFLAGS_E)

$(GAME): $(OBJ_G)
		@$(CC) -o $(GAME) $(OBJ_G)

$(ENGINE): $(OBJ_E)
		@$(CC) -o $(ENGINE) $(OBJ_E) $(LDFLAGS_E)

.PHONY:	clean	fclean

clean:
	@rm -rf $(SRC_DIR)/*.o
	@rm -rf $(SRC_DIR)*~
	@rm -rf $(SRC_DIR_GAME)/*.o
	@rm -rf $(SRC_DIR_GAME)/*~
	@rm -rf $(SRC_DIR_ENGINE)/*.o
	@rm -rf $(SRC_DIR_ENGINE)/*~
	@rm -rf $(OBJ_G)
	@rm -rf vgcore.*

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(GAME)
	@rm -rf $(ENGINE)

re: fclean all
