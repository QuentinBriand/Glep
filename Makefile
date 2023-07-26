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

C_SRC	=	external/glad/glad.c							\

CPP_SRC	=	libglep/Window.cpp								\
			libglep/Graphics/PhongMaterial.cpp				\
			libglep/Graphics/PointLight.cpp					\
			libglep/Graphics/Texture.cpp					\
															\
			libglep/GraphicsPipeline/GraphicsPipeline.cpp	\
			libglep/GraphicsPipeline/Shader.cpp				\
															\
			libglep/Input/KeyboardHandler.cpp				\
			libglep/Input/MouseHandler.cpp					\
															\
			libglep/Model/Mesh.cpp							\
			libglep/Model/Vertex.cpp						\
															\
			libglep/Camera.cpp								\
			libglep/CameraHandling.cpp						\
			libglep/Transform.cpp							\

C_OBJ   = $(C_SRC:.c=.o)
CPP_OBJ = $(CPP_SRC:.cpp=.o)

ALL_OBJ = $(C_OBJ) $(CPP_OBJ)

INCLUDE 	= 	-I./interfaces -I./external -I./libglep
LIBFLAG    	= 	-lGL -lglfw -ldl
WARNINGFLAG = 	-Wall -Wextra -Werror

CFLAGS 		+= 	$(INCLUDE) $(WARNINGFLAG)
CPPFLAGS 	= 	$(INCLUDE) $(LIBFLAG) $(WARNINGFLAG)

all: $(EXAMPLE_OBJ) lib

lib: $(ALL_OBJ)
	ar rc $(LIBNAME) $(ALL_OBJ)

re: fclean all

clean:
	rm -f $(ALL_OBJ) $(EXAMPLE_OBJ)

fclean: clean
	rm -f $(LIBNAME)
