/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 06:15:30 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/27 06:17:42 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	int		ft_not_c(char ch, char *prev_ch)
{
	if (ch == LABEL_CHAR && !prev_ch)
		return (0);
	if (ch == LABEL_CHAR && (!ft_isblank(*prev_ch) &&
		*prev_ch != DIRECT_CHAR && *prev_ch != SEPARATOR_CHAR))
		return (0);
	return (1);
}

static	int		ft_count_w(char *str)
{
	int			ind;
	int			n;
	int			i;

	i = -1;
	n = 0;
	while (str[++i])
		if (!ft_not_c(str[i], (i == 0) ? NULL : &str[i - 1]))
		{
			ind = i;
			n++;
		}
	if (str[ind + 1] || n == 0)
		return (n + 1);
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
	if (!(table = (char**)malloc((ft_count_w(str) + 1) * sizeof(char*))))
		return (NULL);
	while (t[0] < ft_count_w(str))
	{
		t[1] = 0;
		if (*pt > 0)
			ft_position(str, pt);
		t[2] = ft_size_w(str, *pt);
		table[t[0]] = (char*)malloc((t[2] + 1) * sizeof(char));
		while (t[1] < t[2])
			table[t[0]][t[1]++] = str[(*pt)++];
		table[t[0]++][t[1]] = '\0';
		*pt += (!*pt) ? 1 : 0;
	}
	table[t[0]] = NULL;
	tabstr_trim(table);
	return (table);
}
