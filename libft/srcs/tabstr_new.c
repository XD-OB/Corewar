/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabstr_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:14:54 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:17:20 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**tabstr_new(size_t len)
{
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	tab[len] = NULL;
	return (tab);
}
