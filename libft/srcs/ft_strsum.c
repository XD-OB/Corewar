/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 06:42:27 by ishaimou          #+#    #+#             */
/*   Updated: 2019/04/17 06:43:36 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 	tab "a" indexes
**	len1 => 0; len2 => 1; i => 2; sum => 3; carry => 4
*/

static int	c_val(char c)
{
	if (c > 64 && c < 91)
		return (c + 10 - 'A');
	return (c - '0');
}

static char	c_char(int val)
{
	if (val >= 10)
		return (val - 10 + 'A');
	return (val + '0');
}

char		*ft_strsum(char *s1, char *s2, int base)
{
	char	*str;
	int		a[5];

	(ft_strlen(s1) > ft_strlen(s2)) ? ft_strswap(&s1, &s2) : 0;
	a[0] = ft_strlen(s1);
	a[1] = ft_strlen(s2);
	str = ft_strnew(0);
	a[4] = 0;
	a[2] = a[0];
	while (a[2]-- > 0)
	{
		a[3] = (c_val(s1[a[2]]) + c_val(s2[a[2] + a[1] - a[0]]) + a[4]);
		str = ft_str_pushback(str, c_char(a[3] % base));
		a[4] = a[3] / base;
	}
	a[2] = a[1] - a[0];
	while (a[2]-- > 0)
	{
		a[3] = (c_val(s2[a[2]]) + a[4]);
		str = ft_str_pushback(str, c_char(a[3] % base));
		a[4] = a[3] / base;
	}
	(a[4]) ? str = ft_str_pushback(str, c_char(a[4])) : 0;
	str = ft_strrev(str);
	return (str);
}
