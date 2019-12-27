/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 00:49:23 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 19:00:44 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				foisdix(char **str, int *len)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(*len + 1);
	while (i < *len)
	{
		new[i] = (*str)[i];
		i++;
	}
	new[i] = '0';
	(*len)++;
	free(*str);
	*str = new;
}

void				int_add(char **tab, unsigned int *oldsize, int data)
{
	char			*new;
	unsigned int	i;

	i = 0;
	new = ft_strnew(*oldsize + 1);
	while (i < *oldsize)
	{
		new[i] = (*tab)[i];
		i++;
	}
	new[i] = data + '0';
	if (*oldsize != 0)
		free(*tab);
	(*oldsize)++;
	*tab = new;
}

char				*ft_pointjoin(t_format *fmt, char *s1, char *s2, long *len)
{
	long			len_s1;
	long			len_s2;
	char			*str;
	long			i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	*len = len_s1 + len_s2 + 1;
	if (len_s2 == 0 && !ft_strchr(fmt->flag, '#'))
		(*len)--;
	str = (char*)malloc(sizeof(char) * (*len + 1));
	str[*len] = '\0';
	i = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	if (i == *len)
		return (str);
	str[i] = '.';
	while (++i < *len)
		str[i] = s2[i - len_s1 - 1];
	return (str);
}

void				sumstr(char **s1, char *s2, int base)
{
	char			*tmp;

	tmp = *s1;
	*s1 = ft_strsum(*s1, s2, base);
	free(tmp);
	tmp = NULL;
}

void				multstr(char **s1, char *s2, int base)
{
	char			*tmp;

	tmp = *s1;
	*s1 = ft_strmult(*s1, s2, base);
	free(tmp);
	tmp = NULL;
}
