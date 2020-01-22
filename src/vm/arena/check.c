/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 22:36:28 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 19:43:35 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

void			kill_process(t_process **targetadd, t_process **prevadd)
{
	t_process	*tmp;

	if (VIS)
		destroy_cursor(*targetadd);
	if (*prevadd)
	{
		(*prevadd)->next = (*targetadd)->next;
		free((*targetadd));
		*targetadd = (*prevadd)->next;
	}
	else
	{
		tmp = g_arena.processes;
		if (tmp)
		{
			g_arena.processes = g_arena.processes->next;
			*targetadd = g_arena.processes;
		}
		else
			(*targetadd) = NULL;
		free(tmp);
	}
	g_arena.pnum--;
}

void			restart_process(t_process *p)
{
	p->declared_live = FALSE;
}

void			handle_check(void)
{
	g_arena.check.total_checks++;
	g_arena.check.max_checks++;
	if (g_arena.check.lives >= NBR_LIVE)
	{
		g_arena.cycles_to_die -= CYCLE_DELTA;
		g_arena.check.max_checks = 0;
	}
	else if (g_arena.check.max_checks >= MAX_CHECKS)
	{
		g_arena.cycles_to_die -= CYCLE_DELTA;
		g_arena.check.max_checks = 0;
	}
	if (g_arena.pnum <= 0 || g_arena.cycles_to_die <= 0)
		g_arena.game_run = FALSE;
	g_arena.check.lives = 0;
	g_arena.check.remain = g_arena.cycles_to_die;
}

void			perform_check(void)
{
	t_process	*tmp;
	t_process	*prev;

	prev = NULL;
	tmp = g_arena.processes;
	while (tmp)
	{
		if (!tmp->declared_live)
			kill_process(&tmp, &prev);
		else
		{
			restart_process(tmp);
			prev = tmp;
			tmp = tmp->next;
		}
	}
	handle_check();
}
