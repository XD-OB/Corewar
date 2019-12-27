/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:48:46 by obelouch          #+#    #+#             */
/*   Updated: 2018/10/10 04:42:27 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pt;

	pt = (char*)s;
	while (*pt)
	{
		if (*pt == (char)c)
			return (pt);
		pt++;
	}
	if (c == 0 && *pt == '\0')
		return (pt);
	return (NULL);
}
