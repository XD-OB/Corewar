/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:02:48 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/19 01:24:57 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	exit_serror(t_sfile *sfile, int type)
{
	free_sfile(sfile);
	if (type == ERROR_FD)
		ft_printf("Error While Creating the .cor File!\n");
	else if (type == ERROR_ALLOC)
		ft_printf("Can't Allocate Memory\n");
	else if (type == ERROR_EXEC_SIZE)
	{
		ft_printf("Executable Code Exceed the Max!");
		ft_printf(" (Max %d)\n", CHAMP_MAX_SIZE);
	}
	exit(EXIT_FAILURE);
}

void	exit_berror(t_bfile *bfile, int type)
{
	free_bfile(bfile);
	if (type == ERROR_FD)
		ft_printf("Error While Creating the .s File!\n");
	else if (type == ERROR_ALLOC)
		ft_printf("Error Will Allocating Memory\n");
	else if (type == ERROR_EXEC_SIZE)
	{
		ft_printf("Executable Code Exceed the Max!");
		ft_printf(" (Max %d)\n", CHAMP_MAX_SIZE);
	}
	exit(EXIT_FAILURE);
}

void	exit_qerror(t_sfile *sfile, t_chr *def, int type)
{
	ft_printf("line %{red}%d%{eoc}:", def->len);
	if (type == ERROR_LESS_QUOTES)
		ft_printf(" Closing quote not found!\n");
	else if (type == ERROR_CHAR_QUOTES)
		ft_printf(" Character before the quote!\n");
	else if (type == ERROR_NO_STR)
		ft_printf(" No string after the parameter!\n");
	else if (type == ERROR_NO_QUOTES)
		ft_printf(" No Quotes for the string!\n");
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}
