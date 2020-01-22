/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ends_with.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:32:57 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/21 19:33:23 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** charck if a giving string ends with a word
*/

int		ft_ends_with(char *str, char *word)
{
	int i;
	int l1;
	int l2;

	l1 = ft_strlen(str);
	l2 = ft_strlen(word);
	if (l1 < l2)
		return (0);
	else
	{
		i = 0;
		while (word[i])
		{
			if (str[i + l1 - l2] != word[i])
				return (0);
			i++;
		}
		return (1);
	}
}
