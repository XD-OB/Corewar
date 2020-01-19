/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:44:56 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/19 05:20:55 by obelouch         ###   ########.fr       */
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
		treate_file(av[i++], &asmbl);
	return (EXIT_SUCCESS);
}
