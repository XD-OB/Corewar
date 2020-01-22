/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 23:49:00 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 19:44:00 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		players_number(void)
{
	int i;
	int res;

	res = 0;
	i = -1;
	while (++i < MAX_ARGS_NUMBER)
		if (g_players[i].present)
			res++;
	return (res);
}

void	init_arena(void)
{
	int i;

	g_arena.game_run = TRUE;
	g_arena.players_nb = players_number();
	g_arena.cycles_to_die = CYCLE_TO_DIE;
	g_arena.check.remain = g_arena.cycles_to_die;
	i = MAX_PLAYERS - 1;
	while (i >= 0 && !g_players[i].present)
		i--;
	g_arena.last_live_player = i + 1;
	place_players();
	init_processes();
}
