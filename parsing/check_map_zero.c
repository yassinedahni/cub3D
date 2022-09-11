/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:29:24 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/10 02:26:29 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_zero_in_map_if_valid_complete_norm(t_map *m, int i, int j)
{
	if ((m->map2[i][j] == '0' && !m->map2[i - 1][j])
			|| (m->map2[i][j] == '0' && (m->map2[i - 1][j] == '\0'
			|| m->map2[i - 1][j] == '\n')))
	{
		if (ft_strlen(&m->map2[i - 1][j]) < j)
			error();
	}
}

void	check_zero_in_map_if_valid_complete(t_map *m)
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
			if ((m->map2[i][j] == ' ' && m->map2[i + 1] == NULL))
				break ;
			check_zero_in_map_if_valid_complete_norm(m, i, j);
			j++;
		}
		j++;
		i++;
	}
}

void	check_zero_in_map_if_valid_norm(t_map *m, int i, int j)
{
	if ((m->map2[i][j] == ' ' && m->map2[i + 1][j] == '0')
		|| (m->map2[i][j] == '0' && m->map2[i + 1][j] == ' ')
		|| (m->map2[i][j] == '0' && m->map2[i][j + 1] == ' ')
		|| (m->map2[i][j] == ' ' && m->map2[i][j + 1] == '0'))
	{
		error();
	}
}

void	check_zero_in_map_if_valid(t_map *m)
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
			if ((m->map2[i][j] == ' ' && m->map2[i + 1] == NULL))
				break ;
			check_zero_in_map_if_valid_norm(m, i, j);
			j++;
		}
		j++;
		i++;
	}
}
