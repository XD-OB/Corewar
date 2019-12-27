/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_filltab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 05:42:48 by obelouch          #+#    #+#             */
/*   Updated: 2019/06/29 04:38:21 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			hash_filltab(char **hash_tab, int size, char *str)
{
	int		ind;
	int		i;

	ind = hash_str(str) % size;
	i = ind - 1;
	while (++i < size)
		if (!hash_tab[i])
		{
			hash_tab[i] = ft_strdup(str);
			return (i);
		}
	i = -1;
	while (++i < ind)
		if (!hash_tab[i])
		{
			hash_tab[i] = ft_strdup(str);
			return (i);
		}
	return (-1);
}
