/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 22:32:33 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 03:55:40 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	extention_error(char *file)
{
	ft_putstr_fd("error: ", 2);
	ft_putendl_fd(file, 2);
	ft_putendl_fd("file extention was not recognized.", 2);
	exit(EXIT_FAILURE);
}

static void	invalid_file_error(char *file)
{
	ft_putstr_fd("error: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(" ", 2);
	ft_putendl_fd(file, 2);
	exit(EXIT_FAILURE);
}

static void	close_error(void)
{
	ft_putstr_fd("error: ", 2);
	ft_putendl_fd(strerror(errno), 2);
	exit(EXIT_FAILURE);
}

void		check_players_number(int argc, char **argv)
{
	int i;
	int pl_num;
	int max_order_num;

	pl_num = 0;
	max_order_num = 0;
	i = 0;
	while (++i < argc)
		if (argv[i])
			pl_num++;
	i = -1;
	while (++i < MAX_PLAYERS)
		if (g_flags[FLAG_ORDER_I].data.order_data[i])
			max_order_num = i + 1;
	if (max_order_num > pl_num)
	{
		ft_putendl_fd(
			"error: player number must not exeed number of players", 2);
		exit(EXIT_FAILURE);
	}
}

void		get_players_data(int argc, char **argv)
{
	int		i;
	int		fd;
	int		pln;

	pln = 0;
	check_players_number(argc, argv);
	i = 0;
	while (++i < argc)
	{
		if (argv[i])
		{
			if (!ft_ends_with(argv[i], COREWAR_FILE_EXTENTIN))
				extention_error(argv[i]);
			if ((fd = open(argv[i], O_RDONLY)) == -1)
				invalid_file_error(argv[i]);
			if (++pln > 4)
			{
				ft_putendl_fd("error : maximum suported players are 4", 2);
				exit(EXIT_FAILURE);
			}
			get_player_data(fd, argv[i]);
			if (close(fd) == -1)
				close_error();
		}
	}
}
