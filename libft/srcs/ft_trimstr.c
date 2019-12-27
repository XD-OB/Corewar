/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:13:19 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/17 07:49:18 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_blank(char c)
{
	return ((c == 32 || c == 9));
}

static int	ft_strlen_trim(char *str)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (is_blank(str[i]))
		i++;
	while (str[i])
	{
		len++;
		i++;
	}
	while (is_blank(str[--i]) && len > 0)
		len--;
	return (len);
}

void		ft_trimstr(char **str)
{
	char	*new;
	int		new_len;
	int		i;
	int		j;

	if (!str || !*str)
		return ;
	new_len = ft_strlen_trim(*str);
	new = (char*)malloc(sizeof(char) * (new_len + 1));
	new[new_len] = '\0';
	i = 0;
	while (is_blank((*str)[i]))
		i++;
	j = 0;
	while (j < new_len)
		new[j++] = (*str)[i++];
	free(*str);
	*str = new;
}
