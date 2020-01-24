/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sm_d_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 07:09:50 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 21:52:46 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		add_sm_d_flag(char **argv, int position)
{
	int i;
	int num;

	i = position;
	if (!argv[i + 1] || !ft_isnumeric_str(argv[i + 1]))
		invalid_dump_arg_err(argv[i + 1]);
	else
	{
		num = ft_atoi(argv[i + 1]);
		if (num < 1)
			invalid_dump_num(num);
		g_flags[FLAG_SM_D_I].present = TRUE;
		g_flags[FLAG_SM_D_I].data.num = num;
		argv[i + 1] = NULL;
	}
}
