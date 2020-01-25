/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:52:33 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/24 23:54:48 by obelouch         ###   ########.fr       */
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
	return (1);
}
