/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 00:38:44 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 16:59:15 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*custom_fannex2(t_format *fmt, char *str, long *len, int sign)
{
	long	i;
	long	j;
	char	*res;

	j = *len;
	i = fmt->width;
	res = (char*)malloc(sizeof(char) * (fmt->width + 1));
	res[fmt->width] = '\0';
	while (j > 0)
		res[--i] = str[--j];
	while (i > 0)
		res[--i] = '0';
	if (sign)
		res[0] = '-';
	else if (ft_strchr(fmt->flag, '+'))
		res[0] = '+';
	else if (ft_strchr(fmt->flag, ' '))
		res[0] = ' ';
	return (res);
}

static char	*custom_fannex(t_format *fmt, char *str, long *len, int sign)
{
	long	i;
	long	j;
	char	*res;

	if (ft_strchr(fmt->flag, '0'))
		res = custom_fannex2(fmt, str, len, sign);
	else
	{
		j = *len;
		i = fmt->width;
		res = (char*)malloc(sizeof(char) * (fmt->width + 1));
		res[fmt->width] = '\0';
		while (j > 0)
			res[--i] = str[--j];
		if (sign)
			res[--i] = '-';
		else if (ft_strchr(fmt->flag, '+'))
			res[--i] = '+';
		else if (ft_strchr(fmt->flag, ' '))
			res[--i] = ' ';
		while (i > 0)
			res[--i] = ' ';
	}
	*len = fmt->width;
	return (res);
}

/*
**	v[2]:		0: i		1: j
*/

void		customize_f(t_format *fmt, char **str, long *len, int sign)
{
	char	*res;
	long	v[2];

	if (ft_strchr(fmt->flag, '-'))
	{
		v[0] = 0;
		v[1] = 0;
		res = (char*)malloc(sizeof(char) * (fmt->width + 1));
		res[fmt->width] = '\0';
		if (sign)
			res[v[0]++] = '-';
		else if (ft_strchr(fmt->flag, '+'))
			res[v[0]++] = '+';
		else if (ft_strchr(fmt->flag, ' '))
			res[v[0]++] = ' ';
		while (v[1] < *len)
			res[v[0]++] = (*str)[v[1]++];
		*len = fmt->width;
		while (v[0] < *len)
			res[v[0]++] = ' ';
	}
	else
		res = custom_fannex(fmt, *str, len, sign);
	free(*str);
	*str = res;
}

/*
**	v[3]:		0: len		1: carry	2: base
*/

void		conv_lfh(t_lst *lst, t_chr **chr, t_double db, int is_g)
{
	long	v[3];
	char	*fract;
	char	*entier;

	v[1] = 0;
	v[2] = (lst->format->convers == 'H') ? 16 : 10;
	if (pre_d_calc(db, chr, lst, is_g))
		return ;
	entier = get_entier(int_exp(db.zone.exponent, D_BIAS),
			db.zone.mantissa, D_BIAS, lst->format);
	(v[2] == 16) ? flag_dash(&entier, 16) : 0;
	flag_apostrophe(&entier, lst->format);
	fract = get_fract(int_exp(db.zone.exponent, D_BIAS),
			db.zone.mantissa, D_BIAS, lst->format);
	(is_g) ? lst->format->precis =
		ft_max((lst->format->precis - ft_strlen(entier)), 1) : 0;
	fprecis(&fract, lst->format->precis, &v[1], v[2]);
	(v[1] == 1) ? sumstr(&entier, "1", v[2]) : 0;
	(*chr)->str = ft_pointjoin(lst->format, entier, fract, &v[0]);
	(lst->format->width > v[0]) ?
		customize_f(lst->format, &((*chr)->str), &v[0], db.zone.sign) :
		add_sign_f(lst->format, &((*chr)->str), &v[0], db.zone.sign);
	free(entier);
	free(fract);
	(*chr)->len = v[0];
}
