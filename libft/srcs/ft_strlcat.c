/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 01:51:11 by obelouch          #+#    #+#             */
/*   Updated: 2018/10/10 04:40:33 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	char	*psrc;

	len_dest = 0;
	len_src = 0;
	psrc = (char*)src;
	while (src[len_src] != '\0')
		len_src++;
	while ((*dest != '\0') && (size > 0))
	{
		dest++;
		len_dest++;
		size--;
	}
	while ((*psrc != '\0') && (size > 1))
	{
		*dest = *psrc;
		dest++;
		psrc++;
		size--;
	}
	if (*psrc == 0 || size == 1)
		*dest = '\0';
	return (len_dest + len_src);
}
