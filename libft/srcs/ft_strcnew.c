/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 07:02:30 by ishaimou          #+#    #+#             */
/*   Updated: 2019/04/17 07:02:39 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcnew(size_t size, char c)
{
	char	*str;

	str = ft_strnew(size);
	while (size--)
		str[size] = c;
	return (str);
}
