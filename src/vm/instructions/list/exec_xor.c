/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_xor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:28:43 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/24 00:54:03 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	exec_xor(t_process *p)
{
	int		args[2];
	int		offset;
	int		t_dir_type;
	char	r_dst;

	t_dir_type = g_op_tab[XOR_I].t_dir_size_type;
	if (check_operation(p, t_dir_type, &offset))
		return ;
	get_op_args(p, args, &offset, R_DST);
	r_dst = g_arena.memory[M(p->pc + offset)];
	offset++;
	write_into_reg(p, r_dst, args[0] ^ args[1], SET_CARRY);
	p->pc += offset;
}
