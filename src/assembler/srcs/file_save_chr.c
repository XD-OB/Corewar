/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_save_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 00:05:30 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/30 23:29:07 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		delete_comment(char **str)
{
	char		*new;
	int			i;
	int			q;

	i = 0;
	q = 0;
	if (!*str)
		return ;
	while ((*str)[i] && q < 2)
	{
		if ((*str)[i] == '\\')
			i++;
		else if ((*str)[i] == '\"')
			q++;
		i++;
	}
	if (!(*str)[i] && q == 0)
		i = 0;
	while ((*str)[i] && (*str)[i] != COMMENT_CHAR)
		i++;
	new = ft_strsub(*str, 0, i);
	free(*str);
	*str = ft_strtrim(new);
	free(new);
}

static int		quotes_nbr(char *str)
{
	size_t		i;
	int			q;

	i = 0;
	q = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			i++;
		else if (str[i] == '\"')
			q++;
		i++;
	}
	return (q);
}

static int		treate_line(char **line, int fd, int *q)
{
	char		*tmp;
	int			ret;
	int			pas;

	pas = 0;
	tmp = NULL;
	if (is_cmds(*line))
	{
		while ((*q % 2) != 0 && (ret = gnl(fd, &tmp)) > 0)
		{
			*q += quotes_nbr(tmp);
			str_n_combin(line, tmp);
			FREE(tmp);
			pas++;
		}
	}
	if (tmp)
		free(tmp);
	delete_comment(line);
	return (pas);
}

static t_chr	*return_val(t_chr **input, int ret)
{
	if (ret != 0 && *input)
	{
		chr_free(input);
		*input = NULL;
	}
	return (*input);
}

t_chr			*file_save_chr(int fd, int *nl)
{
	t_chr		*input;
	char		*line;
	int			ret;
	int			ind[2];
	int			q;

	q = 0;
	ind[0] = 1;
	input = NULL;
	line = NULL;
	while ((ret = gnl(fd, &line)) > 0)
	{
		q += quotes_nbr(line);
		if (!is_comment(line) && !ft_is_strblank(line))
		{
			ind[1] = treate_line(&line, fd, &q);
			chr_addnode(&input, line, ind[0]);
			ind[0] += ind[1];
			*nl = ret;
		}
		FREE(line);
		(ind[0])++;
	}
	if (line)
		free(line);
	return (return_val(&input, ret));
}
