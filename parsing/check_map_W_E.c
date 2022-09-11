/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_W_E.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:33:53 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/10 02:26:25 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_error_of_w_norm(t_map *m, int i, int j)
{
	if ((m->map2[i][j] == ' ' && m->map2[i + 1][j] == 'W')
		|| (m->map2[i][j] == '\n' && m->map2[i + 1][j] == 'W')
		|| (m->map2[i][j] == 'W' && m->map2[i + 1][j] == ' ')
		|| (m->map2[i][j] == 'W' && m->map2[i + 1][j] == '\0')
		|| (m->map2[i][j] == 'W' && m->map2[i][j + 1] == ' ')
		|| (m->map2[i][j] == ' ' && m->map2[i][j + 1] == 'W'))
	{
		error();
	}
}

void	check_error_of_w(t_map *m)
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
			check_error_of_w_norm(m, i, j);
			j++;
		}
		j++;
		i++;
	}
}

void	check_error_of_e_norm(t_map *m, int i, int j)
{
	if ((m->map2[i][j] == ' ' && m->map2[i + 1][j] == 'E')
		|| (m->map2[i][j] == '\n' && m->map2[i + 1][j] == 'S')
		|| (m->map2[i][j] == 'E' && m->map2[i + 1][j] == ' ')
		|| (m->map2[i][j] == 'E' && m->map2[i + 1][j] == '\0')
		|| (m->map2[i][j] == 'E' && m->map2[i][j + 1] == ' ')
		|| (m->map2[i][j] == ' ' && m->map2[i][j + 1] == 'E'))
	{
		error();
	}
}

void	check_error_of_e(t_map *m)
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
			check_error_of_e_norm(m, i, j);
			j++;
		}
		j++;
		i++;
	}
}
