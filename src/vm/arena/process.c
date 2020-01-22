/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:50:47 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 19:45:23 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			free_processes(void)
{
	t_process	*tmp;
	t_process	*h;

	tmp = g_arena.processes;
	while (tmp)
	{
		h = tmp;
		tmp = tmp->next;
		free(h);
	}
	g_arena.processes = NULL;
}

void			push_process_front(int player_id, int pc)
{
	t_process	*tmp;

	tmp = NULL;
	SAFE(tmp = (t_process*)malloc(sizeof(t_process)));
	ft_bzero(tmp, sizeof(t_process));
	tmp->pc = pc;
	tmp->player_id = player_id;
	tmp->pid = ++(g_arena.pnum);
	tmp->reg[0] = -player_id;
	tmp->next = g_arena.processes;
	g_arena.processes = tmp;
}

t_process		*pdup(t_process *p)
{
	t_process	*res;

	if (!(res = (t_process*)malloc(sizeof(t_process))))
		return (NULL);
	ft_memcpy(res, p, sizeof(*res));
	return (res);
}
