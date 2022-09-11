/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:56:44 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/11 21:48:52 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	exit_mouse(int key)
{
	write (1, "EXIT", 4);
	exit(1);
	return (0);
}

void	key_hook_up_down(int key, t_map *m)
{
	if (key == 126 || key == 13)
	{
		if (!check_wall(m, \
			m->player->p_x + m->player->v * sin(m->player->rot * (M_PI / 180)), \
			m->player->p_y + m->player->v * cos(m->player->rot * (M_PI / 180))))
			m->player->f_b = 1;
	}
	if (key == 125 || key == 1)
	{
		if (!check_wall(m, \
			m->player->p_x - m->player->v * sin(m->player->rot * (M_PI / 180)), \
			m->player->p_y - m->player->v * cos(m->player->rot * (M_PI / 180))))
			m->player->f_b = -1;
	}
}

void	key_hook_left_right(int key, t_map *m)
{
	if (key == 2)
	{
		if (!check_wall(m, \
			m->player->p_x + m->player->v * \
			sin((m->player->rot + 90) * (M_PI / 180)), \
			m->player->p_y + m->player->v * \
			cos((m->player->rot + 90) * (M_PI / 180))))
		{
			m->player->l_r = 90;
			m->player->f_b = 1;
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
			m->player->l_r = -90;
			m->player->f_b = 1;
		}
	}
}

int	key_hook(int key, t_map *m)
{
	if (key == 124)
		m->player->rot_fac = 5;
	if (key == 123)
		m->player->rot_fac = -5;
	key_hook_up_down(key, m);
	key_hook_left_right(key, m);
	if (key == 53)
		exit_mouse(-1);
	return (0);
}
