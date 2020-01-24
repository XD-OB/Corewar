/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 04:00:09 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/17 01:23:31 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_is_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static	char	*ft_return(int start, int end, const char *s)
{
	char	*trim;
	int		i;

	if (end < start)
	{
		trim = (char*)malloc(sizeof(*trim));
		trim[0] = '\0';
		return (trim);
	}
	if (!(trim = (char*)malloc(sizeof(*trim) * (end - start + 2))))
		return (NULL);
	i = start;
	while (i <= end)
	{
		trim[i - start] = s[i];
		i++;
	}
	trim[i - start] = '\0';
	return (trim);
}

char			*ft_strtrim(char const *s)
{
	int		end;
	int		start;

	if (s != NULL)
	{
		start = 0;
		while (ft_is_blank(s[start]) && s[start] != '\0')
			start++;
		end = start;
		while (s[end] != '\0')
			end++;
		end--;
		while (ft_is_blank(s[end]))
			end--;
		return (ft_return(start, end, s));
	}
	return (NULL);
}
