/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_if_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:46:24 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/10 02:26:19 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_direction_in_map_if_valid(t_map *m)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (m->map2[i])
	{
		j = 0;
		while (m->map2[i][j])
		{
			if (m->map2[i][j] == 'W'
				|| m->map2[i][j] == 'S'
				|| m->map2[i][j] == 'N'
				|| m->map2[i][j] == 'E')
				x++;
			j++;
		}
		i++;
	}
	if (x > 1 || x < 1)
		error();
}

void	check_map_if_valid(t_map *m)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (m->map2[i])
	{
		j = 0;
		while (m->map2[i][j])
		{
			if (m->map2[i][j] == 'W' || m->map2[i][j] == 'E'
				|| m->map2[i][j] == 'N' || m->map2[i][j] == 'S'
				|| m->map2[i][j] == '1'
				|| m->map2[i][j] == '0' || m->map2[i][j] == ' '
				|| m->map2[i][j] == '\n')
			{
				j++;
			}
			else
				error();
		}
		i++;
	}
}
