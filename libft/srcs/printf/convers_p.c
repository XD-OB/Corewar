/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:12:58 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/12 04:10:52 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*p_nbr(t_format *fmt, char *num, int len_num, int *len_nbr)
{
	char		*nbr;
	int			i;
	int			j;

	*len_nbr = ft_max(len_num, fmt->precis) + 2;
	nbr = (char*)malloc(sizeof(char) * (*len_nbr + 1));
	nbr[*len_nbr] = '\0';
	i = *len_nbr;
	j = len_num;
	while (--j >= 0)
		nbr[--i] = num[j];
	while (--i >= 0)
		nbr[i] = '0';
	nbr[1] = 'X';
	return (nbr);
}

static void		p_res_minus(char **res, t_format *fmt, char *nbr, int len_nbr)
{
	char		c;
	int			i;
	int			j;

	c = (ft_strchr(fmt->flag, '0')) ? '0' : ' ';
	i = fmt->width;
	j = len_nbr;
	while (--j >= 0)
		(*res)[--i] = nbr[j];
	while (--i >= 0)
		(*res)[i] = c;
	if (c == '0')
	{
		(*res)[1] = 'X';
		(*res)[fmt->width - len_nbr + 1] = '0';
	}
}

static char		*p_n(t_format *fmt, char *num, int len_num)
{
	char		*nbr;
	char		*res;
	int			len_nbr;
	int			i;

	nbr = p_nbr(fmt, num, len_num, &len_nbr);
	if (fmt->width > len_nbr)
	{
		res = (char*)malloc(sizeof(char) * (fmt->width + 1));
		res[fmt->width] = '\0';
		if (!ft_strchr(fmt->flag, '-'))
			p_res_minus(&res, fmt, nbr, len_nbr);
		else
		{
			i = -1;
			while (++i < len_nbr)
				res[i] = nbr[i];
			while (i < fmt->width)
				res[i++] = ' ';
		}
		free(nbr);
		return (res);
	}
	return (nbr);
}

void			conv_p(t_lst *lst, t_chr **chr, va_list ap)
{
	uintptr_t	n;
	char		*num;
	char		*res;

	flag_star(lst->format, ap);
	n = (flag_dollar(lst)) ? va_arg(*(lst->arglist), uintptr_t)
							: va_arg(ap, uintptr_t);
	num = ft_ulltoa_base(n, 16);
	res = p_n(lst->format, num, (int)ft_strlen(num));
	if (lst->format->convers == 'p')
		ft_strlowcase(res);
	free(num);
	(*chr)->str = res;
	(*chr)->len = (int)ft_strlen(res);
}
