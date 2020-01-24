/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 01:25:23 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/22 04:18:52 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

int		ft_putint(int n)
{
	write(1, &n, 4);
	return (0);
}

void	destroy_cursor(t_process *p)
{
	int n;

	if (p->pvis.prev_color != NO_COLOR)
	{
		tputs(tgetstr("bl", NULL), 1, ft_putint);
		n = p->pvis.prev_color;
		render_byte(g_vis.arena, p->pc, COLOR_PAIR(WRCOLOR) | A_BOLD);
		wrefresh(g_vis.arena);
		usleep(50000);
		render_byte(g_vis.arena, p->pc, COLOR_PAIR(n));
	}
}
