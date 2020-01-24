/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:00:35 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/22 00:00:36 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

long long		ft_strcalcul(char **opts)
{
	long		n1;
	long		n2;

	n1 = ft_atol(opts[0]);
	n2 = ft_atol(opts[2]);
	if (n1 < INT_MIN || n1 > INT_MAX ||
			n2 < INT_MIN || n2 > INT_MAX)
		return (LONG_MAX);
	if (!ft_strcmp(opts[1], "+"))
		return (n1 + n2);
	else if (!ft_strcmp(opts[1], "-"))
		return (n1 - n2);
	else if (!ft_strcmp(opts[1], "*"))
		return (n1 * n2);
	else
	{
		if (!n2)
			return (0);
		return (n1 / n2);
	}
}

t_inst			*create_inst(void)
{
	t_inst		*inst;
	int			i;

	if (!(inst = (t_inst*)malloc(sizeof(t_inst))))
		return (NULL);
	inst->labels = NULL;
	inst->op_nbr = 0;
	inst->nbr_bytes = 0;
	i = 0;
	while (i < 3)
	{
		inst->args[i].str = NULL;
		inst->args[i].type = 0;
		inst->args[i].value = 0;
		i++;
	}
	return (inst);
}
