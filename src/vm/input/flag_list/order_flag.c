/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 12:23:06 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/22 06:21:42 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	invalid_arg_err(char *arg)
{
	ft_putstr_fd("invalid argument for -n option : ", 2);
	ft_putendl_fd(arg, 2);
	ft_putstr_fd("only accept numeric arguments\n", 2);
	exit(EXIT_FAILURE);
}

static void	invalid_num(int n)
{
	ft_putstr_fd("error: invalid player number : ", 2);
	ft_putnbr_fd(n, 2);
	ft_putstr_fd("\nplayer number should be in range 1 and MAXPLAYERS = ", 2);
	ft_putnbr_fd(MAX_PLAYERS, 2);
	ft_putstr_fd("\n", 1);
	exit(EXIT_FAILURE);
}

static void	dup_num_error(void)
{
	ft_dprintf(2, "error : two players can not have the same number\n");
	exit(EXIT_FAILURE);
}

void		add_order_flag(char **argv, int position)
{
	int		num;
	int		i;

	i = position;
	if (!argv[i + 1] || !ft_isnumeric_str(argv[i + 1]))
		invalid_arg_err(argv[i + 1]);
	else
	{
		num = ft_atoi(argv[i + 1]);
		if (num > MAX_PLAYERS || num < 1)
			invalid_num(num);
		if (g_flags[FLAG_ORDER_I].data.order_data[num - 1])
			dup_num_error();
		g_flags[FLAG_ORDER_I].present = TRUE;
		if (!argv[i + 2])
		{
			ft_putstr_fd("third argument for -n argument is missing\n", 2);
			exit(EXIT_FAILURE);
		}
		g_flags[FLAG_ORDER_I].data.order_data[num - 1] = argv[i + 2];
		argv[i + 1] = NULL;
	}
}
