/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:29:31 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/24 00:54:38 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

static int	add(t_process *p, int r_src1, int r_src2)
{
	return (p->reg[r_src1 - 1] + p->reg[r_src2 - 1]);
}

void		exec_add(t_process *p)
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
	write_into_reg(p, r_dst, add(p, r_src1, r_src2), SET_CARRY);
	p->pc += offset;
}
