/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:15:28 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 06:38:20 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		sign_n(long long int n)
{
	if (n > 0)
		return (1);
	if (n < 0)
		return (-1);
	return (0);
}

static void		di_zero(t_chr **chr, t_format *fmt)
{
	char		*nbr;
	int			len_nbr;

	if (fmt->precis == -1)
		fmt->precis = 1;
	len_nbr = fmt->precis;
	if (ft_strpbrk(fmt->flag, "+ "))
		len_nbr++;
	nbr = ft_strcnew(len_nbr, '0');
	if (ft_strchr(fmt->flag, '+'))
		nbr[0] = '+';
	else if (ft_strchr(fmt->flag, ' '))
		nbr[0] = ' ';
	if (fmt->width > len_nbr)
	{
		(*chr)->str = width_di(fmt, nbr, len_nbr, 0);
		(*chr)->len = fmt->width;
		free(nbr);
	}
	else
	{
		(*chr)->str = nbr;
		(*chr)->len = len_nbr;
	}
}

/*
** len[2]       0: len_nbr		1: len_num
*/

static char		*di_nbr(t_format *fmt, char *num, int *len, int sign)
{
	char		*nbr;
	int			i;
	int			j;

	nbr = (char*)malloc(sizeof(char) * (len[0] + 1));
	nbr[len[0]] = '\0';
	i = len[0];
	j = len[1];
	while (--j >= 0)
		nbr[--i] = num[j];
	while (--i >= 0)
		nbr[i] = '0';
	if (sign == -1)
		nbr[0] = '-';
	else if (ft_strchr(fmt->flag, '+'))
		nbr[0] = '+';
	else if (ft_strchr(fmt->flag, ' '))
		nbr[0] = ' ';
	return (nbr);
}

static void		di_n(t_chr **chr, t_format *fmt, char *num, int sign)
{
	char		*nbr;
	int			len[2];

	len[1] = ft_strlen(num);
	len[0] = ft_max(fmt->precis, len[1]);
	if (sign == -1 || ft_strpbrk(fmt->flag, "+ "))
		len[0]++;
	nbr = di_nbr(fmt, num, len, sign);
	if (fmt->width > len[0])
	{
		(*chr)->str = width_di(fmt, nbr, len[0], sign);
		(*chr)->len = fmt->width;
		free(nbr);
	}
	else
	{
		(*chr)->str = nbr;
		(*chr)->len = len[0];
	}
}

void			conv_di(t_lst *lst, t_chr **chr, va_list ap)
{
	long long int	n;
	int				sign;
	char			*num;

	flag_star(lst->format, ap);
	n = (flag_dollar(lst)) ?
		cast_di(*(lst->arglist), lst->format->flag) :
		cast_di(ap, lst->format->flag);
	sign = sign_n(n);
	if (sign == 0)
		di_zero(chr, lst->format);
	else
	{
		num = ft_poslltoa(n);
		di_n(chr, lst->format, num, sign);
		free(num);
		num = NULL;
	}
}
