/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:52:33 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/28 02:20:18 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_comment(char *str)
{
	size_t		i;

	i = 0;
	while (ft_isblank(str[i]))
		i++;
	if (str[i] == COMMENT_CHAR)
		return (1);
	return (0);
}

int		is_cmd(char *str, char *cmd)
{
	if (ft_strnequ(str, cmd, ft_strlen(cmd)))
		return (1);
	return (0);
}

int		is_cmds(char *str)
{
	if (ft_strnequ(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		return (1);
	if (ft_strnequ(str, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		return (1);
	return (0);
}

int		is_label(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(LABEL_CHARS, str[i]))
			return (0);
		i++;
	}
	return ((i > 0) ? 1 : 0);
}
