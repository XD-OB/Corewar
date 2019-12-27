/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 20:37:26 by obelouch          #+#    #+#             */
/*   Updated: 2018/10/10 04:55:14 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		size;
	char	*str;

	if (s && f)
	{
		size = 0;
		while (s[size])
			size++;
		str = (char*)malloc(sizeof(*str) * (size + 1));
		if (str)
		{
			i = 0;
			while (i < size)
			{
				str[i] = (*f)(s[i]);
				i++;
			}
			str[i] = '\0';
		}
		return (str);
	}
	return (NULL);
}
