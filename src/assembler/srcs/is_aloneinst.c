/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_aloneinst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:39:00 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/25 06:59:13 by obelouch         ###   ########.fr       */
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

static int		corrections(int type, char *str, t_op op_ref)
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

static int		corr_tabargs(char **tab_arg, t_op op_ref)
{
	char		*str;
	int			type;
	int			i;

	if (tabstr_len(tab_arg) != op_ref.args_nbr)
		return (0);
	i = -1;
	while (++i < op_ref.args_nbr)
	{
		type = type_arg(tab_arg[i]);
		str = &tab_arg[i][(type == T_IND) ? 0 : 1];
		if (!(type & op_ref.args_type[i]))
			return (0);
		if (!corrections(type, str, op_ref))
			return (0);
	}
	return (1);
}

int				is_aloneinst(t_op *op_tab, char *str)
{
	char		**tab_arg;
	char		*op;
	int			op_nbr;
	int			i;

	i = 0;
	while (str[i] && !ft_isblank(str[i]) && str[i] != DIRECT_CHAR)
		i++;
	if (str[i] == '\0')
		return (0);
	op = ft_strsub(str, 0, i);
	op_nbr = is_op(op_tab, op);
	free(op);
	if (str[i] == '\0' || !op_nbr)
		return (0);
	if (str[ft_strlen(str) - 1] == SEPARATOR_CHAR)
		return (0);
	tab_arg = ft_strsplit(&str[i], SEPARATOR_CHAR);
	tabstr_trim(tab_arg);
	if (!corr_tabargs(tab_arg, op_tab[op_nbr - 1]))
		return (ret_tabstr_free(&tab_arg, 0));
	return (ret_tabstr_free(&tab_arg, 1));
}