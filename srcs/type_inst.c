/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:39:00 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/20 06:50:20 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		corr_tabargs(char **tab_arg, t_op op_ref)
{
	int			type;
	int			i;

	if (tabstr_len(tab_arg) != op_ref.args_nbr)
		return (0);
	i = 0;
	while (i < op_ref.args_nbr)
	{
		type = type_arg(tab_arg[i]);
		if (!(type & op_ref.args_type[i]))
			return (0);
		if (tab_arg[i][0] == '(')
		{
			if (!correct_arithm(type, tab_arg[i], op_ref))
				return (0);
		}
		else
		{
			if (!correct_value(type, tab_arg[i], op_ref))
				return (0);
		}
		i++;
	}
	return (1);
}

static int		ret_tabstr_free(char ***atab, int ret)
{
	tabstr_free(atab);
	return (ret);
}

int				is_aloneinst(t_op *op_tab, char *str)
{
	char		**tab_arg;
	char		*op;
	int			op_nbr;
	int			i;

	i = 0;
	while (str[i] && !ft_isblank(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	op = ft_strsub(str, 0, i++);
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

int				is_instlabel(t_op *op_tab, char *str)
{
	char		*instruct;
	int			ret;
	int			i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR &&
			ft_strchr(LABEL_CHARS, str[i]))
		i++;
	if (str[i] != LABEL_CHAR)
		return (0);
	i++;
	while (ft_isblank(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	instruct = ft_strtrim(&str[i]);
	ret = is_aloneinst(op_tab, instruct);
	free(instruct);
	return (ret);
}

int				is_alonelabel(char *str)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, str[i]))
			return (0);
		i++;
	}
	if (str[i] == LABEL_CHAR && !str[i + 1])
		return (1);
	return (0);
}
