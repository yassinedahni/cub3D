/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_in_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 02:11:38 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/11 18:17:44 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_number(t_map *m, int i, int j)
{
	if (m->map[i][skip_space_2(m->map[i])] == 'N'
			&& m->map[i][skip_space_2(m->map[i]) + 1] == 'O'
			&& m->map[i][skip_space_2(m->map[i]) + 2] == ' ')
		j++;
	if (m->map[i][skip_space_2(m->map[i])] == 'S'
			&& m->map[i][skip_space_2(m->map[i]) + 1] == 'O'
			&& m->map[i][skip_space_2(m->map[i]) + 2] == ' ')
		j++;
	if (m->map[i][skip_space_2(m->map[i])] == 'W'
			&& m->map[i][skip_space_2(m->map[i]) + 1] == 'E'
			&& m->map[i][skip_space_2(m->map[i]) + 2] == ' ')
		j++;
	if (m->map[i][skip_space_2(m->map[i])] == 'E'
			&& m->map[i][skip_space_2(m->map[i]) + 1] == 'A'
			&& m->map[i][skip_space_2(m->map[i]) + 2] == ' ')
		j++;
	if (m->map[i][skip_space_2(m->map[i])] == 'F'
			&& m->map[i][skip_space_2(m->map[i]) + 1] == ' ')
		j++;
	if (m->map[i][skip_space_2(m->map[i])] == 'C'
			&& m->map[i][skip_space_2(m->map[i]) + 1] == ' ')
		j++;
	return (j);
}

void	check_number_of_arg_in_map(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->map[i])
	{
		j = check_number(m, i, j);
		i++;
	}
	if (j < 6 || j > 6)
		error();
}

void	check_name_of_direction_if_valid(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->map[i])
	{
		if (m->map[i][skip_space_2(m->map[i])] == 'N'
				&& m->map[i][skip_space_2(m->map[i]) + 1] != 'O')
			error();
		if (m->map[i][skip_space_2(m->map[i])] == 'S'
				&& m->map[i][skip_space_2(m->map[i]) + 1] != 'O')
			error();
		if (m->map[i][skip_space_2(m->map[i])] == 'W'
				&& m->map[i][skip_space_2(m->map[i]) + 1] != 'E')
			error();
		if (m->map[i][skip_space_2(m->map[i])] == 'E'
				&& m->map[i][skip_space_2(m->map[i]) + 1] != 'A')
			error();
		i++;
	}
}

void	check_name_of_direction_if_valid_available(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->map[i])
	{
		while (m->map[i][skip_space_2(m->map[i])] == '\n')
			i++;
		if (m->map[i][skip_space_2(m->map[i])] != 'S'
			&& m->map[i][skip_space_2(m->map[i])] != 'W'
			&& m->map[i][skip_space_2(m->map[i])] != 'E'
			&& m->map[i][skip_space_2(m->map[i])] != 'N'
			&& m->map[i][skip_space_2(m->map[i])] != 'F'
			&& m->map[i][skip_space_2(m->map[i])] != 'C'
			&& m->map[i][skip_space_2(m->map[i])] != '1')
		{
			error();
		}
		i++;
	}
}
