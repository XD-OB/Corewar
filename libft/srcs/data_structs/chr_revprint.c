/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_revprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:23:30 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:23:35 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	chr_revprint(t_chr *list)
{
	if (!list->next)
		return ;
	list = list->next;
	chr_revprint(list);
	ft_putstr(list->str);
	write(1, "\n", 1);
}
