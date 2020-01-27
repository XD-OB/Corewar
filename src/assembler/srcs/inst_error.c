/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:00:48 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/27 03:27:49 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		wrong_cmd_op(char **str)
{
	if (ft_strequ(*str, NAME_CMD_STRING) ||
		ft_strequ(*str, COMMENT_CMD_STRING))
		ft_dprintf(2, "Duplicated command: ");
	else
		ft_dprintf(2, "Invalid Operation: ");
	ft_dprintf(2, "%{red}%s%{eoc}\n", *str);
	free(*str);
}

static void		check_aloneinst(t_op *op_tab, char *str)
{
	char		*op;
	int			op_nbr;
	int			i;

	i = 0;
	while (str[i] && !ft_isblank(str[i]))
		i++;
	op = ft_strsub(str, 0, i++);
	if (!(op_nbr = is_op(op_tab, op)))
	{
		wrong_cmd_op(&op);
		return ;
	}
	i = ft_strlen(op);
	while (ft_isblank(str[i]))
		i++;
	free(op);
	check_args(op_tab, op_nbr, &str[i]);
}

static void		exit_label_error(t_sfile *sfile, char ***tab, int i)
{
	ft_dprintf(2, "[%{red}%s%{eoc}] ", (*tab)[i]);
	ft_dprintf(2, "contain invalid characters!\n");
	tabstr_free(tab);
	close(sfile->param_asm.fd);
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}

void			exit_inst_error(t_sfile *sfile, t_chr *curr)
{
	char		**tab;
	int			len;
	int			i;

	i = -1;
	ft_dprintf(2, "line %{red}%d%{eoc}: ", curr->len);
	tab = split_labels(curr->str);
	len = tabstr_len(tab);
	if (tabstr_len(tab) < 1)
		ft_dprintf(2, "A %{red}%c%{eoc} without a label\n", LABEL_CHAR);
	else
	{
		while (++i < len - 1)
			if (!is_label(tab[i]))
				exit_label_error(sfile, &tab, i);
		if (curr->str[ft_strlen(curr->str) - 1] != LABEL_CHAR)
			check_aloneinst(sfile->op_tab, tab[i]);
		else if (!is_label(tab[i]))
			exit_label_error(sfile, &tab, i);
		else
			ft_dprintf(2, "Syntax Error!\n");
	}
	tabstr_free(&tab);
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}
