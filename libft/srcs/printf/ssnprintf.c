/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssnprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 09:06:58 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/18 09:12:11 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int		get_chr_len(t_chr *mychr)
{
	unsigned int		len;

	len = 0;
	while (mychr)
	{
		len += mychr->len;
		mychr = mychr->next;
	}
	return (len);
}

static char				*str_chr(t_chr *mychr, unsigned int len_str)
{
	char				*str;
	unsigned int		i;
	unsigned int		j;

	str = (char*)malloc(sizeof(char) * len_str + 1);
	str[len_str] = '\0';
	i = 0;
	while (mychr && i < len_str)
	{
		j = 0;
		while (j < mychr->len && i < len_str)
		{
			str[i] = (mychr->str)[j];
			j++;
			i++;
		}
		mychr = mychr->next;
	}
	return (str);
}

/*
*** len:	0: len		1: len_format		2: pflag
*/

static int				sprintf_null(char *format, int *len, long n)
{
	int					l;

	l = 0;
	if (len[2] == -1)
		return (0);
	if (n == INT_MIN)
	{
		l = put_spstr((char*)format);
		if (format[len[1] - 1] == '%')
			return (-1);
		return (l);
	}
	else
	{
		if (len[2] == -1)
			return (0);
		l = put_spstrn((char*)format, (size_t)n);
		if (format[len[1] - 1] == '%')
			return (-1);
		return (l);
	}
}

int						ft_sprintf(char **str, const char *format, ...)
{
	t_chr				*mychr;
	t_lst				*lst;
	va_list				ap;
	int					len[3];

	len[1] = 0;
	len[2] = 0;
	while (format[len[1]])
		(len[1])++;
	va_start(ap, format);
	lst = parse_format(ap, (char*)format, &(len[2]));
	if (!lst)
		return (sprintf_null((char*)format, len, INT_MIN));
	if (!(mychr = load_chr((char*)format, lst)))
		return (-1);
	fill_chr(lst, mychr, ap);
	len[0] = get_chr_len(mychr);
	*str = str_chr(mychr, len[0]);
	free_lst(&lst);
	free_chr(&mychr);
	va_end(ap);
	return (len[0]);
}

int						ft_snprintf(char **str, size_t n,
								const char *format, ...)
{
	t_chr				*mychr;
	t_lst				*lst;
	va_list				ap;
	int					len[3];

	len[1] = 0;
	len[2] = 0;
	while (format[len[1]])
		(len[1])++;
	va_start(ap, format);
	lst = parse_format(ap, (char*)format, &(len[2]));
	if (!lst)
		return (sprintf_null((char*)format, len, n));
	if (!(mychr = load_chr((char*)format, lst)))
		return (-1);
	fill_chr(lst, mychr, ap);
	len[0] = get_chr_len(mychr);
	if (len[0] > (int)n)
		len[0] = n;
	*str = str_chr(mychr, n);
	free_lst(&lst);
	free_chr(&mychr);
	va_end(ap);
	return (len[0]);
}
