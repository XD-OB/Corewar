/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:24:04 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/15 02:44:37 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		exec_ld(t_process *p)
{
	int		t_dir_type;
	t_dir	dir_val;
	t_ind	addr;
	int		offset;
	int		r_num;

	t_dir_type = g_op_tab[LD_I].t_dir_size_type;
	if (check_operation(p, t_dir_type, &offset))
		return ;
	if (g_type[0] == T_DIR)
	{
		dir_val = read_dir_val(p->pc + offset, t_dir_type);
		offset += t_dir_type == SHORT_TDIR ? IND_SIZE : DIR_SIZE;
	}
	if (g_type[0] == T_IND)
	{
		addr = read_ind_val(p, &offset, NORM_OP);
		dir_val = read_dir_val(addr, t_dir_type);
	}
	if (g_type[1] == T_REG)
	{
		r_num = g_arena.memory[M(p->pc + offset)];
		write_into_reg(p, r_num, dir_val.n, 1);
	}
	p->pc = p->pc + offset + 1;
}
