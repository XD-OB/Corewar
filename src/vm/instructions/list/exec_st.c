/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:29:48 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/18 23:35:53 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		exec_st(t_process *p)
{
	int		t_dir_type;
	int		offset;
	char	r_src;
	char	r_dst;
	t_ind	addr;

	t_dir_type = g_op_tab[ST_I].t_dir_size_type;
	if (check_operation(p, t_dir_type, &offset))
		return ;
	r_src = g_arena.memory[M(p->pc + offset)];
	offset++;
	if (g_type[1] == T_REG)
	{
		r_dst = g_arena.memory[M(p->pc + offset)];
		offset++;
		write_into_reg(p, r_dst, p->reg[r_src - 1], 0);
	}
	if (g_type[1] == T_IND)
	{
		addr = read_ind_val(p, &offset, NORM_OP);
		write_mem(p, &(p->reg[r_src - 1]), addr, REG_SIZE);
	}
	p->pc += offset;
}
