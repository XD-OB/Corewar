/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 05:43:30 by obelouch          #+#    #+#             */
/*   Updated: 2019/06/28 05:54:06 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long		hash_str(char *str)
{
	unsigned long	hash;
	unsigned long	power;
	int				i;

	i = 0;
	hash = 0;
	power = 1;
	while (str[i])
	{
		hash += (str[i] - 31) * power;
		power *= HASH_C;
		i++;
	}
	return (hash);
}
