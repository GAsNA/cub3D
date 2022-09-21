/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_rand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:47:49 by nmathieu          #+#    #+#             */
/*   Updated: 2022/09/21 10:50:11 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_game.h"

static inline uint64_t	rotl(const uint64_t x, int k) {
	return ((x << k) | (x >> (64 - k)));
}

uint64_t	c3d_game_rand(t_game *game) {
	uint64_t s0;
	uint64_t s1;
	uint64_t result;

	s0 = game->rng_state[0];
	s1 = game->rng_state[1];
	result = rotl(s0 + s1, 17) + s0;
	s1 ^= s0;
	game->rng_state[0] = rotl(s0, 49) ^ s1 ^ (s1 << 21);
	game->rng_state[1] = rotl(s1, 28);
	return (result);
}
