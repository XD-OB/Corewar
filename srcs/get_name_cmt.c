/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_cmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:01:04 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/20 01:33:18 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		count_dquotes(t_sfile *sfile, t_chr *curr, char *str)
{
	int			q;
	int			i;

	i = 1;
	q = 1;
	if (str[0] == '\0')
		exit_qerror(sfile, curr->len, ERROR_NO_STR);
	if (str[0] != '"')
		exit_qerror(sfile, curr->len, ERROR_CHAR_QUOTES);
	while (str[i])
	{
		if (str[i] == '"')
			q++;
		i++;
	}
	return (q);
}

static void		str_n_combin(char **s1, char *s2)
{
	ft_strcombin(s1, "\n");
	ft_strcombin(s1, s2);
}

static char		*complete_line(t_sfile *sfile, t_chr **curr, char *str)
{
	int			line;
	char		*complete;
	int			q;

	q = count_dquotes(sfile, *curr, str);
	complete = ft_strdup(str);
	if (q > 1)
		return (complete);
	if (q != 0)
	{
		line = (*curr)->len;
		*curr = (*curr)->next;
		while (*curr)
		{
			str_n_combin(&complete, (*curr)->str);
			if (ft_strchr((*curr)->str, '"'))
				return (complete);
			(*curr) = (*curr)->next;
		}
		free(complete);
		exit_qerror(sfile, line, ERROR_LESS_QUOTES);
	}
	free(complete);
	exit_qerror(sfile, (*curr)->len, ERROR_NO_QUOTES);
	return (complete);
}

static void		find_start_end_q(char *str, int *start, int *end)
{
	int			i;
	int			j;

	i = 0;
	while (str[i] != '"')
		i++;
	i++;
	j = i;
	while (str[j] != '"')
		j++;
	j--;
	*start = i;
	*end = j;
}

static char		*get_q_text_q(t_sfile *sfile, t_chr **curr, char *str)
{
	char		*complete;
	char		*text;
	int			start;
	int			end;
	int			i;

	i = 0;
	text = NULL;
	complete = complete_line(sfile, curr, str);
	find_start_end_q(complete, &start, &end);
	i = end + 2;
	while (ft_isblank(complete[i]))
		i++;
	if (complete[i] == '\0' || complete[i] == COMMENT_CHAR)
		text = ft_strsub(complete, start, end - start + 1);
	free(complete);
	if (!text)
		exit_ass_error(sfile, *curr, ERROR_LEXICAL);
	return (text);
}

static int		is_cmd_comment(char *str)
{
	size_t		len;
	size_t		i;

	i = 0;
	while (ft_isblank(str[i]))
		i++;
	len = ft_strlen(COMMENT_CMD_STRING);
	if (!ft_strncmp(&str[i], COMMENT_CMD_STRING, len))
		return (1);
	return (0);
}

static int		is_cmd_name(char *str)
{
	size_t		len;
	size_t		i;

	i = 0;
	while (ft_isblank(str[i]))
		i++;
	len = ft_strlen(NAME_CMD_STRING);
	if (!ft_strncmp(&str[i], NAME_CMD_STRING, len))
		return (1);
	return (0);
}

static char		*val_cmd(char *str, char *cmd)
{
	char		*new;
	size_t		i;

	i = 0;
	while (ft_isblank(str[i]))
		i++;
	i += ft_strlen(cmd);
	while (ft_isblank(str[i]))
		i++;
	if (!str[i])
	{
		if (!ft_strcmp(cmd, NAME_CMD_STRING))
			new = ft_strdup("\"Anonym\"");
		if (!ft_strcmp(cmd, COMMENT_CMD_STRING))
			new = ft_strdup("\"Nothing to say :(\"");
	}
	else
		new = ft_strdup(&str[i]);
	return (new);
}

int				get_name_cmt(t_sfile *sfile, t_chr **curr, char *str)
{
	char		*s;

	if (str[0] == '\0')
		return (0);
	if (is_cmd_name(str) && !sfile->name)
	{
		s = val_cmd(str, NAME_CMD_STRING);
		sfile->name = get_q_text_q(sfile, curr, s);
		free(s);
		if (ft_strlen(sfile->name) > PROG_NAME_LENGTH)
			exit_ass_error(sfile, *curr, ERROR_NAME_LENGTH);
		return (0);
	}
	if (is_cmd_comment(str) && !sfile->comment)
	{
		s = val_cmd(str, COMMENT_CMD_STRING);
		sfile->comment = get_q_text_q(sfile, curr, s);
		free(s);
		if (ft_strlen(sfile->comment) > COMMENT_LENGTH)
			exit_ass_error(sfile, *curr, ERROR_COMMENT_LENGTH);
		return (0);
	}
	return (1);
}
