/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:27:27 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/24 00:43:35 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

void		exec_lld(t_process *p)
{
	int		t_dir_type;
	t_dir	dir_val;
	t_ind	addr;
	int		offset;
	int		r_num;

	t_dir_type = g_op_tab[LLD_I].t_dir_size_type;
	if (check_operation(p, t_dir_type, &offset))
		return ;
	if (g_type[0] == T_DIR)
	{
		dir_val = read_dir_val(p->pc + offset, t_dir_type);
		offset += t_dir_type == SHORT_TDIR ? IND_SIZE : DIR_SIZE;
	}
	if (g_type[0] == T_IND)
	{
		addr = read_ind_val(p, &offset, LONG_OP);
		dir_val = read_dir_val(addr, t_dir_type);
	}
	if (g_type[1] == T_REG)
	{
		r_num = g_arena.memory[M(p->pc + offset)];
		write_into_reg(p, r_num, dir_val.n, SET_CARRY);
	}
	p->pc = p->pc + offset + 1;
}
