/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:36:45 by obelouch          #+#    #+#             */
/*   Updated: 2018/10/10 04:31:44 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*pt;

	if (len == 0)
		return (b);
	pt = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		*pt = (unsigned char)c;
		pt++;
		i++;
	}
	return (b);
}
