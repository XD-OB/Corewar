/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 22:33:41 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 21:14:05 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_visu.h"

void	g_flow(void)
{
	int	c;

	c = getch();
	if (c == PAUSE_KEY)
	{
		g_vis.game.paused = TRUE;
		render_gstate();
		wrefresh(g_vis.siders.gstate);
	}
	else if (c == KEY_LEFT || c == KEY_RIGHT)
		catch_speed_keys(c);
	else if (c == QUIT_KEY)
	{
		free_all();
		exit(EXIT_SUCCESS);
	}
	handle_time_flow();
}

void	refresh_all(void)
{
	wrefresh(g_vis.arena);
	wrefresh(g_vis.siders.gstate);
	wrefresh(g_vis.siders.chatbox);
	refresh_players();
}

void	reload_arena(void)
{
	int i;
	int color;

	i = 0;
	while (i < MEM_SIZE)
	{
		color = get_byte_color(i);
		render_byte(g_vis.arena, i, COLOR_PAIR(color));
		i++;
	}
}

void	print_frame(void)
{
	if (g_arena.cycles_nb && g_arena.cycles_nb % 250 == 0)
		reload_arena();
	render_pcursors();
	render_gstate();
	render_players_info();
	render_comments();
	refresh_all();
}
