/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:40:31 by obelouch          #+#    #+#             */
/*   Updated: 2018/10/10 04:49:24 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				res;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	res = 0;
	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	while (i < n && (ps1[i] != '\0' || ps2[i] != '\0'))
	{
		if (ps1[i] != ps2[i])
		{
			res = (ps1[i] - ps2[i]);
			break ;
		}
		i++;
	}
	return (res);
}
