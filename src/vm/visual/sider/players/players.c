/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:53:37 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 22:29:59 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_visu.h"
#include "vm.h"

void	refresh_players(void)
{
	int i;

	i = -1;
	while (g_vis.siders.player[++i])
		wrefresh(g_vis.siders.player[i]);
}

void	render_player_info(WINDOW *plw, int pli)
{
	int rows;
	int cols;

	wattron(plw, A_BOLD);
	getmaxyx(plw, rows, cols);
	wmove(plw, 2, 6);
	wprintw(plw, "Players %d : ", pli + 1);
	wattron(plw, COLOR_PAIR(pli + 1));
	wprintw(plw, "%s", g_players[pli].header.prog_name);
	wattroff(plw, COLOR_PAIR(pli + 1));
	mvwprintw(plw, 4, 6, "lives declared : %-10d",
		g_players[pli].lives_last_check);
	mvwprintw(plw, 6, 6, "last live cycle : %-10d",
		g_players[pli].last_live_cycle);
	wattroff(plw, A_BOLD);
}

void	render_players_info(void)
{
	int i;

	i = -1;
	while (g_vis.siders.player[++i])
		render_player_info(g_vis.siders.player[i], i);
}
