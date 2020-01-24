/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_o_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:44:53 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 17:46:29 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*o_nbr(t_format *fmt, char *num, int len_num, int *len_nbr)
{
	char		*nbr;
	int			dash;
	int			i;
	int			j;

	dash = (ft_strchr(fmt->flag, '#')) ? 1 : 0;
	*len_nbr = ft_max(len_num + dash, fmt->precis);
	nbr = (char*)malloc(sizeof(char) * (*len_nbr + 1));
	nbr[*len_nbr] = '\0';
	i = *len_nbr;
	j = len_num;
	while (--j >= 0)
		nbr[--i] = num[j];
	while (--i >= 0)
		nbr[i] = '0';
	return (nbr);
}

static char		*o_nres(t_format *fmt, char *nbr, int len_nbr, char c)
{
	char		*res;
	int			i;
	int			j;

	res = (char*)malloc(sizeof(char) * (fmt->width + 1));
	res[fmt->width] = '\0';
	if (!ft_strchr(fmt->flag, '-'))
	{
		i = -1;
		while (++i < fmt->width - len_nbr)
			res[i] = c;
		j = -1;
		while (++j < len_nbr)
			res[i++] = nbr[j];
	}
	else
	{
		i = -1;
		while (++i < len_nbr)
			res[i] = nbr[i];
		while (i < fmt->width)
			res[i++] = ' ';
	}
	return (res);
}

char			*o_n(t_format *fmt, char *num, int len_num)
{
	char		*res;
	char		*nbr;
	int			len_nbr;
	char		c;

	nbr = o_nbr(fmt, num, len_num, &len_nbr);
	if (fmt->width - len_nbr > 0)
	{
		c = (fmt->precis == -1 && ft_strchr(fmt->flag, '0')
				&& !ft_strchr(fmt->flag, '-')) ? '0' : ' ';
		res = o_nres(fmt, nbr, len_nbr, c);
		free(nbr);
		return (res);
	}
	return (nbr);
}
