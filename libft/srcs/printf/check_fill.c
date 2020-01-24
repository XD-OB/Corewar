/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 05:14:43 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/18 06:51:46 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		part_check1(char **flag, char **str, t_lst **curr)
{
	if (!**str)
		return (adv_freeflag(flag));
	if (ft_isdigit(**str))
	{
		(*curr)->format->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	if (!**str)
		return (adv_freeflag(flag));
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			(*curr)->format->precis = -2;
			(*str)++;
		}
		else
			(*curr)->format->precis = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	return (0);
}

static void		part_check2(char **str, char **flag, char **p)
{
	if ((**str == 'l' && !ft_strstr(*flag, "ll")) || !ft_strchr(*flag, **str)
				|| (**str == 'h' && !ft_strstr(*flag, "hh")))
	{
		**p = **str;
		(*p)++;
	}
	(*str)++;
}

static int		part_check3(t_lst **curr, char **str, char **flag, int pos)
{
	(*curr)->format->pos = pos;
	if (**str == '{')
	{
		(*str)++;
		(*curr)->format->flag = ft_strcolor(*str);
		(*curr)->format->convers = '}';
		return (1);
	}
	*flag = ft_strnew(200);
	return (0);
}

static void		part_check4(t_lst **curr, char **str, char **p, va_list tmp)
{
	**p = **str;
	if (**str == '$')
	{
		(*str)++;
		(*curr)->arglist = (va_list*)malloc(sizeof(va_list));
		va_copy(*((*curr)->arglist), tmp);
		(*curr)->format->argn = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	(*p)++;
}

int				check_fill(va_list tmp, char *str, int pos, t_lst *curr)
{
	char		*flag;
	char		*p;

	if (part_check3(&curr, &str, &flag, pos))
		return (0);
	p = flag;
	while (is_preflag(*str))
	{
		if (!ft_strchr(flag, *str))
			part_check4(&curr, &str, &p, tmp);
		else
			str++;
	}
	if (part_check1(&flag, &str, &curr))
		return (-1);
	while (is_postflag(*str))
		part_check2(&str, &flag, &p);
	if (!*str)
		return (adv_freeflag(&flag));
	curr->format->convers = *str;
	curr->format->flag = flag;
	return (0);
}
