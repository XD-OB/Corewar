/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 23:31:27 by obelouch          #+#    #+#             */
/*   Updated: 2018/10/10 04:32:55 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	while (n > 0)
	{
		if (*psrc == (unsigned char)c)
		{
			*pdst = (unsigned char)c;
			pdst++;
			return (pdst);
		}
		*pdst = *psrc;
		pdst++;
		psrc++;
		n--;
	}
	return (NULL);
}
