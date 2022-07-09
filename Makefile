# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 17:13:48 by nmathieu          #+#    #+#              #
#    Updated: 2022/07/09 17:29:34 by nmathieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Le nom du programme c'est bien "cub3D" avec un D majuscule. T'avais raison
# depuis le début x)
NAME := cub3D
CFLAGS :=
CC := /bin/clang

define SRCS :=
	main.c
endef

define HDRS :=
endef

SRCS_DIR := srcs
OBJS_DIR := objs
INCS_DIR := incs

define LIBS :=
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

all: $(LIBS) $(NAME)

clean:
	@rm -vf $(OBJ_FILES)
.PHONY: clean

fclean:
	@rm -vf $(OBJ_FILES)
	@rm -vf $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re

# ============================================================================ #
#                                   Rules                                      #
# ============================================================================ #

$(NAME): $(OBJ_FILES) $(LIBS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HDR_FILES)
	@mkdir -vp $(dir $@)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $<