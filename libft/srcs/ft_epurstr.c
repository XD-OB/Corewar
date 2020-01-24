/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epurstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 08:46:48 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/19 09:54:42 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_blank(char c)
{
	return (c == 32 || c == 9);
}

static int	epur_len(char *str)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (!is_blank(str[i]))
		{
			while (str[i] && !is_blank(str[i]))
			{
				len++;
				i++;
			}
			if (str)
				len++;
		}
		i++;
	}
	return (len);
}

void		ft_epurstr(char **str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_trimstr(str);
	new = ft_strnew(epur_len(*str));
	while ((*str)[i])
	{
		if (!is_blank((*str)[i]))
		{
			while ((*str)[i] && !is_blank((*str)[i]))
				new[j++] = (*str)[i++];
			if (*str)
				new[j++] = ' ';
		}
		i++;
	}
	ft_trimstr(&new);
	free(*str);
	*str = new;
}
