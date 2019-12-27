/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 03:21:07 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 17:50:26 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*null_str(t_format *fmt, int *len_str)
{
	char		*str;

	if (fmt->precis == 0)
	{
		str = ft_strnew(0);
		*len_str = 0;
	}
	else
	{
		if (fmt->precis == -1 || fmt->precis > 6)
		{
			str = ft_strdup("(null)");
			*len_str = 6;
		}
		else
		{
			str = ft_strndup("(null)", fmt->precis);
			*len_str = fmt->precis;
		}
	}
	return (str);
}

static char		*s_str(t_format *fmt, char *str, int *len_str)
{
	char		*res;
	char		c;
	int			i;

	res = (char*)malloc(sizeof(char) * (fmt->width + 1));
	res[fmt->width] = '\0';
	if (!ft_strchr(fmt->flag, '-'))
	{
		c = (ft_strchr(fmt->flag, '0')) ? '0' : ' ';
		i = fmt->width;
		while (--(*len_str) >= 0)
			res[--i] = str[*len_str];
		while (--i >= 0)
			res[i] = c;
	}
	else
	{
		i = -1;
		while (++i < *len_str)
			res[i] = str[i];
		while (i < fmt->width)
			res[i++] = ' ';
	}
	*len_str = fmt->width;
	return (res);
}

static char		*mystr(t_format *fmt, char *s, int *len_str)
{
	char		*str;

	if (!s)
		str = null_str(fmt, len_str);
	else
	{
		*len_str = ft_strlen(s);
		if (fmt->precis < *len_str && fmt->precis != -1)
		{
			str = ft_strndup(s, fmt->precis);
			*len_str = fmt->precis;
		}
		else
			str = ft_strdup(s);
	}
	return (str);
}

void			conv_s(t_lst *lst, t_chr **chr, va_list ap)
{
	int			len_str;
	char		*str;
	char		*s;

	flag_star(lst->format, ap);
	if (flag_dollar(lst))
	{
		(*chr)->str = ft_dollar_cs(lst->format);
		(*chr)->len = ft_strlen((*chr)->str);
	}
	else
	{
		s = va_arg(ap, char*);
		str = mystr(lst->format, s, &len_str);
		if (lst->format->width > len_str)
		{
			(*chr)->str = s_str(lst->format, str, &len_str);
			free(str);
		}
		else
			(*chr)->str = str;
		(*chr)->len = len_str;
	}
}
