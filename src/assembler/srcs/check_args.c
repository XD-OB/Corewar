/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 07:29:43 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/27 01:09:11 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		print_val_error(char *arg, int type)
{
	ft_printf("The argument %{red}%s%{eoc} can't fit", arg);
	ft_printf(" %{green}%d%{eoc} bytes\n", type);
	return (0);
}

static int		check_hex_val(int type, char *arg, t_op op_ref)
{
	int			i;

	i = 2;
	while (arg[i] == '0')
		i++;
	if ((type == T_DIR && op_ref.tdir_size == 2) ||
			type == T_IND)
	{
		if (ft_strlen(arg) > 4)
			return (print_val_error(arg, 2));
	}
	else
	{
		if (ft_strlen(arg) > 8)
			return (print_val_error(arg, 4));
	}
	return (1);
}

static int		check_values(int type, char *arg, t_op op_ref)
{
	char		*str;

	str = &arg[(type == T_DIR) ? 1 : 0];
	if (str[0] != '(' && str[0] != LABEL_CHAR)
	{
		if (ft_is_strhex(str) &&
			!check_hex_val(type, str, op_ref))
			return (0);
	}
	return (1);
}

static void		check_tabargs(char **tab_arg, t_op op_ref)
{
	int			type;
	int			i;

	if (tabstr_len(tab_arg) != op_ref.args_nbr)
	{
		ft_printf("Wrong Number of Arguments! %{green}%s%{eoc}", op_ref.name);
		ft_printf(" need %{green}%d%{eoc} argument(s)\n", op_ref.args_nbr);
		return ;
	}
	i = -1;
	while (++i < op_ref.args_nbr)
	{
		type = type_arg(tab_arg[i]);
		if (!(type & op_ref.args_type[i]))
		{
			ft_printf("Invalid Type of Argument %{red}%s%{eoc} ", tab_arg[i]);
			ft_printf("for the operation %{green}%s%{eoc}\n", op_ref.name);
			return ;
		}
		if (!check_values(type, tab_arg[i], op_ref))
			return ;
	}
}

void			check_args(t_op *op_tab, int op_nbr, char *str)
{
	char		**tab_arg;

	if (str[ft_strlen(str) - 1] == SEPARATOR_CHAR)
		ft_printf("The Instruction end with %{red}%c%{eoc}\n", SEPARATOR_CHAR);
	else
	{
		tab_arg = ft_strsplit_char(str, SEPARATOR_CHAR);
		tabstr_trim(tab_arg);
		check_tabargs(tab_arg, op_tab[op_nbr - 1]);
		tabstr_free(&tab_arg);
	}
}
