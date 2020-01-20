/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:00:35 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/20 07:04:45 by obelouch         ###   ########.fr       */
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

int				quotes_nbr(char *str)
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
		free(line);
		q += quotes_nbr(line);
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

t_inst			*create_inst(void)
{
	t_inst		*inst;
	int			i;

	if (!(inst = (t_inst*)malloc(sizeof(t_inst))))
		return (NULL);
	inst->labels = NULL;
	inst->op_nbr = 0;
	inst->nbr_bytes = 0;
	i = 0;
	while (i < 3)
	{
		inst->args[i].str = NULL;
		inst->args[i].type = 0;
		inst->args[i].value = 0;
		i++;
	}
	return (inst);
}
