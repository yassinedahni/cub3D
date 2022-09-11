/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_S_N.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:47:24 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/10 02:26:22 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_error_of_n_norm(t_map *m, int i, int j)
{
	if ((m->map2[i][j] == ' ' && m->map2[i + 1][j] == 'N')
		|| (m->map2[i][j] == '\n' && m->map2[i + 1][j] == 'N')
		|| (m->map2[i][j] == 'N' && m->map2[i + 1][j] == ' ')
		|| (m->map2[i][j] == 'N' && m->map2[i + 1][j] == '\0')
		|| (m->map2[i][j] == 'N' && m->map2[i][j + 1] == ' ')
		|| (m->map2[i][j] == ' ' && m->map2[i][j + 1] == 'N'))
	{
		error();
	}
}

void	check_error_of_n(t_map *m)
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
			check_error_of_n_norm(m, i, j);
			j++;
		}
		j++;
		i++;
	}
}

void	check_error_of_s_norm(t_map *m, int i, int j)
{
	if ((m->map2[i][j] == ' ' && m->map2[i + 1][j] == 'S')
		|| (m->map2[i][j] == '\n' && m->map2[i + 1][j] == 'S')
		|| (m->map2[i][j] == 'S' && m->map2[i + 1][j] == ' ')
		|| (m->map2[i][j] == 'S' && m->map2[i + 1][j] == '\0')
		|| (m->map2[i][j] == 'S' && m->map2[i][j + 1] == ' ')
		|| (m->map2[i][j] == ' ' && m->map2[i][j + 1] == 'S'))
	{
		error();
	}
}

void	check_error_of_s(t_map *m)
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
			check_error_of_s_norm(m, i, j);
			j++;
		}
		j++;
		i++;
	}
}
