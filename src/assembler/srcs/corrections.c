/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corrections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 06:20:37 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/21 22:03:01 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		corr_dec_value(int type, char *arg, t_op op_ref)
{
	size_t		len;
	long		n;

	if ((type == T_DIR && op_ref.tdir_size == 2) ||
			type == T_IND)
	{
		len = (arg[0] == '-') ? 6 : 5;
		if (ft_strlen(arg) > len)
			return (0);
		n = ft_atoi(arg);
		if (n < SHRT_MIN || n > 65535)
			return (0);
	}
	else
	{
		len = (arg[0] == '-') ? 11 : 10;
		if (ft_strlen(arg) > len)
			return (0);
		n = ft_atol(arg);
		if (n < INT_MIN || n > 4294967295)
			return (0);
	}
	return (1);
}

static int		corr_hex_value(int type, char *arg, t_op op_ref)
{
	int			i;

	i = 2;
	while (arg[i] == '0')
		i++;
	if ((type == T_DIR && op_ref.tdir_size == 2) ||
			type == T_IND)
	{
		if (ft_strlen(&arg[i]) > 4)
			return (0);
	}
	else
	{
		if (ft_strlen(&arg[i]) > 8)
			return (0);
	}
	return (1);
}

int				corrections(int type, char *str, t_op op_ref)
{
	if (str[0] == '(')
	{
		if (!corr_arithm(type, str, op_ref))
			return (0);
	}
	else
	{
		if (str[0] != LABEL_CHAR)
		{
			if (ft_is_strhex(str))
			{
				if (!corr_hex_value(type, str, op_ref))
					return (0);
			}
			else
			{
				if (!corr_dec_value(type, str, op_ref))
					return (0);
			}
		}
	}
	return (1);
}
