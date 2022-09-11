/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position_of_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:33:29 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/11 03:39:43 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	angle_of_player(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init_position(m);
	while (m->map2[i])
	{
		j = 0;
		while (m->map2[i][j])
		{
			if (m->map2[i][j] == 'E')
				m->e = 0;
			if (m->map2[i][j] == 'W')
				m->w = 180;
			if (m->map2[i][j] == 'S')
				m->s = 90;
			if (m->map2[i][j] == 'N')
				m->n = 270;
			j++;
		}
		j++;
		i++;
	}
	return (final_position(m));
}

void	position_of_player_complete(t_map *m, int x, int y)
{
	if (m->map2[x][y] == 'E')
	{
		m->map2[x][y] = '0';
		m->player->p_x = x * 64;
		m->player->p_y = y * 64;
	}
	if (m->map2[x][y] == 'S')
	{
		m->map2[x][y] = '0';
		m->player->p_x = x * 64;
		m->player->p_y = y * 64;
	}
	if (m->map2[x][y] == 'N')
	{
		m->map2[x][y] = '0';
		m->player->p_x = x * 64;
		m->player->p_y = y * 64;
	}
}

void	position_of_player(t_map *m)
{
	int	y;
	int	x;

	x = 0;
	while (m->map2[x])
	{
		y = 0;
		while (m->map2[x][y])
		{
			if (m->map2[x][y] == 'W')
			{
				m->map2[x][y] = '0';
				m->player->p_x = x * 64;
				m->player->p_y = y * 64;
			}
			position_of_player_complete(m, x, y);
			y++;
		}
		x++;
	}
	m->player->p_x += 2.5;
	m->player->p_y += 2.5;
}
