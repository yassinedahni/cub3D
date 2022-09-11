/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 00:13:45 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/11 03:38:08 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	loop(t_map *m)
{
	m->img = mlx_new_image(m->mlx, m->weight, m->height);
	m->addr = mlx_get_data_addr(m->img, &m->bits_per_pixel, \
		&m->line_length, &m->endian);
	draw_3d(m);
	if (check_wall(m, \
		m->player->p_x + m->player->v * m->player->f_b * \
		sin((m->player->rot + m->player->l_r) * (M_PI / 180)), \
		m->player->p_y + m->player->v * m->player->f_b * \
		cos((m->player->rot + m->player->l_r) * (M_PI / 180))) == 0)
	{
		m->player->p_x += m->player->v * m->player->f_b * \
			sin((m->player->rot + m->player->l_r) * (M_PI / 180));
		m->player->p_y += m->player->v * m->player->f_b * \
			cos((m->player->rot + m->player->l_r) * (M_PI / 180));
	}
	m->player->rot += m->player->rot_fac;
	mlx_put_image_to_window(m->mlx, m->mlx_wind, m->img, 0, 0);
	mlx_destroy_image(m->mlx, m->img);
	return (0);
}

void	draw(t_map *m)
{
	m->height = 1080;
	m->weight = 1920;
	m->player->rot = angle_of_player(m);
	m->mlx = mlx_init();
	m->mlx_wind = mlx_new_window(m->mlx, m->weight, m->height, "cub3D");
	get_image_for_texture(m);
	position_of_player(m);
	mlx_hook(m->mlx_wind, 17, 0L, exit_mouse, m);
	mlx_hook(m->mlx_wind, 02, 1L << 0, key_hook, m);
	mlx_hook(m->mlx_wind, 03, 1L << 3, key_up, m);
	mlx_loop_hook(m->mlx, loop, m);
	mlx_loop(m->mlx);
}
