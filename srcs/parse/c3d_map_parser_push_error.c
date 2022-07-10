/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_parser_push_error.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:24:21 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 18:27:41 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map_parser.h"

static void	my_va_end(va_list *args)
{
	va_end(*args);
}

void	c3d_map_parser_push_error(t_map_parser *self, const char *format, ...)
{
	t_unwind	unwind_index;
	va_list		args;

	va_start(args, format);
	unwind_index = ft_unwind(&args, my_va_end);
	ft_vec_reserve((t_vec *)&self->errors, 1, sizeof(char *));
	self->errors.errors[self->errors.len++] = ft_sfmt_va(format, args);
	ft_unwind_to(unwind_index);
}
