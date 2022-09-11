/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 01:52:34 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/11 00:46:35 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	add_arg_map_norm(t_map *m, int i, int j)
{
	if (m->map[i][j] == 'N' && m->map[i][j + 1] == 'O')
			m->north = ft_substr(m->map[i], skip_space(m, i, j + 2), \
			(ft_strlen(m->map[i]) - skip_space(m, i, j + 2)) - 1);
	if (m->map[i][j] == 'S' && m->map[i][j + 1] == 'O')
		m->south = ft_substr(m->map[i], skip_space(m, i, j + 2), \
		(ft_strlen(m->map[i]) - skip_space(m, i, j + 2)) - 1);
	if (m->map[i][j] == 'W' && m->map[i][j + 1] == 'E')
		m->west = ft_substr(m->map[i], skip_space(m, i, j + 2), \
		(ft_strlen(m->map[i]) - skip_space(m, i, j + 2)) - 1);
	if (m->map[i][j] == 'E' && m->map[i][j + 1] == 'A')
		m->east = ft_substr(m->map[i], skip_space(m, i, j + 2), \
		(ft_strlen(m->map[i]) - skip_space(m, i, j + 2)) - 1);
	if (m->map[i][j] == 'F')
		m->floor = ft_substr(m->map[i], skip_space(m, i, j + 1), \
		(ft_strlen(m->map[i]) - skip_space(m, i, j + 1)) - 1);
	if (m->map[i][j] == 'C')
		m->celling = ft_substr(m->map[i], skip_space(m, i, j + 1), \
		(ft_strlen(m->map[i]) - skip_space(m, i, j + 1)) - 1);
}

void	add_arg_map(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			add_arg_map_norm(m, i, j);
			j++;
		}
		i++;
	}
}
