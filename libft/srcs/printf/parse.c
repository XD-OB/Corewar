/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:15:23 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/18 08:18:12 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_node(t_lst *node)
{
	node->arglist = NULL;
	node->format->precis = -1;
	node->format->width = 0;
	node->format->convers = '\0';
	node->format->pos = 0;
	node->format->argn = 0;
}

static t_lst	*create_node(void)
{
	t_lst		*node;

	node = (t_lst*)malloc(sizeof(t_lst));
	node->format = (t_format*)malloc(sizeof(t_format));
	init_node(node);
	node->next = NULL;
	return (node);
}

static void		advance_free(t_lst **node, int *p)
{
	free((*node)->format);
	free(*node);
	*p = -1;
}

t_lst			*parse_format(va_list ap, char *str, int *pflag)
{
	t_lst		*head;
	t_lst		*node;
	long		i;

	i = -1;
	head = NULL;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (!str[++i])
				return (head);
			node = create_node();
			if (check_fill(ap, &str[i], i - 1, node) != -1)
			{
				head = add_node(head, node);
				while (str[i] && str[i] != node->format->convers)
					i++;
			}
			else
				advance_free(&node, pflag);
			node = node->next;
		}
	}
	return (head);
}
