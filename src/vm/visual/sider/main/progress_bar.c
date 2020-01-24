/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:45:58 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 22:36:07 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_visu.h"

void			progbar(WINDOW *win, int row, int col, t_progbar_state state)
{
	int				i;

	wattron(win, state.battrs);
	wmove(win, row, col);
	wprintw(win, "|");
	wmove(win, row, col + state.width + 1);
	wprintw(win, "|");
	wattroff(win, state.battrs);
	wmove(win, row, col + 1);
	i = -1;
	while (++i < state.width)
		wprintw(win, " ");
	wmove(win, row, col + 1);
	wattron(win, state.attrs | A_REVERSE);
	i = -1;
	while (++i < (state.width * state.progress))
		wprintw(win, " ");
	wattroff(win, state.attrs | A_REVERSE);
}

void			speed_pb(WINDOW *win, int row, int col, t_progbar_state state)
{
	int				i;

	wattron(win, state.battrs);
	wmove(win, row, col);
	wprintw(win, "|");
	wmove(win, row, col + state.width * 2);
	wprintw(win, "|");
	wmove(win, row, col + 1);
	i = -1;
	while (++i < state.width * 2 - 1)
		wprintw(win, " ");
	wmove(win, row, col + 1);
	wattron(win, state.attrs);
	i = -1;
	while (++i < (state.width * state.progress) * 2 - 1)
	{
		if (i % 2 == 0)
			wattron(win, state.attrs | A_REVERSE);
		wprintw(win, " ");
		if (i % 2 == 0)
			wattroff(win, state.attrs | A_REVERSE);
	}
	wattroff(win, COLOR_PAIR(GBCOLOR));
}

t_progbar_state	get_pb_state(int width, double progress, int attrs, int battrs)
{
	t_progbar_state	res;

	res.attrs = attrs;
	res.progress = progress;
	res.width = width;
	res.battrs = battrs;
	return (res);
}
