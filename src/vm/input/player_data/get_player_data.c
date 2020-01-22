/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 13:27:11 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/22 01:24:01 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		reverse_bytes(void *add, size_t size)
{
	size_t			i;
	unsigned char	*address;
	unsigned char	h;

	address = (unsigned char *)add;
	i = 0;
	while (i < size / 2)
	{
		h = address[i];
		address[i] = address[size - i - 1];
		address[size - i - 1] = h;
		i++;
	}
}

static int	set_player_number(char *file)
{
	int		i;
	char	*strtmp;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		strtmp = g_flags[FLAG_ORDER_I].data.order_data[i];
		if (strtmp)
			if (ft_strequ(strtmp, file) && !g_players[i].present)
				return (i + 1);
	}
	i = -1;
	while (++i < MAX_PLAYERS)
		if (!g_players[i].present && !g_flags[FLAG_ORDER_I].data.order_data[i])
			return (i + 1);
	return (0);
}

/*
** n stands for player number
*/

void		get_player_data(int fd, char *file)
{
	int				n;
	t_player		*player;
	unsigned int	delimiter;

	n = set_player_number(file);
	player = &g_players[n - 1];
	player->present = TRUE;
	read(fd, &player->header.magic, sizeof(player->header.magic));
	reverse_bytes(&player->header.magic, sizeof(player->header.magic));
	if (player->header.magic != COREWAR_EXEC_MAGIC)
		magic_header_error(file);
	read(fd, player->header.prog_name, PROG_NAME_LENGTH);
	read(fd, &delimiter, sizeof(delimiter));
	if (delimiter != 0)
		delimiter_error(file, "champion name");
	read(fd, &player->header.prog_size, sizeof(player->header.prog_size));
	reverse_bytes(&player->header.prog_size, sizeof(player->header.prog_size));
	check_prog_size(file, player->header.prog_size);
	read(fd, player->header.comment, COMMENT_LENGTH);
	read(fd, &delimiter, sizeof(delimiter));
	if (delimiter != 0)
		delimiter_error(file, "champion comment");
	n = read(fd, player->ex_code, player->header.prog_size);
	check_ex_code(fd, file, player->header.prog_size, n);
}
