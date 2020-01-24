/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 23:50:56 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 19:46:48 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** psn stands for players number
*/

void	place_players(void)
{
	int i;

	i = -1;
	while (++i < g_arena.players_nb)
		ft_memcpy(g_arena.memory + i * (MEM_SIZE / g_arena.players_nb),
			g_players[i].ex_code,
			g_players[i].header.prog_size);
}
