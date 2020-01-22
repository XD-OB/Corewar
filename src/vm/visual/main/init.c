/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:44:02 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/22 01:04:16 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_visu.h"
#include "vm.h"

void		ft_init_colors(void)
{
	init_pair(DEFULT_COLOR, COLOR_WHITE, COLOR_BLACK);
	init_pair(P1COLOR, COLOR_GREEN, COLOR_BLACK);
	init_pair(P2COLOR, COLOR_CYAN, COLOR_BLACK);
	init_pair(P3COLOR, COLOR_YELLOW, COLOR_BLACK);
	init_pair(P4COLOR, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(WRCOLOR, COLOR_WHITE, COLOR_RED);
	init_pair(WWCOLOR, COLOR_WHITE, COLOR_WHITE);
	init_pair(GBCOLOR, COLOR_GREEN, COLOR_BLACK);
	init_pair(RBCOLOR, COLOR_RED, COLOR_BLACK);
	init_pair(BLBCOLOR, COLOR_BLUE, COLOR_BLACK);
	init_pair(YBCOLOR, COLOR_YELLOW, COLOR_BLACK);
}

void		load_arena(void)
{
	int		i;
	int		j;

	WINDOW * arena;
	arena = g_vis.arena;
	i = -1;
	while (++i < (MEM_SIZE / BYTES_PER_LINE))
	{
		j = -1;
		while (++j < BYTES_PER_LINE)
			render_rc_byte(arena, i, j, A_NORMAL);
	}
}

void		paint_players(void)
{
	int		pos;
	int		i;
	int		j;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (g_players[i].present)
		{
			pos = i * (MEM_SIZE / g_arena.players_nb);
			j = pos - 1;
			while (++j < (int)(pos + g_players[i].header.prog_size))
				render_rc_byte(g_vis.arena, j / BYTES_PER_LINE,
							j % BYTES_PER_LINE, COLOR_PAIR(i + 1));
		}
	}
}

void		init_game_params(void)
{
	g_vis.game.paused = TRUE;
	g_vis.game.speed = INIT_SPEED;
}

void		init_vis(void)
{
	initscr();
	start_color();
	noecho();
	curs_set(0);
	cbreak();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	ft_init_colors();
	vinit_arena();
	init_siders();
	init_game_params();
	init_usage();
	init_color(COLOR_WHITE, 200, 200, 200);
	refresh();
	wrefresh(g_vis.usage);
}
