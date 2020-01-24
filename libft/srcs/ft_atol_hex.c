/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 04:51:00 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/21 22:48:48 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_val(char c)
{
	char		*base_maj;
	char		*base_min;
	int			i;

	i = 0;
	base_maj = "0123456789ABCDEF";
	base_min = "0123456789abcdef";
	while (i < 16)
	{
		if (c == base_maj[i])
			return (i);
		if (c == base_min[i])
			return (i);
		i++;
	}
	return (-1);
}

long			ft_atol_hex(char *str)
{
	char		*s;
	long		nb;
	int			power;
	int			val;
	int			i;

	nb = 0;
	power = 1;
	if (str[0] == '0' && str[1] == 'x')
		s = &str[2];
	else
		s = str;
	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		val = ft_get_val(s[i]);
		if (val < 0)
			return (0);
		nb += val * power;
		power *= 16;
		i--;
	}
	return (nb);
}
