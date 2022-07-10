# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 17:13:48 by nmathieu          #+#    #+#              #
#    Updated: 2022/07/10 14:47:05 by nmathieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Le nom du programme c'est bien "cub3D" avec un D majuscule. T'avais raison
# depuis le début x)
NAME := cub3D
CFLAGS :=
CC := /bin/clang

define SRCS :=
	main.c

	parse/c3d_map_free.c
	parse/c3d_map_parse_fd.c
	parse/c3d_map_parse.c
endef

define HDRS :=
	c3d_map.h
endef

SRCS_DIR := srcs
OBJS_DIR := objs
INCS_DIR := incs

define LIBS :=
	libft/libft.a
endef

# ============================================================================ #
#                               Intermediates                                  #
# ============================================================================ #

OBJ_FILES := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))
HDR_FILES := $(addprefix $(INCS_DIR)/,$(HDRS))

CFLAGS := $(CFLAGS) -Wall -Wextra

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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBS)

libft/libft.a:
	@make -C libft libft.a

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HDR_FILES)
	@mkdir -vp $(dir $@)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $<