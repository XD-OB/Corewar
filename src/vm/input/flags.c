/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 14:20:30 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 21:51:54 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	unsupported_err(char *op)
{
	ft_putstr_fd(op, 2);
	ft_putendl_fd(" option is not recognized", 2);
	exit(EXIT_FAILURE);
}

void		set_flags(char **argv, int i)
{
	if (ft_strequ(&argv[i][1], FLAG_ORDER_T))
		add_order_flag(argv, i);
	else if (ft_strequ(&argv[i][1], FLAG_VISUAL_T))
		g_flags[FLAG_VISUAL_I].present = TRUE;
	else if (ft_strequ(&argv[i][1], FLAG_DUMP_T))
		add_dump_flag(argv, i);
	else if (ft_strequ(&argv[i][1], FLAG_D_T))
		g_flags[FLAG_D_I].present = TRUE;
	else if (ft_strequ(&argv[i][1], FLAG_S_T))
		add_s_flag(argv, i);
	else if (ft_strequ(&argv[i][1], FLAG_A_T))
		g_flags[FLAG_A_I].present = TRUE;
	else if (ft_strequ(&argv[i][1], FLAG_SM_D_T))
		add_sm_d_flag(argv, i);
	else
		unsupported_err(argv[i]);
}

void		process_flags(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i] && argv[i][0] == '-')
		{
			set_flags(argv, i);
			argv[i] = NULL;
		}
	}
}
