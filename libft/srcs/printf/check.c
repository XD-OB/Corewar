/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 03:16:14 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/08 22:52:22 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_repeat(char *str, char c)
{
	int			count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	if (count > 1)
		return (1);
	return (0);
}

static int		ret_val(int c, int cc)
{
	if (c == 0 && cc == 1)
		return (cc);
	if (cc == 0 && c == 1)
		return (c);
	if (cc == 0 && c == 0)
		return (-1);
	return (0);
}

static int		not_repstr(char *str, char c)
{
	int			countc;
	int			countcc;

	countc = 0;
	countcc = 0;
	while (*str)
	{
		if (*str == c)
		{
			if (*(str + 1) == c)
			{
				if (*(str + 2) == c)
					return (0);
				countcc++;
				str++;
			}
			else
				countc++;
		}
		str++;
	}
	return (ret_val(countc, countcc));
}

int				is_valid(char *str)
{
	char		*ndbl;
	int			i;

	i = 0;
	ndbl = " 0+-#'*L$";
	while (ndbl[i])
		if (is_repeat(str, ndbl[i++]))
			return (0);
	if (!not_repstr(str, 'h') || !not_repstr(str, 'l'))
		return (0);
	if (not_repstr(str, 'h') != -1 && not_repstr(str, 'l') != -1)
		return (0);
	if ((not_repstr(str, 'h') != -1 || not_repstr(str, 'l') != -1)
			&& ft_strchr(str, 'L'))
		return (0);
	return (1);
}
