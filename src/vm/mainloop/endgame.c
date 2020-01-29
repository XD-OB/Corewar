/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 03:20:42 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/29 02:13:58 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

void	anounce_winner(void)
{
	if (VIS)
		v_anounce_winner();
	else
		ft_printf("Player %d (%s) won\n",
			g_arena.last_live_player,
			g_players[g_arena.last_live_player - 1].header.prog_name);
}

void	free_all(void)
{
	free_processes();
	if (VIS)
		endwin();
}

void	endgame(void)
{
	anounce_winner();
	free_all();
}
