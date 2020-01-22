/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:39:17 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/07 16:20:18 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_processes(void)
{
	int pn;
	int i;

	pn = g_arena.players_nb;
	i = -1;
	while (++i < MAX_ARGS_NUMBER)
	{
		if (g_players[i].present)
			push_process_front(i + 1, i * (MEM_SIZE / pn));
	}
}
