/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poslltoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 07:01:24 by ishaimou          #+#    #+#             */
/*   Updated: 2019/04/17 07:02:03 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_poslltoa(long long int n)
{
	long long int	tmp;
	int				size;
	char			*res;

	if (n == LLONG_MIN)
		return (ft_strdup("9223372036854775808"));
	if (n < 0)
		n *= -1;
	tmp = n;
	size = 1;
	while (tmp /= 10)
		size++;
	res = ft_strnew(size);
	tmp = n;
	while (--size >= 0)
	{
		res[size] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (res);
}
