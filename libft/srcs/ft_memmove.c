/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 02:01:26 by obelouch          #+#    #+#             */
/*   Updated: 2018/10/12 01:04:09 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*pt;

	pt = ft_memalloc(len);
	if (pt == NULL)
		return (dst);
	ft_memcpy(pt, src, len);
	ft_memcpy(dst, pt, len);
	free(pt);
	return (dst);
}
