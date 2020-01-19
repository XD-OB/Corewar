/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:02:48 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/19 04:41:19 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	exit_serror(t_sfile *sfile, int type)
{
	free_sfile(sfile);
	if (type == ERROR_FD)
		ft_dprintf(2, "Error While Creating the .cor File!\n");
	else if (type == ERROR_ALLOC)
		ft_dprintf(2, "Can't Allocate Memory\n");
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

void	exit_qerror(t_sfile *sfile, t_chr *def, int type)
{
	ft_dprintf(2, "line %{red}%d%{eoc}:", def->len);
	if (type == ERROR_LESS_QUOTES)
		ft_dprintf(2, " Closing quote not found!\n");
	else if (type == ERROR_CHAR_QUOTES)
		ft_dprintf(2, " Character before the quote!\n");
	else if (type == ERROR_NO_STR)
		ft_dprintf(2, " No string after the parameter!\n");
	else if (type == ERROR_NO_QUOTES)
		ft_dprintf(2, " No Quotes for the string!\n");
	close(sfile->param_asm.fd);
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}
