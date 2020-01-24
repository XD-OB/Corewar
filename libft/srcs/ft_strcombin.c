/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcombin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 03:43:24 by obelouch          #+#    #+#             */
/*   Updated: 2018/10/08 22:44:30 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcombin(char **s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_s1;
	unsigned int	len_s2;
	char			*join;

	if (*s1 && s2)
	{
		len_s1 = ft_strlen(*s1);
		len_s2 = ft_strlen(s2);
		join = (char*)malloc(sizeof(*join) * (len_s1 + len_s2 + 1));
		if (join == NULL)
			return ;
		i = 0;
		j = 0;
		while (i < len_s1)
			join[j++] = (*s1)[i++];
		i = 0;
		while (i < len_s2)
			join[j++] = s2[i++];
		join[j] = '\0';
		free(*s1);
		*s1 = join;
	}
}
