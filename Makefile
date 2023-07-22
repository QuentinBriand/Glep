##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## file making
##

LIBNAME = 	libglep.a

CC		=	gcc
CCP		=	g++

RM		= rm -f

C_SRC	=	src/glad.c	                                \

EXAMPLE_SRC =   main.cpp                                \
				scene.cpp								\

CPP_SRC	=	src/Window/Window.cpp	                    \
			src/Window/CameraHandling.cpp				\
														\
			src/Camera/Camera.cpp						\
														\
			src/Materials/Texture.cpp					\
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

C_OBJ   = $(C_SRC:.c=.o)
CPP_OBJ = $(CPP_SRC:.cpp=.o)

ALL_OBJ = $(C_OBJ) $(CPP_OBJ)
EXAMPLE_OBJ = $(EXAMPLE_SRC:.cpp=.o)

INCLUDE 	= 	-I./include -I./interfaces
LIBFLAG    	= 	-lGL -lglfw -ldl
WARNINGFLAG = 	-Wall -Wextra -Werror -g3

CFLAGS 		= 	$(WARNINGFLAG) $(INCLUDE)
CPPFLAGS 	= 	$(WARNINGFLAG) $(INCLUDE) $(LIBFLAG)

all: $(EXAMPLE_OBJ) lib
	$(CCP) -o example $(EXAMPLE_OBJ) $(CFLAGS) $(CPPFLAGS) -L. -lglep

lib: $(ALL_OBJ)
	ar rc $(LIBNAME) $(ALL_OBJ)

re: fclean all

clean:
	rm -f $(ALL_OBJ)

fclean: clean
	rm -f $(LIBNAME)
	rm -f example
