/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:06:17 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/21 00:43:19 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		write_s_insts(t_bfile bfile, int fd)
{
	t_list		*curr;
	t_inst		*inst;
	int			args_nbr;
	int			i;

	curr = bfile.insts;
	while (curr)
	{
		inst = (t_inst*)curr->content;
		ft_dprintf(fd, "  %-8s", bfile.op_tab[inst->op_nbr - 1].name);
		i = 0;
		args_nbr = bfile.op_tab[inst->op_nbr - 1].args_nbr;
		while (i < args_nbr)
		{
			ft_dprintf(fd, "%4s", inst->args[i].str);
			if (++i < args_nbr)
				ft_dprintf(fd, "%c ", SEPARATOR_CHAR);
		}
		ft_putstr_fd("\n", fd);
		curr = curr->next;
	}
}

static void		write_s_namecmt(t_bfile bfile, int fd)
{
	ft_dprintf(fd, "%cThis file Was ", COMMENT_CHAR);
	ft_putstr_fd("Disassembled by: Memory_Rapists\n", fd);
	ft_dprintf(fd, "%-15s", NAME_CMD_STRING);
	ft_dprintf(fd, "\"%s\"\n", (char*)bfile.name);
	ft_dprintf(fd, "%-15s", COMMENT_CMD_STRING);
	ft_dprintf(fd, "\"%s\"\n\n", bfile.comment);
}

void			write_s(t_bfile bfile)
{
	char		*file;
	int			fd;

	file = ft_strjoin(bfile.file_name, ".st");     //////////////////// .s
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	free(file);
	if (fd < 0)
		exit_berror(&bfile, ERROR_FD);
	ft_printf("Writing output program to ");
	ft_printf("%{GREEN}%s.s%{eoc}\n", bfile.file_name);
	write_s_namecmt(bfile, fd);
	write_s_insts(bfile, fd);
	close(fd);
}
