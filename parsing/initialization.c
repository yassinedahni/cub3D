/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:51:43 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/11 21:49:44 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_struct(t_map *m)
{
	m->player->f_b = 0;
	m->player->l_r = 0;
	m->player->rot_fac = 0;
	m->player->v = 15;
	m->map2 = NULL;
	m->map = NULL;
	m->north = NULL;
	m->south = NULL;
	m->west = NULL;
	m->east = NULL;
	m->floor = NULL;
	m->celling = NULL;
}

void	init_struct_dda(t_map *m)
{
	m->dda->dx = 0;
	m->dda->dy = 0;
	m->dda->steps = 0;
	m->dda->direction = 0;
	m->dda->h = 0;
	m->dda->w = 0;
	m->dda->angle = 0;
	m->dda->angle_fov = 0;
	m->dda->i = 0;
	m->dda->xinc = 0;
	m->dda->yinc = 0;
	m->dda->x = 0;
	m->dda->y = 0;
	m->dda->dis = 0;
	m->dda->new_dis = 0;
	m->dda->wall = 0;
	m->dda->flag = 0;
}

void	init_position(t_map *m)
{
	m->e = -1;
	m->w = -1;
	m->s = -1;
	m->n = -1;
}

int	final_position(t_map *m)
{
	if (m->e != -1)
		return (m->e);
	else if (m->w != -1)
		return (m->w);
	else if (m->s != -1)
		return (m->s);
	else if (m->n != -1)
		return (m->n);
	return (-1);
}
