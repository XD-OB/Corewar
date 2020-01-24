/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 07:02:14 by ishaimou          #+#    #+#             */
/*   Updated: 2019/04/17 07:02:20 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_pushback(char *str, char c)
{
	char	*new_str;
	int		newlen;
	int		len;

	len = ft_strlen(str);
	newlen = len + 1;
	new_str = ft_strnew(newlen);
	new_str[len] = c;
	while (len--)
		new_str[len] = str[len];
	free(str);
	return (new_str);
}
