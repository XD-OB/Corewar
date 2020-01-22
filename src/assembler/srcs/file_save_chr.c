/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_save_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 00:05:30 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/21 00:06:20 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		is_comment(char *str)
{
	size_t		i;

	i = 0;
	while (ft_isblank(str[i]))
		i++;
	if (str[i] == '#')
		return (1);
	return (0);
}

static void		delete_comment(char **str, int q)
{
	char		*new;
	int			i;

	if (q % 2 != 0)
		return ;
	if (ft_is_strblank(*str) || is_comment(*str))
		new = ft_strnew(0);
	else
	{
		i = 0;
		while ((*str)[i] && (*str)[i] != COMMENT_CHAR)
			i++;
		if (!(*str)[i])
			return ;
		new = ft_strsub(*str, 0, i);
	}
	free(*str);
	*str = new;
}

static int		quotes_nbr(char *str)
{
	size_t		i;
	int			q;

	i = 0;
	q = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			q++;
		i++;
	}
	return (q);
}

t_chr			*file_save_chr(int fd)
{
	t_chr		*input;
	char		*line;
	int			ret;
	int			q;
	int			i;

	i = 1;
	input = NULL;
	line = NULL;
	q = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		delete_comment(&line, q);
		chr_addnode(&input, line, i);
		q += quotes_nbr(line);
		free(line);
		i++;
	}
	if (line)
		free(line);
	if (ret == 0)
		return (input);
	if (input)
		chr_free(&input);
	return (NULL);
}
