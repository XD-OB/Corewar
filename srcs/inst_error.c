/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:00:48 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/20 08:48:36 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		check_aloneinst(t_op *op_tab, char *str)
{
	char		*op;
	int			op_nbr;
	int			i;

	i = 0;
	while (str[i] && !ft_isblank(str[i]))
		i++;
	if (str[i] == '\0')
	{
		ft_printf("Syntax Error!\n");
		return ;
	}
	op = ft_strsub(str, 0, i++);
	if (!(op_nbr = is_op(op_tab, op)))
	{
		ft_printf("Invalid Operation: %s\n", op);
		free(op);
		return ;
	}
	free(op);
	check_args(op_tab, op_nbr, str, i);
}

static int		there_islabel(char *str)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR &&
			ft_strchr(LABEL_CHARS, str[i]))
		i++;
	if (str[i] != LABEL_CHAR)
		return (0);
	return (1);
}

static void		check_instlabel(t_op *op_tab, char *str)
{
	char		*instruct;
	int			i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR &&
			ft_strchr(LABEL_CHARS, str[i]))
		i++;
	i++;
	while (ft_isblank(str[i]))
		i++;
	if (str[i] == '\0')
	{
		ft_printf("Cant take it as label without [%c]\n", LABEL_CHAR);
		return ;
	}
	instruct = ft_strtrim(&str[i]);
	check_aloneinst(op_tab, instruct);
	free(instruct);
}

void			exit_inst_error(t_sfile *sfile, t_chr *curr)
{
	ft_printf("line %{red}%d%{eoc}: ", curr->len);
	ft_trimstr(&curr->str);
	if (there_islabel(curr->str))
		check_instlabel(sfile->op_tab, curr->str);
	else
		check_aloneinst(sfile->op_tab, curr->str);
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}
