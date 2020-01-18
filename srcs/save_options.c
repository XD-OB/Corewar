/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:00:54 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 20:00:57 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		save_mini_opt(t_asm *asmbl, char *option, char *exe)
{
	int			i;

	i = 1;
	while (option[i])
	{
		if (option[i] == 'r')
			asmbl->r = 1;
		else if (option[i] == 'a')
			asmbl->a = 1;
		else
		{
			ft_printf("Invalid Option: %{red}%c%{eoc}\n", option[i]);
			exit_usage(exe);
		}
		i++;
	}
}

static void		save_long_opt(t_asm *asmbl, char *option, char *exe)
{
	if (!ft_strcmp(option, "--reverse"))
		asmbl->r = 1;
	else if (!ft_strcmp(option, "--annotated"))
		asmbl->a = 1;
	else
	{
		ft_printf("Invalid Option: %{red}%s%{eoc}\n", option);
		exit_usage(exe);
	}
}

int				save_options(t_asm *asmbl, int ac, char **av)
{
	int			i;

	i = 1;
	while (i < ac && av[i][0] == '-')
	{
		if (av[i][1] == '-')
			save_long_opt(asmbl, av[i], av[0]);
		else
			save_mini_opt(asmbl, av[i], av[0]);
		i++;
	}
	if (i == ac)
	{
		ft_printf("No file!\n");
		exit_usage(av[0]);
	}
	return (i);
}
