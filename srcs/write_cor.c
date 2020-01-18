/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:38:29 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 20:38:47 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			write_short(short n, int fd)
{
	char		c[2];

	if (n < 0)
	{
		n = ~(n * -1);
		n += 0x1;
	}
	c[0] = (n >> 8) & 0xff;
	c[1] = n & 0xff;
	ft_putchar_fd(c[0], fd);
	ft_putchar_fd(c[1], fd);
}

void			write_int(int n, int fd)
{
	char		c[4];

	if (n < 0)
	{
		n = ~(n * -1);
		n += 1;
	}
	c[0] = (n >> 24) & 0xff;
	c[1] = (n >> 16) & 0xff;
	c[2] = (n >> 8) & 0xff;
	c[3] = n & 0xff;
	ft_putchar_fd(c[0], fd);
	ft_putchar_fd(c[1], fd);
	ft_putchar_fd(c[2], fd);
	ft_putchar_fd(c[3], fd);
}

static void		write_champ_name(char *name, int fd)
{
	int			nbr_zero;
	int			i;

	nbr_zero = PROG_NAME_LENGTH - ft_strlen(name) + 4;
	ft_putstr_fd(name, fd);
	i = 0;
	while (i++ < nbr_zero)
		ft_putchar_fd(0, fd);
}

static void		write_champ_comment(char *comment, int fd)
{
	int			nbr_zero;
	int			i;

	nbr_zero = COMMENT_LENGTH - ft_strlen(comment) + 4;
	ft_putstr_fd(comment, fd);
	i = 0;
	while (i++ < nbr_zero)
		ft_putchar_fd(0, fd);
}

void			write_cor(t_sfile sfile, char *file_name)
{
	char		*file;
	int			fd;

	file = ft_strjoin(file_name, ".cor");
	fd = open(file, O_CREAT | O_WRONLY, 0666);
	free(file);
	if (fd < 0)
		exit_serror(&sfile, ERROR_FD);
	write_int(COREWAR_EXEC_MAGIC, fd);
	write_champ_name(sfile.name, fd);
	write_int(sfile.exec_size, fd);
	write_champ_comment(sfile.comment, fd);
	write_exec_code(sfile, fd);
	close(fd);
}
