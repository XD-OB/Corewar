/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:22:57 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/23 22:26:55 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int					is_valid_reg(int reg_num)
{
	return (reg_num > 0 && reg_num <= 16);
}

t_dir				read_dir_val(int pc, int type)
{
	int				i;
	t_dir			res;
	unsigned char	*tmp;
	int				size;

	tmp = (unsigned char *)(&res);
	ft_bzero(&res, sizeof(res));
	size = (type == SHORT_TDIR ? IND_SIZE : DIR_SIZE);
	i = -1;
	while (++i < size)
		tmp[i] = g_arena.memory[M(pc + i)];
	reverse_bytes(&res, type == SHORT_TDIR ? IND_SIZE : DIR_SIZE);
	return (res);
}

t_ind				read_ind_val(t_process *p, int *offset, int type)
{
	int				i;
	t_ind			res;
	unsigned char	*tmp;

	tmp = (unsigned char *)(&res);
	ft_bzero(&res, sizeof(res));
	i = -1;
	while (++i < IND_SIZE)
		tmp[i] = g_arena.memory[M(p->pc + *offset + i)];
	*offset += IND_SIZE;
	reverse_bytes(&res, IND_SIZE);
	if (type == LONG_OP)
		return (M(p->pc + res));
	else
		return (M(p->pc + (res % IDX_MOD)));
}
