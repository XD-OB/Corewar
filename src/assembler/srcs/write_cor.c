/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:38:29 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/26 04:48:59 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

void			write_cor(t_sfile sfile)
{
	char		*file;
	int			fd;

	file = ft_strjoin(sfile.file_name, ".cor");
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	free(file);
	if (fd < 0)
		exit_serror(&sfile, ERROR_FD);
	ft_printf("Writing output program to ");
	ft_printf("%{GREEN}%s.cor%{eoc}\n", sfile.file_name);
	write_int(COREWAR_EXEC_MAGIC, fd);
	write_champ_name(sfile.name, fd);
	write_int(sfile.exec_size, fd);
	write_champ_comment(sfile.comment, fd);
	write_exec_code(sfile, fd);
	close(fd);
}
