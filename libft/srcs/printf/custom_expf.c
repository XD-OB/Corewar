/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_expf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 09:35:51 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 12:33:16 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		nanf_annex(char **res, char *s, long *len, int wid)
{
	long		i;
	long		j;

	i = wid;
	j = *len;
	while (j > 0)
		(*res)[--i] = s[--j];
	while (i > 0)
		(*res)[--i] = ' ';
	*len = wid;
}

void			custom_nanf(t_format *fmt, char **str, long *len)
{
	long		i;
	long		j;
	char		*res;

	res = (char*)malloc(sizeof(char) * (fmt->width + 1));
	res[fmt->width] = '\0';
	if (ft_strchr(fmt->flag, '-'))
	{
		i = 0;
		j = 0;
		while (j < *len)
			res[i++] = (*str)[j++];
		*len = fmt->width;
		while (i < *len)
			res[i++] = ' ';
	}
	else
		nanf_annex(&res, *str, len, fmt->width);
	free(*str);
	*str = res;
}

static char		*inff_minus(t_format *fmt, char *str, long *len, int sign)
{
	long		i;
	long		j;
	char		*res;

	res = (char*)malloc(sizeof(char) * (fmt->width + 1));
	res[fmt->width] = '\0';
	i = 0;
	j = 0;
	if (sign)
		res[i++] = '-';
	else if (ft_strchr(fmt->flag, '+'))
		res[i++] = '+';
	else if (ft_strchr(fmt->flag, ' '))
		res[i++] = ' ';
	while (j < *len)
		res[i++] = str[j++];
	*len = fmt->width;
	while (i < *len)
		res[i++] = ' ';
	return (res);
}

/*
**	var:	0:i			1:j
*/

void			custom_inff(t_format *fmt, char **str, long *len, int sign)
{
	long		var[2];
	char		*res;

	if (ft_strchr(fmt->flag, '-'))
		res = inff_minus(fmt, *str, len, sign);
	else
	{
		res = (char*)malloc(sizeof(char) * (fmt->width + 1));
		res[fmt->width] = '\0';
		var[0] = fmt->width;
		var[1] = *len;
		while (var[1] > 0)
			res[--(var[0])] = (*str)[--(var[1])];
		if (sign)
			res[--(var[0])] = '-';
		else if (ft_strchr(fmt->flag, '+'))
			res[--(var[0])] = '+';
		else if (ft_strchr(fmt->flag, ' '))
			res[--(var[0])] = ' ';
		while (var[0] > 0)
			res[--(var[0])] = ' ';
		*len = fmt->width;
	}
	free(*str);
	*str = res;
}
