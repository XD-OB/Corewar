/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:02:48 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/25 00:39:52 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	exit_usage(char *exe)
{
	ft_dprintf(2, "%{red}Usage:%{eoc} %s", exe);
	ft_dprintf(2, " [-ra] <sourcefile.s> ...\n");
	ft_dprintf(2, "  --reverse   -r : deassembler mode\n");
	ft_dprintf(2, "  --annotated -a : annotated mode\n");
	exit(EXIT_FAILURE);
}

void	exit_serror(t_sfile *sfile, int type)
{
	free_sfile(sfile);
	if (type == ERROR_FD)
		ft_dprintf(2, "Error While Creating the .cor File!\n");
	else if (type == ERROR_ALLOC)
		ft_dprintf(2, "Can't Allocate Memory\n");
	else if (type == ERROR_NO_INSTS)
		ft_dprintf(2, "No Instructions in this file\n");
	else if (type == ERROR_NC_NAMECMT_END)
		ft_dprintf(2, "File end whitout the necessary cmds\n");
	else if (type == ERROR_NO_NL)
		ft_dprintf(2, "The last instruction doesn't have new line\n");
	else if (type == ERROR_FEMPTY)
		ft_dprintf(2, "File whitout cmds and instructions\n");
	else if (type == ERROR_EXEC_SIZE)
	{
		ft_dprintf(2, "Executable Code Exceed the Max!");
		ft_dprintf(2, " (Max %d)\n", CHAMP_MAX_SIZE);
	}
	close(sfile->param_asm.fd);
	exit(EXIT_FAILURE);
}

void	exit_berror(t_bfile *bfile, int type)
{
	free_bfile(bfile);
	if (type == ERROR_FD)
		ft_dprintf(2, "Error While Creating the .s File!\n");
	else if (type == ERROR_ALLOC)
		ft_dprintf(2, "Error Will Allocating Memory\n");
	else if (type == ERROR_EXEC_SIZE)
	{
		ft_dprintf(2, "Executable Code Exceed the Max!");
		ft_dprintf(2, " (Max %d)\n", CHAMP_MAX_SIZE);
	}
	close(bfile->param_asm.fd);
	exit(EXIT_FAILURE);
}
