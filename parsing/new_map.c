/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 02:00:49 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/10 02:26:42 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	new_map_add(char *new, t_map *m, int i, int j)
{
	char	**map;

	map = malloc(sizeof(char *) * (j + 1));
	i = 0;
	j = 1;
	map[i] = ft_substr(new, i, map_len(new, i));
	while (new[i])
	{
		if (new[i] == '\n')
		{
			map[j] = ft_substr(new, i + 1, map_len(new, i + 1));
			j++;
		}
		i++;
	}
	map[j] = NULL;
	m->map = map;
}

void	new_map(char *new, t_map *m)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (new[i])
	{
		if (new[i] == '\n')
			j++;
		i++;
	}
	new_map_add(new, m, i, j);
}

void	add_map_of_play_norm(t_map *m, int i, int j)
{
	char	**new;

	new = NULL;
	new = malloc(sizeof(char *) * (j + 1));
	j = 0;
	while (m->map[i])
	{
		new[j] = ft_strdup(m->map[i]);
		j++;
		i++;
	}
	new[j] = NULL;
	m->map2 = new;
}

void	add_map_of_play(t_map *m)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	while (m->map[i])
	{
		if (m->map[i][skip_space_2(m->map[i])] == '1')
			break ;
		i++;
	}
	x = i;
	while (m->map[x])
	{
		j++;
		x++;
	}
	add_map_of_play_norm(m, i, j);
}
