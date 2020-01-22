/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 23:36:59 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 22:20:21 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

void				render_rc_byte(WINDOW *arena, int row, int col,
		unsigned int attr)
{
	unsigned char	byte;

	byte = g_arena.memory[M(row * BYTES_PER_LINE + col)];
	wattron(arena, attr);
	mvwprintw(arena, row + 1 + V_PADDING, col * 3 + 1 + H_PADDING,
				"%02x", byte);
	wattroff(arena, attr);
}

void				render_byte(WINDOW *arena, int pos, unsigned int attr)
{
	unsigned char	byte;
	int				row;
	int				col;

	byte = g_arena.memory[M(pos)];
	row = (M(pos) / BYTES_PER_LINE) + 1 + V_PADDING;
	col = (pos % BYTES_PER_LINE) * 3 + 1 + H_PADDING;
	wattron(arena, attr);
	mvwprintw(arena, row, col, "%02x", byte);
	wattroff(arena, attr);
}

void				print_arena(void)
{
	int				i;
	int				j;
	WINDOW			*arena;

	arena = g_vis.arena;
	box(arena, 0, 0);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_YELLOW);
	i = -1;
	while (++i < (MEM_SIZE / BYTES_PER_LINE))
	{
		j = -1;
		while (++j < BYTES_PER_LINE)
		{
			if (g_arena.memory[i * BYTES_PER_LINE + j])
				render_rc_byte(arena, i, j, COLOR_PAIR(1) | A_BLINK);
			else
				render_rc_byte(arena, i, j, A_NORMAL);
		}
	}
	mvwchgat(arena, 2, 2, 2, 0, 2, 0);
	wrefresh(arena);
	getchar();
}
