/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 05:49:26 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 07:07:39 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_ultoa(unsigned long int nbr)
{
	unsigned long int	tmp;
	char				*res;
	unsigned long		size;

	size = 1;
	tmp = nbr;
	while (tmp /= 10)
		size++;
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (res);
	res[size] = '\0';
	tmp = nbr;
	while (size-- > 0)
	{
		res[size] = (tmp % 10) + 48;
		tmp /= 10;
	}
	return (res);
}
