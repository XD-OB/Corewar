/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 05:14:25 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/18 08:16:46 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			conv_u_1(t_lst *lst, char **str, char *nbr)
{
	char			c;
	int				i;
	size_t			size;

	size = ft_max(ft_strlen(nbr), lst->format->width);
	if (!(*str = ft_strnew(size)))
		return (-1);
	c = (ft_strchr(lst->format->flag, '0') && lst->format->precis) ? '0' : ' ';
	if (ft_strchr(lst->format->flag, '-'))
	{
		ft_strcpy(*str, nbr);
		i = ft_strlen(nbr);
		while (i < (int)size)
			(*str)[i++] = ' ';
	}
	else
	{
		i = 0;
		while (i < (int)(size - ft_strlen(nbr) + 1))
			(*str)[i++] = c;
		ft_strcpy(&(*str)[--i], nbr);
	}
	return (0);
}

static void			conv_u_2(t_lst *lst, char **str, char *nbr, t_chr **mychr)
{
	if (lst->format->precis > 0 && lst->format->precis < lst->format->width)
		precis_u(str, lst->format, ft_strlen(nbr));
	else if (lst->format->precis >= lst->format->width)
	{
		free(*str);
		*str = all_zero_u(nbr, lst->format->precis);
	}
	(*mychr)->str = *str;
	free(nbr);
	(*mychr)->len = ft_strlen(*str);
}

/*
**	str[0] = str | str[1] = nbr
*/

void				conv_u(t_lst *lst, t_chr **mychr, va_list ap)
{
	char			*str[2];
	unsigned long	n;

	flag_star(lst->format, ap);
	n = (flag_dollar(lst)) ? cast_xxoub(*(lst->arglist), lst->format)
		: cast_xxoub(ap, lst->format);
	if (n == 0 && !lst->format->precis)
	{
		(*mychr)->str = ft_strcnew(lst->format->width, ' ');
		((*mychr)->str)[lst->format->width] = '\0';
		(*mychr)->len = lst->format->width;
		return ;
	}
	str[1] = ft_ultoa(n);
	flag_apostrophe(&str[1], lst->format);
	if (lst->format->precis <= 0)
	{
		if (conv_u_1(lst, &str[0], str[1]) == -1)
			return ;
	}
	else
		str[0] = ft_strdup(str[1]);
	conv_u_2(lst, &str[0], str[1], mychr);
}
