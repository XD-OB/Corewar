/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 07:41:35 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/20 07:42:47 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				is_cmd_comment(char *str)
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

int				is_cmd_name(char *str)
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

int				count_dquotes(t_sfile *sfile, t_chr *curr, char *str)
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
