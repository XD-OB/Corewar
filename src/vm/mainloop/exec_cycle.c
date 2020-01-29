/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:20:37 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/29 01:38:34 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

void	pload_op(t_process *p)
{
	unsigned char	op;

	op = (int)g_arena.memory[M(p->pc)];
	p->op_buff.op = op;
	p->op_buff.cycles_last = g_op_tab[op - 1].cycles;
}

void	exec_process(t_process *p)
{
	unsigned char op;

	if (VIS && p->pvis.prev_color != NO_COLOR)
		render_byte(g_vis.arena, p->pc,
			COLOR_PAIR(p->pvis.prev_color) | p->pvis.prev_attrs);
	if (p->op_buff.op)
	{
		if (--p->op_buff.cycles_last <= 1)
			pexec_inst(p);
	}
	else
	{
		op = g_arena.memory[M(p->pc)];
		if (op >= (LIVE_I + 1) && (op <= AFF_I + 1))
			pload_op(p);
		else
			p->pc += 1;
	}
}

void	exec_cycle(void)
{
	t_process	*p;

	p = g_arena.processes;
	if (g_arena.game_run)
	{
		g_arena.cycles_nb++;
		g_arena.check.remain--;
	}
	while (p)
	{
		exec_process(p);
		p = p->next;
	}
}
