/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 06:15:30 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/28 00:28:01 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_not_c(char ch, char *prev_ch)
{
	if (ch != LABEL_CHAR)
		return (1);
	if (prev_ch)
	{
		if (ft_isblank(*prev_ch))
			return (1);
		if (*prev_ch == SEPARATOR_CHAR)
			return (1);
		if (*prev_ch == DIRECT_CHAR)
			return (1);
	}
	return (0);
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

char			**split_labels(char *str)
{
	int		t[4];
	char	**table;

	if (str == NULL)
		return (NULL);
	t[0] = 0;
	t[3] = 0;
	if (!(table = (char**)malloc((ft_count_w(str) + 1) * sizeof(char*))))
		return (NULL);
	while (t[0] < ft_count_w(str))
	{
		t[1] = 0;
		t[2] = ft_size_w(str, t[3]);
		table[t[0]] = (char*)malloc((t[2] + 1) * sizeof(char));
		while (t[1] < t[2])
			table[t[0]][t[1]++] = str[(t[3])++];
		table[t[0]++][t[1]] = '\0';
		(t[3])++;
	}
	table[t[0]] = NULL;
	tabstr_trim(table);
	return (table);
}
