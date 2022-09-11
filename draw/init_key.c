/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 02:07:16 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/11 21:53:25 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_up_up_down(int key, t_map *m)
{
	if (key == 126 || key == 13)
	{
		if (!check_wall(m, \
			m->player->p_x + m->player->v * sin(m->player->rot * (M_PI / 180)), \
			m->player->p_y + m->player->v * cos(m->player->rot * (M_PI / 180))))
			m->player->f_b = 0;
	}
	if (key == 125 || key == 1)
	{
		if (!check_wall(m, \
			m->player->p_x - m->player->v * sin(m->player->rot * (M_PI / 180)), \
			m->player->p_y - m->player->v * cos(m->player->rot * (M_PI / 180))))
			m->player->f_b = 0;
	}
}

void	key_up_left_right(int key, t_map *m)
{
	if (key == 2)
	{
		if (!check_wall(m, \
			m->player->p_x + m->player->v * \
			sin((m->player->rot + 90) * (M_PI / 180)), \
			m->player->p_y + m->player->v * \
			cos((m->player->rot + 90) * (M_PI / 180))))
		{
			m->player->l_r = 0;
			m->player->f_b = 0;
		}
	}
	if (key == 0)
	{
		if (!check_wall(m, \
			m->player->p_x + m->player->v * \
			sin((m->player->rot - 90) * (M_PI / 180)), \
			m->player->p_y + m->player->v * \
			cos((m->player->rot - 90) * (M_PI / 180))))
		{
			m->player->l_r = 0;
			m->player->f_b = 0;
		}
	}
}

int	key_up(int key, t_map *m)
{
	if (key == 124)
		m->player->rot_fac = 0;
	if (key == 123)
		m->player->rot_fac = 0;
	key_up_up_down(key, m);
	key_up_left_right(key, m);
	return (0);
}
