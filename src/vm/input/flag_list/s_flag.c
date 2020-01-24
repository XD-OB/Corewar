/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 05:56:35 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 21:52:25 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		add_s_flag(char **argv, int position)
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
		g_flags[FLAG_S_I].present = TRUE;
		g_flags[FLAG_S_I].data.num = num;
		argv[i + 1] = NULL;
	}
}
