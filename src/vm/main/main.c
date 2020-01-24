/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 16:25:06 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/22 06:04:16 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int argc, char **argv)
{
	if (argc <= 1)
		print_usage_and_exit();
	process_flags(argc, argv);
	get_players_data(argc, argv);
	run_vm();
}

void	print_usage_and_exit(void)
{
	ft_printf("%{red}usage%{eoc}: ./corewar [-v] [-dump nbr_cycles] ");
	ft_printf("[[-n number] champion1.cor] ...\n");
	ft_printf("options:\n");
	ft_printf("      %{CYAN}a%{eoc} : activate the affich mode\n");
	ft_printf("      %{CYAN}v%{eoc} : activate the visualizer mode\n");
	ft_printf("      %{CYAN}D%{eoc} : dump memory cycle by cycle\n");
	ft_printf("      %{CYAN}d%{eoc} <nbr_cycle>   : dump in mode 64 the ");
	ft_printf("<nbr_cycle> cycle\n");
	ft_printf("      %{CYAN}dump%{eoc} <nbr_cycle>: dump in mode 32 the ");
	ft_printf("<nbr_cycle> cycle\n");
	ft_printf("      %{CYAN}s%{eoc} <nbr_cycle>   : dump <nbr_cycle> ");
	ft_printf("cycles and press enter key to continue\n");
	ft_printf("      %{CYAN}n%{eoc} <player_nbr>  : assign <player_nbr> ");
	ft_printf("to the next player\n");
	ft_printf("=============================================");
	ft_printf("==============================\n");
	exit(EXIT_SUCCESS);
}
