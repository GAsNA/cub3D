# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 17:13:48 by nmathieu          #+#    #+#              #
#    Updated: 2022/09/20 19:40:09 by nmathieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Le nom du programme c'est bien "cub3D" avec un D majuscule. T'avais raison
# depuis le début x)
NAME   := cub3D
CFLAGS :=
CC     := /bin/clang
CFLAGS := -Wall -Wextra -g3 -D DEBUG
LFLAGS := -lXext -lX11 -lm

define SRCS :=
	main.c

	parse/c3d_map_free.c
	parse/c3d_map_parse_fd.c
	parse/c3d_map_parse.c
	parse/c3d_map_parser_color.c
	parse/c3d_map_parser_field.c
	parse/c3d_map_parser_filename.c
	parse/c3d_map_parser_init.c
	parse/c3d_map_parser_is_enclosed.c
	parse/c3d_map_parser_map.c
	parse/c3d_map_parser_push_error.c
	parse/c3d_map_parser_utils.c
	parse/c3d_map_parser_validate_fields.c

	game/c3d_game_load.c
	game/c3d_img_load_file.c
	game/c3d_game_free_wall_textures.c
	game/c3d_game_free_line_texture.c
	game/c3d_game_destroy_mlx.c
	game/c3d_game_destroy_hook.c
	game/c3d_game_key_hooks.c
	game/c3d_game_free_canvas.c
	game/c3d_game_loop_hook.c
	game/c3d_game_free_car_textures.c
	game/c3d_game_pointer_hook.c

	graphics/c3d_game_render.c
	graphics/c3d_game_make_raycasted_image.c
	graphics/c3d_game_render_minimap.c
	graphics/c3d_game_render_car.c
	graphics/c3d_create_ray.c
	graphics/c3d_cast_ray.c

	physics/c3d_game_move_player.c
	physics/c3d_game_simulate.c
	physics/c3d_game_update_line.c
endef
SRCS := $(strip $(SRCS))

SRCS_DIR := srcs
OBJS_DIR := objs
INCS_DIR := incs

define LIBS :=
	libft/libft.a
	minilibx/libmlx_Linux.a
endef
LIBS := $(strip $(LIBS))

# ============================================================================ #
#                               Intermediates                                  #
# ============================================================================ #

OBJ_FILES := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))
DEP_FILES := $(OBJ_FILES:.o=.d)

# ============================================================================ #
#                                 Functions                                    #
# ============================================================================ #

all: $(NAME)

clean:
	@rm -vf $(OBJ_FILES)
	@$(MAKE) -C libft fclean
	@$(MAKE) -C minilibx clean
.PHONY: clean

fclean: clean
	@rm -vf $(NAME)
.PHONY: fclean

re:
	@$(MAKE) --no-print-directory clean
	@$(MAKE) --no-print-directory all
.PHONY: re

# ============================================================================ #
#                                   Rules                                      #
# ============================================================================ #

$(NAME): $(OBJ_FILES) $(LIBS)
	@echo "linking..."
	@$(CC) -o $(NAME) $(OBJ_FILES) $(LIBS) $(LFLAGS)

libft/libft.a:
	@echo "creating 'libft.a'..."
	@$(MAKE) -C libft libft.a

minilibx/libmlx_Linux.a:
	@echo "creating 'mlx.a'..."
	@$(MAKE) -C minilibx

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "compiling '$@'..."
	@mkdir -vp $(dir $@)
	@$(CC) $(CFLAGS) -MMD -I $(INCS_DIR) -o $@ -c $<

-include $(DEP_FILES)