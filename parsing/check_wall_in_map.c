/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 02:12:38 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/11 18:08:46 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map_of_wall_if_valid(t_map *m)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (m->map2[i])
	{
		if (m->map2[i][skip_space_2(m->map2[i])] != '1'
			|| m->map2[i][ft_strlen(m->map2[i]) - 2] != '1')
			error();
		i++;
	}
	if (m->map2[i - 1][0] == ' ')
		j = skip_space_2(m->map2[i - 1]);
	while (m->map[i - 1][j])
	{
		if (m->map2[i - 1][j] == '0')
			error();
		if (m->map2[i - 1][j + 1] == '\0')
			break ;
		if (m->map2[i - 1][j] == '1' || m->map2[i - 1][j] == ' ')
			j++;
		else
			error();
	}
}

void	check_map_of_wall_if_valid_2(t_map *m)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (m->map2[i][0] == ' ')
		j = skip_space_2(m->map2[i]);
	while (m->map2[i][j])
	{
		if (m->map2[i][j + 1] == '\0')
			break ;
		if (m->map2[i][j] == '1' || m->map2[i][j] == ' ')
			j++;
		else
			error();
	}
}

int	check_wall(t_map *m, float x, float y)
{
	if (m->map2[(int)(x / 64)][(int)(y / 64)] == '1'
		|| m->map2[(int)(x / 64)][(int)(y / 64)] == '\0'
		|| m->map2[(int)(x / 64)][(int)(y / 64)] == '\n'
		|| m->map2[(int)(x / 64)][(int)(y / 64)] == ' ')
		return (1);
	return (0);
}
