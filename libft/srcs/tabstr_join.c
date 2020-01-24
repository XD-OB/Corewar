/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabstr_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:58:22 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/15 00:00:34 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*tabstr_join(char **tab, char *sep)
{
	char	*res;
	int		len;
	int		i;

	res = ft_strnew(0);
	len = tabstr_len(tab);
	i = 0;
	while (i < len)
	{
		ft_strcombin(&res, tab[i]);
		i++;
		if (i < len)
			ft_strcombin(&res, sep);
	}
	return (res);
}
