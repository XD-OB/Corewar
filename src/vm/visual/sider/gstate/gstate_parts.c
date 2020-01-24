/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gstate_parts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 00:49:40 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/22 01:04:05 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_visu.h"

void	render_speed_bar(int row, int col)
{
	t_progbar_state state;

	state.width = MAX_SPEED + 1;
	state.attrs = COLOR_PAIR(GBCOLOR);
	state.battrs = COLOR_PAIR(DEFULT_COLOR);
	state.progress = (double)g_vis.game.speed / (MAX_SPEED + 1);
	speed_pb(g_vis.siders.gstate, row, col, state);
}

void	render_top_infos(void)
{
	int		bl;

	WINDOW * win;
	bl = BASE_LINE;
	win = g_vis.siders.gstate;
	wmove(win, bl, WORDS_COL);
	wattron(win, A_BOLD);
	wprintw(win, "game state : ");
	wattron(win, COLOR_PAIR(g_vis.game.paused ? RBCOLOR : GBCOLOR));
	if (g_arena.game_run)
		wprintw(g_vis.siders.gstate,
				"%-20s", g_vis.game.paused ? "*PAUSE*" : "*RUNNING*");
	else
		wprintw(g_vis.siders.gstate, "%-20s", "*GAMEOVER*");
	wattroff(win, COLOR_PAIR(g_vis.game.paused ? RBCOLOR : GBCOLOR));
	wmove(win, bl + 2, WORDS_COL);
	wprintw(win, "Speed : ");
	render_speed_bar(bl + 2, WORDS_COL + ft_strlen("Speed : "));
	wattroff(win, A_BOLD);
}

void	render_important_info(void)
{
	int	bl;

	bl = BASE_LINE + 6;
	wattron(g_vis.siders.gstate, A_BOLD | COLOR_PAIR(g_arena.last_live_player));
	mvwprintw(g_vis.siders.gstate, bl, WORDS_COL, "last live : %-10d",
		g_arena.last_live_player);
	wattroff(g_vis.siders.gstate, COLOR_PAIR(g_arena.last_live_player));
	mvwprintw(g_vis.siders.gstate, bl + 2, WORDS_COL, "cycles : %-10d",
		g_arena.cycles_nb);
	wattroff(g_vis.siders.gstate, A_BOLD);
}
