/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:09:51 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 20:59:48 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "__libft_internal.h"
#include <stdlib.h>

void	ft_vec_realloc(t_vec *vec, size_t new_cap, size_t elem_size)
{
	void	*new_data;

	if (new_cap > ((SIZE_MAX / elem_size) - 4) / 2)
		ft_unwind_panic("the system is out of memory");
	new_data = ft_alloc(new_cap * elem_size);
	if (vec->cap)
	{
		ft_mem_copy(new_data, vec->data, elem_size * vec->len);
		free(vec->data);
	}
	vec->data = new_data;
	vec->cap = new_cap;
}
