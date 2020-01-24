/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pcursors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:20:27 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 21:10:05 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

chtype			get_byte_color(int pos)
{
	int			row;
	int			col;

	pos = M(pos);
	row = (M(pos) / BYTES_PER_LINE) + 1 + V_PADDING;
	col = (M(pos) % BYTES_PER_LINE) * 3 + 1 + H_PADDING;
	return ((mvwinch(g_vis.arena, row, col) & A_COLOR) >> 8);
}

chtype			get_byte_attrs(int pos)
{
	int			row;
	int			col;

	pos = M(pos);
	row = (M(pos) / BYTES_PER_LINE) + 1 + V_PADDING;
	col = (M(pos) % BYTES_PER_LINE) * 3 + 1 + H_PADDING;
	return ((mvwinch(g_vis.arena, row, col) & A_ATTRIBUTES));
}

void			render_cursor(t_process *p)
{
	int			row;
	int			col;

	row = (M(p->pc) / BYTES_PER_LINE) + 1 + V_PADDING;
	col = (M(p->pc) % BYTES_PER_LINE) * 3 + 1 + H_PADDING;
	if (!(get_byte_attrs(M(p->pc)) & A_REVERSE))
	{
		p->pvis.prev_color = (mvwinch(g_vis.arena, row, col) & A_COLOR) >> 8;
		p->pvis.prev_attrs = get_byte_attrs(M(p->pc));
		render_byte(g_vis.arena, M(p->pc),
			COLOR_PAIR(p->player_id) | A_REVERSE);
	}
	else
		p->pvis.prev_color = NO_COLOR;
}

void			render_pcursors(void)
{
	t_process	*p;

	wattron(g_vis.arena, COLOR_PAIR(g_arena.last_live_player) | A_REVERSE);
	wborder(g_vis.arena, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wattroff(g_vis.arena, COLOR_PAIR(g_arena.last_live_player) | A_REVERSE);
	p = g_arena.processes;
	while (p)
	{
		render_cursor(p);
		p = p->next;
	}
}
