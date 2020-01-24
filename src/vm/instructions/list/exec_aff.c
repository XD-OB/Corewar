/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:26:27 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/24 01:13:18 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

void	exec_aff(t_process *p)
{
	int		t_dir_type;
	int		offset;
	int		r_src;

	t_dir_type = g_op_tab[AFF_I].t_dir_size_type;
	if (check_operation(p, t_dir_type, &offset))
		return ;
	r_src = g_arena.memory[M(p->pc + offset)];
	offset++;
	p->pc += offset;
	if (!VIS)
	{
		if (g_flags[FLAG_A_I].present)
			ft_printf("%c\n", (char)p->reg[r_src - 1]);
	}
	else
	{
		add_comment(p->player_id, ft_itoa(p->reg[r_src - 1]));
	}
}
