/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabstr_njoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:58:22 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/15 00:00:34 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*tabstr_njoin(char **tab, int start, int end, char *sep)
{
	char	*res;
	int		len;
	int		n;
	int		i;

	res = ft_strnew(0);
	len = tabstr_len(tab);
	ft_printf("len = %d\n", len);
	if (start < 0 || start >= len)
		return (res);
	n = (end < start) ? len - 1 : ft_min(len - 1, end);
	i = start;
	while (i < n)
	{
		ft_strcombin(&res, tab[i++]);
		ft_strcombin(&res, sep);
	}
	ft_strcombin(&res, tab[i]);
	return (res);
}
