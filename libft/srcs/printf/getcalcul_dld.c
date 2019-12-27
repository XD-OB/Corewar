/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcalcul_dld.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 01:02:57 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 18:28:43 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*calcul_entier(char *tab, int size, t_format *format)
{
	char		*entier;
	char		*count;
	int			debut;
	int			base;
	int			i;

	base = (format->convers == 'H') ? 16 : 10;
	entier = ft_strdup("0");
	debut = 0;
	while (tab[debut] == '0')
		debut++;
	i = size - 1;
	while (i >= debut && tab[i] == '0')
		i--;
	count = ft_strpower(2, (size - i - 1), base);
	while (i >= debut)
	{
		if (tab[i] == '1')
			sumstr(&entier, count, base);
		multstr(&count, "2", base);
		i--;
	}
	free(count);
	return (entier);
}

static int		ft_strupdatelen(char *str, int old)
{
	int			len;

	len = old;
	while (str[len])
		len++;
	return (len);
}

/*
**	var[2]: 	0: base	   1: len
*/

static void		init_fractcalc(int *var, int *size, int *i, char convers)
{
	*i = 0;
	var[1] = 1;
	if (convers == 'H')
		var[0] = 16;
	else
		var[0] = 10;
	(*size)--;
}

char			*calcul_fract(char *tab, int size, t_format *fmt)
{
	char		*fract;
	char		*count;
	int			var[2];
	int			i;

	init_fractcalc(var, &size, &i, fmt->convers);
	while (tab[size] == '0')
		size--;
	while (i <= size && tab[i] == '0')
		i++;
	count = ft_strpower(5, i + 1, var[0]);
	fract = ft_strcnew(i + 1, '0');
	while (i <= size)
	{
		if (tab[i] == '1')
		{
			sumstr(&fract, count, var[0]);
			var[1] = ft_strupdatelen(fract, var[1]);
		}
		multstr(&count, "5", var[0]);
		foisdix(&fract, &(var[1]));
		i++;
	}
	free(count);
	return (fract);
}
