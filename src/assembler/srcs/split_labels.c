/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 06:15:30 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/28 07:24:25 by ishaimou         ###   ########.fr       */
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

static int		ft_count_w(char *str)
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
	if (n == 0 || str[ind + 1])
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
	int		i;
	int		j;
	int		k;
	int		l;
	char	**table;

	if (str == NULL)
		return (NULL);
	i = 0;
	l = 0;
	if (!(table = (char**)malloc((ft_count_w(str) + 1) * sizeof(char*))))
		return (NULL);
	while (i < ft_count_w(str))
	{
		j = 0;
		k = ft_size_w(str, l);
		table[i] = (char*)malloc((k + 1) * sizeof(char));
		while (j < k)
			table[i][j++] = str[l++];
		table[i++][j] = '\0';
		l++;
	}
	table[i] = NULL;
	tabstr_trim(table);
	return (table);
}
