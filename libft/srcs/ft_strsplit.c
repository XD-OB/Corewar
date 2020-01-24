/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 20:45:42 by obelouch          #+#    #+#             */
/*   Updated: 2018/10/12 01:53:45 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_not_c(char ch, char c)
{
	if (ch == c)
		return (0);
	return (1);
}

static	int		ft_count_w(const char *str, char c)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (ft_not_c(str[i], c) == 0)
		{
			if (j == 1)
				j = 0;
		}
		if (ft_not_c(str[i], c) == 1)
			if (j == 0)
			{
				n++;
				j = 1;
			}
		i++;
	}
	return (n);
}

static	int		ft_size_w(const char *str, int ind, char c)
{
	int		i;

	i = ind;
	while (ft_not_c(str[i], c) == 1 && str[i])
		i++;
	return (i - ind);
}

static	int		ft_position(const char *str, int *pt, char c)
{
	while (str[*pt])
	{
		if (ft_not_c(str[*pt], c) == 1)
			break ;
		(*pt)++;
	}
	return (0);
}

char			**ft_strsplit(char const *str, char c)
{
	int		t[3];
	int		pt[1];
	char	**table;

	if (str == NULL)
		return (NULL);
	t[0] = 0;
	*pt = 0;
	table = (char**)malloc((ft_count_w(str, c) + 1) * sizeof(char*));
	if (table)
	{
		while (t[0] < ft_count_w(str, c))
		{
			t[1] = 0;
			ft_position(str, pt, c);
			t[2] = ft_size_w(str, *pt, c);
			table[t[0]] = (char*)malloc((t[2] + 1) * sizeof(char));
			while (t[1] < t[2])
				table[t[0]][t[1]++] = str[(*pt)++];
			table[t[0]][t[1]] = '\0';
			t[0]++;
		}
		table[t[0]] = 0;
	}
	return (table);
}
