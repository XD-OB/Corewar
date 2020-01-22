/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:27:04 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/21 20:23:34 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	exec_lfork(t_process *p)
{
	int			c;
	t_process	*np;
	t_dir		dirval;

	c = 1;
	dirval = read_dir_val(p->pc + c, SHORT_TDIR);
	c += IND_SIZE;
	SAFE(np = pdup(p));
	np->pc = M(p->pc + (dirval.s));
	np->op_buff.op = 0;
	np->pid = ++(g_arena.pnum);
	np->next = g_arena.processes;
	g_arena.processes = np;
	p->pc = M(p->pc + c);
}
