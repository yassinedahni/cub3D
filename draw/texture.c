/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:43:14 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/11 03:53:42 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_image_for_texture(t_map *m)
{
	m->image = malloc(sizeof(t_map) * 4);
	m->image[0].img = mlx_xpm_file_to_image(m->mlx, m->north, &m->h, &m->l);
	m->image[0].addr = mlx_get_data_addr(m->image[0].img, \
		&m->image[0].bits_per_pixel, \
		&m->image[0].line_length, &m->image[0].endian);
	m->image[1].img = mlx_xpm_file_to_image(m->mlx, m->south, &m->h, &m->l);
	m->image[1].addr = mlx_get_data_addr(m->image[1].img, \
		&m->image[1].bits_per_pixel, \
		&m->image[1].line_length, &m->image[1].endian);
	m->image[2].img = mlx_xpm_file_to_image(m->mlx, m->west, &m->h, &m->l);
	m->image[2].addr = mlx_get_data_addr(m->image[2].img, \
		&m->image[2].bits_per_pixel, \
		&m->image[2].line_length, &m->image[2].endian);
	m->image[3].img = mlx_xpm_file_to_image(m->mlx, m->east, &m->h, &m->l);
	m->image[3].addr = mlx_get_data_addr(m->image[3].img, \
		&m->image[3].bits_per_pixel, \
		&m->image[3].line_length, &m->image[3].endian);
}

int	check_direction_of_texture(t_map *m, float x, float y)
{
	int	direction;

	direction = 0;
	if (m->map2[(int)((x - 1) / 64)][(int)(y / 64)] == '0')
		direction = 1;
	if (m->map2[(int)((x + 1) / 64)][(int)(y / 64)] == '0')
		direction = 2;
	if (m->map2[(int)(x / 64)][(int)((y - 1) / 64)] == '0')
		direction = 3;
	if (m->map2[(int)(x / 64)][(int)((y + 1) / 64)] == '0')
		direction = 4;
	return (direction);
}

int	get_color_image(t_map *m, int x, int y, int direction)
{
	char	*dst;

	if (direction == 1)
		dst = m->image[0].addr + (y * m->image[0].line_length + x \
			* (m->image[0].bits_per_pixel / 8));
	if (direction == 2)
		dst = m->image[1].addr + (y * m->image[1].line_length + x \
			* (m->image[1].bits_per_pixel / 8));
	if (direction == 3)
		dst = m->image[2].addr + (y * m->image[2].line_length + x \
			* (m->image[2].bits_per_pixel / 8));
	if (direction == 4)
		dst = m->image[3].addr + (y * m->image[3].line_length + x \
			* (m->image[3].bits_per_pixel / 8));
	return (*(int *)dst);
}

void	my_mlx_pixel_put(t_map *m, int x, int y, int color)
{
	char	*d;

	d = m->addr + (y * m->line_length + x * (m->bits_per_pixel / 8));
	*(int *)d = color;
}
