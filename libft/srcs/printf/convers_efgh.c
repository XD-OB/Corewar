/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_efgh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:57:10 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 16:22:09 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		gclean(t_format *fmt, t_chr **chr)
{
	char		*clean;
	int			size;
	int			i;

	if (!ft_strchr(fmt->flag, '#'))
	{
		size = (*chr)->len - 1;
		while (size >= 0 && ((*chr)->str)[size] == '0')
			size--;
		if (((*chr)->str)[size] == '.')
			size--;
		if (size != (int)((*chr)->len))
		{
			clean = (char*)malloc(sizeof(char) * size + 2);
			clean[size + 1] = '\0';
			i = -1;
			while (++i <= size)
				clean[i] = ((*chr)->str)[i];
			free((*chr)->str);
			(*chr)->str = clean;
			(*chr)->len = size + 1;
		}
	}
}

static void		efgh_annex(t_chr **chr, t_lst *lst)
{
	size_t		a;

	a = (ft_strpbrk(lst->format->flag, "+ ")) ? 2 : 1;
	if (ft_strlen((*chr)->str) > 1 + a)
		gclean(lst->format, chr);
}

/*
**	v[2]:		0: exp		1: is_long
*/

void			conv_d_efgh(t_lst *lst, t_chr **chr, va_list ap)
{
	t_double	db;
	int			v[2];

	v[1] = (ft_strchr(lst->format->flag, 'L') ? 1 : 0);
	flag_star(lst->format, ap);
	db.d = (flag_dollar(lst)) ?
			va_arg(*(lst->arglist), double) : va_arg(ap, double);
	(lst->format->precis == -1) ? lst->format->precis = 6 : 0;
	if (ft_strchr("fH", lst->format->convers))
		(v[1]) ? conv_llf(lst, chr, ap, 0) : conv_lfh(lst, chr, db, 0);
	else if (ft_strchr("eE", lst->format->convers))
		(v[1]) ? conv_lee(lst, chr, ap, 0) : conv_ee(lst, chr, db, 0);
	else
	{
		(ft_strchr(lst->format->flag, '#')) ? lst->format->precis = 6 : 0;
		v[0] = int_exp(db.zone.mantissa, (v[1]) ? LD_BIAS : D_BIAS);
		if (v[0] < -4 || v[0] >= (int)(lst->format->precis))
		{
			(lst->format->convers == 'G') ? lst->format->convers = 'E' : 0;
			(v[1]) ? conv_lee(lst, chr, ap, 1) : conv_ee(lst, chr, db, 1);
		}
		else
			(v[1]) ? conv_llf(lst, chr, ap, 1) : conv_lfh(lst, chr, db, 1);
		efgh_annex(chr, lst);
	}
}
