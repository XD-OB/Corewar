/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:29:14 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/24 00:54:25 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	exec_zjmp(t_process *p)
{
	int		t_dir_type;
	t_dir	dir_val;
	int		offset;

	offset = 1;
	t_dir_type = g_op_tab[ZJMP_I].t_dir_size_type;
	dir_val = read_dir_val(p->pc + offset, t_dir_type);
	offset += t_dir_type == SHORT_TDIR ? IND_SIZE : DIR_SIZE;
	if (p->carry)
		p->pc = M(p->pc + (dir_val.s % IDX_MOD));
	else
		p->pc += offset;
}
