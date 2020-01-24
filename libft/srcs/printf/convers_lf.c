/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_ld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 03:59:42 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/18 07:52:54 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			fill_tabld(char **tab, unsigned int *size,
							long *new_exp, long exp)
{
	if (*new_exp < -1)
	{
		int_add(tab, size, 0);
		(*new_exp)++;
		return (0);
	}
	if (*new_exp == -1)
	{
		(exp) ? int_add(tab, size, 1) : int_add(tab, size, 0);
		(*new_exp)++;
		return (0);
	}
	return (1);
}

/*
**	v[2]:		0: new_exp		1: bin_mantis
*/

char				*get_fractld(long exp, t_ldouble db, t_format *format)
{
	int				len_b;
	unsigned int	size;
	char			*tab;
	char			*res;
	long			v[2];

	tab = NULL;
	size = 0;
	v[0] = (exp == 0) ? 1 - LD_BIAS : exp - LD_BIAS;
	v[1] = db.zone.mantissa;
	len_b = ABS(63 - v[0] - 1);
	if (len_b < 0)
		return (ft_strdup("0"));
	while (len_b >= 0)
	{
		if (fill_tabld(&tab, &size, &v[0], exp))
			((v[1] >> len_b) & 1) ? int_add(&tab, &size, 1) :
									int_add(&tab, &size, 0);
		len_b--;
	}
	res = calcul_fract(tab, size, format);
	free(tab);
	return (res);
}

/*
**	v[2]:		0: len			1: carry
*/

static void			double_free(char **s1, char **s2)
{
	free(*s1);
	free(*s2);
}

void				conv_llf(t_lst *lst, t_chr **chr, va_list ap, int is_g)
{
	t_ldouble		db;
	long			v[2];
	char			*fract;
	char			*entier;

	v[1] = 0;
	flag_star(lst->format, ap);
	db.ld = (flag_dollar(lst)) ?
		va_arg(*(lst->arglist), long double) : va_arg(ap, long double);
	(lst->format->precis == -1) ? lst->format->precis = 6 : 0;
	if (pre_ld_calc(db, chr, lst, is_g))
		return ;
	entier = get_entierld(int_exp(db.zone.exponent, LD_BIAS), db, lst->format);
	flag_apostrophe(&entier, lst->format);
	fract = get_fractld(int_exp(db.zone.exponent, LD_BIAS), db, lst->format);
	(is_g) ? lst->format->precis = ft_max(0,
			(lst->format->precis - (long)ft_strlen(entier))) : 0;
	fprecis(&fract, lst->format->precis, &v[1], 10);
	(v[1] == 1) ? sumstr(&entier, "1", 10) : 0;
	(*chr)->str = ft_pointjoin(lst->format, entier, fract, &v[0]);
	(lst->format->width > v[0]) ?
		customize_f(lst->format, &((*chr)->str), &v[0], db.zone.sign) :
		add_sign_f(lst->format, &((*chr)->str), &v[0], db.zone.sign);
	double_free(&entier, &fract);
	(*chr)->len = v[0];
}
