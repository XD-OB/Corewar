/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_data_errors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 18:15:07 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/22 06:10:00 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	magic_header_error(char *file)
{
	ft_putstr_fd("invalid magic header in file ", 2);
	ft_putendl_fd(file, 2);
	exit(EXIT_FAILURE);
}

void	delimiter_error(char *file, char *befor_delimiter)
{
	ft_putstr_fd("error: delimiter (4 null bytes) is not located after ", 2);
	ft_putstr_fd(befor_delimiter, 2);
	ft_putstr_fd(" in file ", 2);
	ft_putendl_fd(file, 2);
}

void	check_prog_size(char *file, int prog_size)
{
	if (prog_size < 0 || prog_size > CHAMP_MAX_SIZE)
	{
		ft_putstr_fd("error: file ", 2);
		ft_putendl_fd(file, 2);
		ft_putstr_fd("champion exec code size out of range\n", 2);
		ft_putstr_fd("champion exec code size should be between 0 ", 2);
		ft_putstr_fd("and MAX_CHAMP_SIZE=", 2);
		ft_putnbr_fd(CHAMP_MAX_SIZE, 2);
		ft_putchar_fd('\n', 2);
		exit(EXIT_FAILURE);
	}
}

void	check_ex_code(int fd, char *file, int prog_size, int bytes_read)
{
	int		i;
	char	buff[1];

	i = read(fd, buff, 1);
	if (i > 0 || bytes_read != prog_size)
	{
		ft_putstr_fd("error: file ", 2);
		ft_putendl_fd(file, 2);
		ft_putstr_fd("champ executable code size does not match ", 2);
		ft_putstr_fd("actual executable code", 2);
		exit(EXIT_FAILURE);
	}
}
