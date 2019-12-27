/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ilyass.sh@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:17:20 by ishaimou          #+#    #+#             */
/*   Updated: 2018/12/17 16:58:51 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_val(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int				ft_atoibase(char *str, char *base_from)
{
	int i;
	int nb;
	int power;
	int	base_len;

	nb = 0;
	power = 1;
	base_len = ft_strlen(base_from);
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (ft_get_val(str[i], base_from) < 0)
			return (0);
		nb += ft_get_val(str[i], base_from) * power;
		power *= base_len;
		i--;
	}
	return (nb);
}
