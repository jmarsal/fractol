# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 00:34:02 by jmarsal           #+#    #+#              #
#    Updated: 2016/09/22 09:29:57 by jmarsal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
OPTI = -O2
CFLAGS_DEBUG = -g0 -O0
CFLAGS = -Wall -Werror -Wextra $(OPTI)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
    MLX_INC_PATH = libmlx
else
    MLX_INC_PATH = minilibx
endif

#Header
LIBFT_INC_PATH = libft/includes
LIBFT_INC_FILES = libft.h
MLX_INC_FILES = mlx.h
INC_PATH = includes
INC_FILES = fractol.h define.h structs.h
HEADERS =  $(LIBFT_INC_FILES:%.h=$(LIBFT_INC_PATH)/%.h)
HEADERS += $(MLX_INC_FILES:%.h=$(MLX_INC_PATH)/%.h)
HEADERS += $(INC_FILES:%.h=$(INC_PATH)/%.h)
CFLAGS += $(addprefix -I,$(INC_PATH) $(LIBFT_INC_PATH) $(MLX_INC_PATH))

#Sources
SRC_PATH = srcs/
SRC_PATH += srcs/memory
SRC_PATH += srcs/treatment
SRC_PATH += srcs/fractals
SRC_PATH += srcs/events
vpath %.c $(SRC_PATH)

SOURCES = main.c \
					treatment.c \
					put_img_and_str_win.c \
					init_app.c \
					init_menu_left.c \
					init_data.c \
					mandelbrot.c \
					events.c \
					key_fonctions.c \

# Libft
 LIBFT_PATH = libft
 LIBFT = $(LIBFT_PATH)/libft.a

 # MLX
ifeq ($(UNAME_S), Darwin)
   MLX_PATH = libmlx
else
    MLX_PATH = minilibx
endif
MLX = $(MLX_PATH)/mlx.a

#Objects
OBJ_PATH = ./obj
OBJECTS = $(addprefix $(OBJ_PATH)/, $(SOURCES:%.c=%.o))

ifeq ($(UNAME_S), Darwin)
   LIB_PATH = -L./libft/ -lft -L./libmlx/ -lmlx -framework OpenGL -framework AppKit
else
    LIB_PATH = -L./libft/ -lft  -L./minilibx/ -lmlx -L/usr/include/../lib -lXext -lX11 -lm
endif

all: $(NAME)
$(NAME): $(OBJECTS)
	@make -C $(MLX_PATH)
	@make -C libft
	@$(CC) -o $(NAME) $(OBJECTS) $(CFLAGS) $(LIB_PATH)
	@echo "\n-----------------------------------------"
	@echo "|\033[32;1m\t$(NAME) has been created !\t\t\033[0m|"
	@echo "-----------------------------------------\n"

$(OBJECTS): $(HEADERS) | $(OBJ_PATH)
$(OBJECTS): $(OBJ_PATH)/%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_PATH):
	@-mkdir -p $@

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\n-------------------------------------------------"
	@echo "|\t\033[31mall $(NAME) files.o are deleted\033[0m\t\t|"
	@echo "-------------------------------------------------\n"

fclean: clean
	@rm -f $(NAME)
	@echo "\n---------------------------------"
	@echo "|\t\033[31m$(NAME) is deleted\033[0m\t\t|"
	@echo "---------------------------------\n"

re: fclean all

libs:
	@make -C libft
	@make -C $(MLX_PATH)

libs-clean:
	@make -C libft clean
	@make -C $(MLX_PATH) clean

libs-fclean:
	@make -C libft fclean
	@make -C $(MLX_PATH) clean

libs-re: libs-fclean
	@make -C libft re
	@make -C $(MLX_PATH) re

fclean-all: fclean libs-fclean

debug: CFLAGS := $(filter-out $(OPTI),$(CFLAGS) $(CFLAGS_DEBUG))
debug: re
	@echo "\n-----------------------------------------------------------------"
	@echo "|\033[32;1m\tDebug mode for $(NAME) with $(CFLAGS_DEBUG)!\t\033[0m|"
	@echo "-----------------------------------------------------------------\n"

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY:  all, clean, fclean, re, libs, libs-clean, libs-fclean, libs-re \
		fclean-all, debug, norme
