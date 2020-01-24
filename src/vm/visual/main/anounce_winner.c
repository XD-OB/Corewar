/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anounce_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 02:57:16 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 22:12:36 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_visu.h"

void		anounce_player(void)
{
	t_point p;
	int		rows;
	int		cols;

	g_vis.game.paused = TRUE;
	getmaxyx(stdscr, rows, cols);
	move(0, 0);
	getyx(stdscr, p.y, p.x);
	attron(COLOR_PAIR(g_arena.last_live_player) | A_BLINK | A_BOLD);
	while (p.x < cols * 0.9)
	{
		printw("Player %d (%s) won ~ ", g_arena.last_live_player,
			g_players[g_arena.last_live_player - 1].header.prog_name);
		getyx(stdscr, p.y, p.x);
	}
	move(rows - 1, 0);
	getyx(stdscr, p.y, p.x);
	attron(COLOR_PAIR(g_arena.last_live_player) | A_BLINK);
	while (p.x < cols * 0.9)
	{
		printw("Player %d (%s) won ~ ", g_arena.last_live_player,
			g_players[g_arena.last_live_player - 1].header.prog_name);
		getyx(stdscr, p.y, p.x);
	}
	attroff(COLOR_PAIR(g_arena.last_live_player) | A_BLINK | A_BOLD);
}

void		v_anounce_winner(void)
{
	int		c;

	anounce_player();
	render_gstate();
	refresh();
	wrefresh(g_vis.siders.gstate);
	while ((c = getch()))
		if (c == QUIT_KEY)
			break ;
}
