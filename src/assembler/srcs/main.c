/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:44:56 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/29 01:04:17 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	t_asm	asmbl;
	int		i;

	if (ac == 1)
		exit_usage(av[0]);
	init_asmbl(&asmbl);
	i = save_options(&asmbl, ac, av);
	while (i < ac)
	{
		if (asmbl.multi && !asmbl.a)
			ft_printf("\n%{cyan}%s:%{eoc}\n", av[i]);
		treate_file(av[i++], &asmbl);
	}
	return (EXIT_SUCCESS);
}
