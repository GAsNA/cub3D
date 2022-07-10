/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:09:51 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 13:53:40 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	ft_reader_next(t_reader *reader, uint8_t *byte)
{
	if (!ft_reader_peek(reader, byte))
		return (false);
	reader->cur++;
	return (true);
}
