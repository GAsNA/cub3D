# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 17:13:48 by nmathieu          #+#    #+#              #
#    Updated: 2022/07/13 18:54:32 by rleseur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Le nom du programme c'est bien "cub3D" avec un D majuscule. T'avais raison
# depuis le début x)
NAME := cub3D
CFLAGS :=
CC := /bin/clang

define SRCS :=
	main.c			\
	window.c		\
	draw.c			\
	actions_win.c	\
	moving.c		\
	free.c
endef

define HDRS :=
	c3d_map.h	\
	raycasting.h
endef

SRCS_DIR := srcs
OBJS_DIR := objs
INCS_DIR := incs

define LIBS :=
	libft/libft.a	\
	minilibx/libmlx_Linux.a
endef

# ============================================================================ #
#                               Intermediates                                  #
# ============================================================================ #

OBJ_FILES := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))
HDR_FILES := $(addprefix $(INCS_DIR)/,$(HDRS))

CFLAGS := $(CFLAGS) -Wall -Wextra -g
MLXFLAGS := -L. -lXext -L. -lX11

ifdef DEBUG
	CFLAGS := $(CFLAGS) -g3 -D DEBUG
else
	CFLAGS := $(CFLAGS) -Werror
endif

# ============================================================================ #
#                                 Functions                                    #
# ============================================================================ #

all: $(NAME)

clean:
	@rm -vf $(OBJ_FILES)
	@make -C libft fclean
	@make -C minilibx clean
.PHONY: clean

fclean: clean
	@rm -vf $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re

# ============================================================================ #
#                                   Rules                                      #
# ============================================================================ #

$(NAME): $(OBJ_FILES) $(LIBS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBS) $(MLXFLAGS)

libft/libft.a:
	@make -C libft libft.a

minilibx/libmlx_Linux.a:
	@make -C minilibx

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HDR_FILES)
	@mkdir -vp $(dir $@)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $<
