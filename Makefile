##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## file making
##

NAME	= 	my_gl

CC		=	gcc
CCP		=	g++

RM		= rm -f

CSRC	=	src/glad.c	                                \

CPPSRC	= 	main.cpp	                                \
                                                        \
			src/Window/Window.cpp	                    \
			src/Window/CameraHandling.cpp				\
														\
			src/Camera/Camera.cpp						\
														\
			src/Materials/Texture.cpp					\
			src/Materials/Material.cpp					\
                                                        \
			src/GraphicsPipeline/Shader.cpp	            \
			src/GraphicsPipeline/GraphicsPipeline.cpp	\
			                                            \
            src/Input/KeyboardHandler.cpp		        \
			src/Input/MouseHandler.cpp		            \
                                                        \
			src/Mesh/Mesh.cpp	                        \
			src/Mesh/Vertex.cpp		                    \
														\
			src/Transform/Transform.cpp					\

COBJ   = $(CSRC:.c=.o)
CPPOBJ = $(CPPSRC:.cpp=.o)
OBJ = $(COBJ) $(CPPOBJ)

INCLUDE 	= 	-I./include -I./interfaces
LIBFLAG    	= 	-lGL -lglfw -ldl
WARNINGFLAG = 	-Wall -Wextra -Werror -g3
CPPFLAGS 	+= 	$(INCLUDE) $(LIBFLAG) $(WARNINGFLAG)


all:  $(OBJ) compile

compile:
	$(CCP) $(OBJ) -o $(NAME) $(INCLUDE) $(LIBFLAG) $(WARNINGFLAG)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(OBJ)

re: fclean all
