/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 04:56:50 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/30 04:56:52 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_not_c(char ch, char c)
{
	return ((ch != c) ? 1 : 0);
}

static int		ft_count_w(char *str, char c)
{
	int			n;
	int			i;

	i = -1;
	n = 0;
	while (str[++i])
		if (!ft_not_c(str[i], c))
			n++;
	return (n + 1);
}

static	int		ft_size_w(char *str, char c, int ind)
{
	int		i;

	i = ind;
	while (str[i] && ft_not_c(str[i], c) == 1)
		i++;
	return (i - ind);
}

char			**ft_strsplit_char(char *str, char c)
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
	if (!(table = (char**)malloc((ft_count_w(str, c) + 1) * sizeof(char*))))
		return (NULL);
	while (i < ft_count_w(str, c))
	{
		j = 0;
		k = ft_size_w(str, c, l);
		table[i] = (char*)malloc((k + 1) * sizeof(char));
		while (j < k)
			table[i][j++] = str[l++];
		table[i++][j] = '\0';
		l++;
	}
	table[i] = NULL;
	return (table);
}
