/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 06:15:30 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/25 23:35:55 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	int		ft_not_c(char ch, char *prev_ch)
{
	if (ch == LABEL_CHAR && (prev_ch == NULL ||
		(!ft_isblank(*prev_ch) && *prev_ch != DIRECT_CHAR &&
		 *prev_ch != SEPARATOR_CHAR && *prev_ch != LABEL_CHAR)))
		return (0);
	return (1);
}

static	int		ft_count_w(char *str)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (ft_not_c(str[i], (i == 0) ? NULL : &str[i - 1]) == 0)
		{
			if (j == 1)
				j = 0;
		}
		if (ft_not_c(str[i], (i == 0) ? NULL : &str[i - 1]) == 1)
			if (j == 0)
			{
				n++;
				j = 1;
			}
		i++;
	}
	return (n);
}

static	int		ft_size_w(char *str, int ind)
{
	int		i;

	i = ind;
	while (str[i] && ft_not_c(str[i], (i == 0) ? NULL : &str[i - 1]) == 1)
		i++;
	return (i - ind);
}

static	int		ft_position(char *str, int *pt)
{
	while (str[*pt])
	{
		if (ft_not_c(str[*pt], (*pt == 0) ? NULL : &str[*pt - 1]) == 1)
			break ;
		(*pt)++;
	}
	return (0);
}

char			**split_labels(char *str)
{
	int		t[3];
	int		pt[1];
	char	**table;

	if (str == NULL)
		return (NULL);
	t[0] = 0;
	*pt = 0;
	table = (char**)malloc((ft_count_w(str) + 1) * sizeof(char*));
	if (table)
	{
		while (t[0] < ft_count_w(str))
		{
			t[1] = 0;
			ft_position(str, pt);
			t[2] = ft_size_w(str, *pt);
			table[t[0]] = (char*)malloc((t[2] + 1) * sizeof(char));
			while (t[1] < t[2])
				table[t[0]][t[1]++] = str[(*pt)++];
			table[t[0]++][t[1]] = '\0';
		}
		table[t[0]] = 0;
	}
	tabstr_trim(table);
	return (table);
}
