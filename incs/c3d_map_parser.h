/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:56:12 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 19:59:11 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_MAP_PARSER_H
# define C3D_MAP_PARSER_H

# include "libft.h"
# include "c3d_map.h"

// Stores the state required to parse a `t_map` instance.
typedef struct s_map_parser
{
	t_reader	reader;
	size_t		line;

	t_map		*map;

	size_t		width;
	size_t		height;

	struct s_map_parser_walls
	{
		bool	*data;
		size_t	len;
		size_t	cap;
	}	walls;
	struct s_map_parser_lines
	{
		struct s_map_parser_lines_element
		{
			bool	*line;
			size_t	len;
		}		*data;
		size_t	len;
		size_t	cap;
	}	lines;
	struct s_map_parser_errors
	{
		char	**data;
		size_t	len;
		size_t	cap;
	}	errors;
}	t_map_parser;

// Initializes a `t_map_parser` instance.
void	c3d_map_parser_init(t_map_parser *self, int fd, t_map *result);

// Frees the resources that were allocated for a `t_map_parser` instance.
void	c3d_map_parser_deinit(t_map_parser *self);

// Consume every character until (and including) the first `\n` character.
void	c3d_map_parser_skip_line(t_map_parser *self);

// Consume every whitespace (not including the `\n` character).
void	c3d_map_parser_skip_spaces(t_map_parser *self);

// Parses a file name until the end of the line.
//
// If `result` is not `NULL`, an error is returned and the function returns
// `false`.
bool	c3d_map_parser_filename(t_map_parser *self, t_str ident, char **result);

// Parses a `t_color` instance until the end of the line.
//
// If `result` is not a fully-zeroed value, an error is returned.
bool	c3d_map_parser_color(t_map_parser *self, t_str ident, t_color *result);

// Tries to parse a key-value pair at the begining of the parser. If an error
// occurs, it is added to the list.
//
// The function returns an actual key-value pair could be found.
bool	c3d_map_parser_field(t_map_parser *self);

// Skip empty lines (or lines only made of spaces). 
void	c3d_map_parser_skip_empty_lines(t_map_parser *self);

// Tries to parse a map.
void	c3d_map_parser_map(t_map_parser *self);

// Pushes a new error at the end of the error list.
void	c3d_map_parser_push_error(t_map_parser *self, const char *format, ...);

#endif
