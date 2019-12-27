/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:57:16 by obelouch          #+#    #+#             */
/*   Updated: 2018/10/10 07:22:12 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	char	*pt;

	pt = (char*)str;
	if (c == '\0')
	{
		while (*pt != '\0')
			pt++;
		return (pt);
	}
	while (*str != '\0')
	{
		if (*str == (const char)c)
			pt = (char*)str;
		str++;
	}
	if (*pt == (char)c)
		return (pt);
	return (0);
}
