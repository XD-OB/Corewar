/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:29:31 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/17 06:52:04 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

void	exec_add(t_process *p)
{
	int		t_dir_type;
	int		offset;
	char	r_src1;
	char	r_src2;
	char	r_dst;

	t_dir_type = g_op_tab[ADD_I].t_dir_size_type;
	if (check_operation(p, t_dir_type, &offset))
		return ;
	r_src1 = g_arena.memory[M(p->pc + offset)];
	r_src2 = g_arena.memory[M(p->pc + offset + 1)];
	r_dst = g_arena.memory[M(p->pc + offset + 2)];
	offset += 3;
	write_into_reg(p, r_dst, p->reg[r_src1 - 1] + p->reg[r_src2 - 1], 1);
	p->pc += offset;
}
