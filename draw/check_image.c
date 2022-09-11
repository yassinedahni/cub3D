/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:18:59 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/11 03:37:56 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_image_texture(t_map *m)
{
	if (open(m->north, O_RDONLY) == -1)
		error();
	if (open(m->south, O_RDONLY) == -1)
		error();
	if (open(m->west, O_RDONLY) == -1)
		error();
	if (open(m->east, O_RDONLY) == -1)
		error();
}
