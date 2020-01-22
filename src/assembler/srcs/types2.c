/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:13:52 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 20:44:06 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_op(t_op *op_tab, char *str)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strcmp(str, op_tab[i].name))
			return (i + 1);
		i++;
	}
	return (0);
}

int			type_arg(char *str)
{
	if (is_reg(str))
		return (T_REG);
	else if (is_dir(str))
		return (T_DIR);
	else if (is_ind(str))
		return (T_IND);
	else
		return (0);
}
