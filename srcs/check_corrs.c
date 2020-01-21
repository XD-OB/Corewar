/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_corrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 07:31:34 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/21 06:32:10 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		print_val_error(char *arg, int type)
{
	ft_printf("The argument %{red}%s%{eoc} can't fit", arg);
	ft_printf(" %{green}%d%{eoc} bytes\n", type);
	return (0);
}

int				check_dec_val(int type, char *arg, t_op op_ref)
{
	size_t		len;
	long		n;

	if ((type == T_DIR && op_ref.tdir_size == 2) ||
			type == T_IND)
	{
		len = (arg[0] == '-') ? 6 : 5;
		if (ft_strlen(arg) > len)
			return (print_val_error(arg, 2));
		n = ft_atoi(arg);
		if (n < SHRT_MIN || n > SHRT_MAX)
			return (print_val_error(arg, 2));
		return (1);
	}
	len = (arg[0] == '-') ? 11 : 10;
	if (ft_strlen(arg) > len)
		return (print_val_error(arg, 4));
	n = ft_atoi(arg);
	if (n < INT_MIN || n > INT_MAX)
		return (print_val_error(arg, 4));
	return (1);
}

int				check_hex_val(int type, char *arg, t_op op_ref)
{
	size_t		len;
	long		n;
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

static int		print_arithm_error(char *arg, int type,
		char **opts, int ret)
{
	free(opts[0]);
	free(opts[1]);
	free(opts[2]);
	if (ret == 0)
		print_val_error(arg, type);
	return (ret);
}

int				check_arithm(int type, char *arg, t_op op_ref)
{
	size_t		len;
	char		*opts[3];
	long long	n;

	fill_opts(opts, arg);
	if (type == T_DIR && op_ref.tdir_size == 4)
	{
		len = (arg[0] == '-') ? 11 : 10;
		if ((ft_strlen(opts[0]) > len) || (ft_strlen(opts[2]) > len))
			return (print_arithm_error(arg, 4, opts, 0));
		n = ft_strcalcul(opts);
		if (n < INT_MIN || n > INT_MAX)
			return (print_arithm_error(arg, 4, opts, 0));
	}
	else
	{
		len = (arg[0] == '-') ? 6 : 5;
		if ((ft_strlen(opts[0]) > len) || (ft_strlen(opts[2]) > len))
			return (print_arithm_error(arg, 2, opts, 0));
		n = ft_strcalcul(opts);
		if (n < SHRT_MIN || n > SHRT_MAX)
			return (print_arithm_error(arg, 2, opts, 0));
	}
	return (print_arithm_error(arg, 2, opts, 1));
}
