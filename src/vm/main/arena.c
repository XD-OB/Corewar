/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 22:18:33 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/10 02:40:31 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_flag			g_flags[SUPPORTED_FLAGS_NUM];

t_player		g_players[MAX_PLAYERS];

t_arena			g_arena;

char			g_type[3];
