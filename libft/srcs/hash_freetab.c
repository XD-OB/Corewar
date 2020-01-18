/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_freetab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:13:14 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:13:16 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		hash_freetab(char ***tab_hash, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free((*tab_hash)[i++]);
	free(*tab_hash);
}
