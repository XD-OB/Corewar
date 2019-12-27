/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 04:01:32 by obelouch          #+#    #+#             */
/*   Updated: 2019/03/02 04:34:26 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, int n)
{
	int		i;
	int		len_src;
	char	*dup;

	i = -1;
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (n > len_src)
		dup = (char*)malloc(sizeof(*src) * (len_src + 1));
	else
		dup = (char*)malloc(sizeof(*src) * n + 1);
	if (dup == 0)
		return (NULL);
	while (++i < len_src && i < n)
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}
