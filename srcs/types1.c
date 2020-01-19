/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:06:40 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/19 01:15:40 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	pass_digit(char *str, int *i)
{
	if (str[*i] == '-')
		(*i)++;
	if (!ft_isdigit(str[(*i)++]))
		return (0);
	while (ft_isdigit(str[*i]))
		(*i)++;
	return (1);
}

static int	is_arithm(char *str)
{
	int		i;

	i = 0;
	if (str[i++] != '(')
		return (0);
	if (!pass_digit(str, &i))
		return (0);
	if (str[i] == ' ')
		i++;
	if (str[i] != '+' && str[i] != '-' &&
		str[i] != '*' && str[i] != '/')
		return (0);
	i++;
	if (str[i] == ' ')
		i++;
	if (!pass_digit(str, &i))
		return (0);
	if (str[i++] != ')')
		return (0);
	if (str[i])
		return (0);
	return (1);
}

int			is_reg(char *str)
{
	int		n;

	if (str[0] != 'r')
		return (0);
	if (str[1] == '(')
		return (is_arithm(&str[1]));
	if (ft_strlen(str) == 2)
	{
		if (!ft_isdigit(str[1]))
			return (0);
		n = str[1] - 48;
		if (n == 0 || n > REG_NUMBER)
			return (0);
		return (1);
	}
	else if (ft_strlen(str) == 3)
	{
		if (!ft_isdigit(str[1]) || !ft_isdigit(str[2]))
			return (0);
		n = ft_atoi(&str[1]);
		if (n == 0 || n > REG_NUMBER)
			return (0);
		return (1);
	}
	return (0);
}

int			is_dir(char *str)
{
	int		i;

	if (str[0] != DIRECT_CHAR)
		return (0);
	if (str[1] == LABEL_CHAR)
	{
		i = 1;
		while (str[++i])
			if (!ft_strchr(LABEL_CHARS, str[i]))
				return (0);
		return (1);
	}
	if (str[1] == '(')
		return (is_arithm(&str[1]));
	return (ft_is_strdigit(&str[1]));
}

int			is_ind(char *str)
{
	int		i;

	if (str[0] == LABEL_CHAR)
	{
		i = 0;
		while (str[++i])
			if (!ft_strchr(LABEL_CHARS, str[i]))
				return (0);
		return (1);
	}
	if (str[0] == '(')
		return (is_arithm(str));
	return (ft_is_strdigit(str));
}
