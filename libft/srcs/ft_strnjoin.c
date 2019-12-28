/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 23:03:56 by obelouch          #+#    #+#             */
/*   Updated: 2019/12/28 00:32:34 by vegeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char *s1, char *s2, size_t len)
{
	char	*str;
	size_t	n;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	n = ft_strlen(s1) + len + 1;
	str = ft_strnew(n);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	len++;
	while (s2[j] != '\0' && --len > 0)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
