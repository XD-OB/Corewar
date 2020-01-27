/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_cmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:01:04 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/27 23:15:32 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		true_strlen(char *str)
{
	int			len;
	int			i;

	i = 0;
	if (str[i++] != '\"')
		return (-1);
	len = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			break ;
		if (str[i] == '\\' && ft_strchr("\"\'\\", str[i + 1]))
			i++;
		len++;
		i++;
	}
	if (str[i] == '\"')
		return (len);
	return (-1);
}

static char		*q_take_value(char *str)
{
	char		*new;
	int			len;
	int			i;
	int			j;

	len = true_strlen(str);
	if (len == -1)
		return (NULL);
	i = 1;
	j = 0;
	new = ft_strnew(len);
	while (j < len)
	{
		if (str[i] == '\\' && ft_strchr("\'\"\\", str[i + 1]))
			i++;
		new[j++] = str[i++];
	}
	while (str[++i])
		if (!ft_isblank(str[i]))
		{
			free(new);
			new = NULL;
			break ;
		}
	return (new);
}

static char		*val_cmd(char *str, char *cmd)
{
	char		*new;
	size_t		i;

	i = ft_strlen(cmd);
	while (ft_isblank(str[i]))
		i++;
	if (!str[i])
	{
		if (!ft_strcmp(cmd, NAME_CMD_STRING))
			new = ft_strdup("Anonym");
		if (!ft_strcmp(cmd, COMMENT_CMD_STRING))
			new = ft_strdup("Nothing to say :(");
	}
	else
		new = q_take_value(&str[i]);
	return (new);
}

int				get_name_cmt(t_sfile *sfile, t_chr *curr, char *str)
{
	if (str[0] == '\0')
		return (0);
	if (is_cmd(str, NAME_CMD_STRING) && !sfile->name)
	{
		sfile->name = val_cmd(str, NAME_CMD_STRING);
		if (!sfile->name)
			exit_ass_error(sfile, curr, ERROR_SYNTAX);
		if (ft_strlen(sfile->name) > PROG_NAME_LENGTH)
			exit_ass_error(sfile, curr, ERROR_NAME_LENGTH);
		return (0);
	}
	if (is_cmd(str, COMMENT_CMD_STRING) && !sfile->comment)
	{
		sfile->comment = val_cmd(str, COMMENT_CMD_STRING);
		if (!sfile->comment)
			exit_ass_error(sfile, curr, ERROR_SYNTAX);
		if (ft_strlen(sfile->comment) > COMMENT_LENGTH)
			exit_ass_error(sfile, curr, ERROR_COMMENT_LENGTH);
		return (0);
	}
	return (1);
}
