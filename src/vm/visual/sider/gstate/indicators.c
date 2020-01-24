/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indicators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 04:06:05 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 22:31:45 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_visu.h"

void	cbcheck(int row, int col)
{
	progbar(g_vis.siders.gstate, row, col,
		get_pb_state(SLD_WIDTH,
			1 - ((double)g_arena.check.remain / g_arena.cycles_to_die),
			COLOR_PAIR(1), 0));
}

void	checks_bd(int row, int col)
{
	progbar(g_vis.siders.gstate, row, col,
		get_pb_state(SLD_WIDTH,
				(double)g_arena.check.max_checks / MAX_CHECKS,
				COLOR_PAIR(BLBCOLOR), 0));
}

void	lives_nb(int row, int col)
{
	progbar(g_vis.siders.gstate, row, col,
		get_pb_state(SLD_WIDTH,
				(double)(MIN(NBR_LIVE, g_arena.check.lives)) / NBR_LIVE,
				COLOR_PAIR(g_arena.check.lives < NBR_LIVE ? YBCOLOR : RBCOLOR)
				, 0));
}

void	render_indicated_data(void)
{
	int bl;

	bl = BASE_LINE + 13;
	wattron(g_vis.siders.gstate, A_BOLD | COLOR_PAIR(2));
	mvwprintw(g_vis.siders.gstate, bl, WORDS_COL, "cycles to die : %-10d",
		g_arena.cycles_to_die);
	wattron(g_vis.siders.gstate, A_BOLD | COLOR_PAIR(1));
	mvwprintw(g_vis.siders.gstate, bl + 3, WORDS_COL,
		"cycles before check : %-10d", g_arena.check.remain);
	cbcheck(bl + 5, WORDS_COL);
	wattroff(g_vis.siders.gstate, A_BOLD | COLOR_PAIR(1));
	wattron(g_vis.siders.gstate, A_BOLD | COLOR_PAIR(BLBCOLOR));
	mvwprintw(g_vis.siders.gstate, bl + 8, WORDS_COL,
	"checks without decrease : %-10d", g_arena.check.max_checks);
	checks_bd(bl + 10, WORDS_COL);
	wattroff(g_vis.siders.gstate, A_BOLD | COLOR_PAIR(BLBCOLOR));
	wattron(g_vis.siders.gstate, A_BOLD | COLOR_PAIR(YBCOLOR));
	mvwprintw(g_vis.siders.gstate, bl + 14, WORDS_COL,
	"lives declared this period: %-10d", g_arena.check.lives);
	lives_nb(bl + 16, WORDS_COL);
	wattroff(g_vis.siders.gstate, A_BOLD | COLOR_PAIR(YBCOLOR));
}
