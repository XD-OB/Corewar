/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:35:33 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/21 20:31:16 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

static void	update_player_info(int pli)
{
	g_players[pli].last_live_cycle = g_arena.cycles_nb;
	g_players[pli].lives_last_check++;
}

void		exec_live(t_process *p)
{
	t_dir	dir_val;
	int		t_dir_type;
	int		c;

	c = 1;
	t_dir_type = g_op_tab[LIVE_I].t_dir_size_type;
	dir_val = read_dir_val(M(p->pc + c), t_dir_type);
	c += t_dir_type == SHORT_TDIR ? IND_SIZE : DIR_SIZE;
	p->declared_live = TRUE;
	g_arena.lives_performed++;
	g_arena.check.lives++;
	if (-dir_val.n >= 1 && -dir_val.n <= g_arena.players_nb)
	{
		g_arena.last_live_player = -dir_val.n;
		update_player_info((-dir_val.n) - 1);
	}
	p->pc = M(p->pc + c);
}
