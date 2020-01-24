/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_pcolinv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:20:38 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 17:26:49 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_invalid(t_chr **mychr, t_format *format, va_list ap)
{
	int		i;

	flag_star(format, ap);
	i = -1;
	if (!format->width)
	{
		(*mychr)->str = ft_strnew(1);
		(*mychr)->str[0] = format->convers;
		(*mychr)->len = 1;
	}
	else
	{
		(*mychr)->str = ft_strnew(format->width);
		while (++i < format->width - 1)
			(*mychr)->str[i] = ' ';
		(*mychr)->str[i] = format->convers;
		(*mychr)->len = format->width;
	}
}

static int	conv_bold_color(t_lst *lst, t_chr **mychr)
{
	if (!ft_strcmp(lst->format->flag, "RED"))
		(*mychr)->str = ft_strdup(B_RED);
	else if (!ft_strcmp(lst->format->flag, "GREEN"))
		(*mychr)->str = ft_strdup(B_GREEN);
	else if (!ft_strcmp(lst->format->flag, "YELLOW"))
		(*mychr)->str = ft_strdup(B_YELLOW);
	else if (!ft_strcmp(lst->format->flag, "BLUE"))
		(*mychr)->str = ft_strdup(B_BLUE);
	else if (!ft_strcmp(lst->format->flag, "PURPLE"))
		(*mychr)->str = ft_strdup(B_PURPLE);
	else if (!ft_strcmp(lst->format->flag, "CYAN"))
		(*mychr)->str = ft_strdup(B_CYAN);
	else
		return (0);
	return (1);
}

void		conv_color(t_lst *lst, t_chr **mychr)
{
	(*mychr)->len = 0;
	if (conv_bold_color(lst, mychr))
		return ;
	if (!ft_strcmp(lst->format->flag, "red"))
		(*mychr)->str = ft_strdup(RED);
	else if (!ft_strcmp(lst->format->flag, "green"))
		(*mychr)->str = ft_strdup(GREEN);
	else if (!ft_strcmp(lst->format->flag, "yellow"))
		(*mychr)->str = ft_strdup(YELLOW);
	else if (!ft_strcmp(lst->format->flag, "blue"))
		(*mychr)->str = ft_strdup(BLUE);
	else if (!ft_strcmp(lst->format->flag, "purple"))
		(*mychr)->str = ft_strdup(PURPLE);
	else if (!ft_strcmp(lst->format->flag, "cyan"))
		(*mychr)->str = ft_strdup(CYAN);
	else if (!ft_strcmp(lst->format->flag, "eoc"))
		(*mychr)->str = ft_strdup(EOC);
	else
	{
		(*mychr)->str = ft_strdup(lst->format->flag);
		(*mychr)->len = ft_strlen((*mychr)->str);
	}
}

void		conv_percent(t_chr **mychr, t_lst *lst, va_list ap)
{
	char	*str;
	int		len;
	int		i;
	char	c;

	flag_star(lst->format, ap);
	len = ft_max(1, lst->format->width);
	str = ft_strnew(len);
	c = (ft_strchr(lst->format->flag, '0')) ? '0' : ' ';
	if (ft_strchr(lst->format->flag, '-'))
	{
		str[0] = '%';
		i = 0;
		while (++i < len)
			str[i] = ' ';
	}
	else
	{
		i = -1;
		while (++i < len - 1)
			str[i] = c;
		str[len - 1] = '%';
	}
	(*mychr)->str = str;
	(*mychr)->len = len;
}
