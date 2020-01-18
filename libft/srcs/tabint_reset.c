/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabint_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:16:17 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:16:24 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		tabint_reset(int *tab, int size, int n)
{
	int		i;

	i = 0;
	while (i < size)
	{
		tab[i] = n;
		i++;
	}
}
