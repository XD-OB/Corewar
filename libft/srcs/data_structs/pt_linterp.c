/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_linterp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:03:14 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 21:03:16 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_point			pt_linterp(t_point p1, t_point p2, int a, int t)
{
	t_point		p;

	p.x = ((float)((p2.x - p1.x) * a) / t) + p1.x;
	p.y = ((float)((p2.y - p1.y) * a) / t) + p1.y;
	return (p);
}
