/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 22:05:38 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 21:48:50 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		invalid_dump_arg_err(char *arg)
{
	ft_putstr_fd("invalid argument for -dump option : ", 2);
	ft_putendl_fd(arg, 2);
	ft_putstr_fd("only accept numeric arguments\n", 2);
	exit(EXIT_FAILURE);
}

void		invalid_dump_num(int n)
{
	ft_putstr_fd("\ninvalid argument for -dump option : ", 2);
	ft_putnbr_fd(n, 2);
	ft_putstr_fd("\nnumber of cycles must be greater or equal to 1\n", 2);
	exit(EXIT_FAILURE);
}

void		add_dump_flag(char **argv, int position)
{
	int		i;
	int		num;

	i = position;
	if (!argv[i + 1] || !ft_isnumeric_str(argv[i + 1]))
		invalid_dump_arg_err(argv[i + 1]);
	else
	{
		num = ft_atoi(argv[i + 1]);
		if (num < 1)
			invalid_dump_num(num);
		g_flags[FLAG_DUMP_I].present = TRUE;
		g_flags[FLAG_DUMP_I].data.num = num;
		argv[i + 1] = NULL;
	}
}
