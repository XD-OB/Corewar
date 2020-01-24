/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_xb_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:54:35 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 17:54:57 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*xx_zero_res(t_format *fmt, char *nbr, int len_nbr, char c)
{
	char		*res;
	int			i;
	int			j;

	res = (char*)malloc(sizeof(char) * (fmt->width + 1));
	res[fmt->width] = '\0';
	if (!ft_strchr(fmt->flag, '-'))
	{
		i = fmt->width;
		j = len_nbr;
		while (--j >= 0)
			res[--i] = nbr[j];
		while (--i >= 0)
			res[i] = c;
	}
	else
	{
		i = 0;
		j = 0;
		while (j < len_nbr)
			res[i++] = nbr[j++];
		while (i < fmt->width)
			res[i++] = c;
	}
	return (res);
}

char			*xx_zero(t_format *fmt)
{
	int			len_nbr;
	char		*nbr;
	char		*res;
	char		c;

	len_nbr = fmt->precis;
	if (fmt->precis == -1)
		len_nbr = 1;
	nbr = ft_strcnew(len_nbr, '0');
	if (fmt->width > len_nbr)
	{
		c = (fmt->precis == -1 && ft_strchr(fmt->flag, '0')
				&& !ft_strchr(fmt->flag, '-')) ? '0' : ' ';
		res = xx_zero_res(fmt, nbr, len_nbr, c);
		free(nbr);
		return (res);
	}
	return (nbr);
}
