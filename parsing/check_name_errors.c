/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 02:09:32 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/10 02:26:32 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error(void)
{
	write (1, "Error\n", 7);
	exit (1);
}

void	check_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.')
		i++;
	if (str[i + 1] != 'c' )
		error();
	if (str[i + 2] != 'u')
		error();
	if (str[i + 3] != 'b' )
		error();
	if (str[i + 4])
		error();
}

int	check_name_of_direction_norm(t_map *m, int i, int j)
{
	if (m->map[i][j] == 'N' && m->map[i][j + 1] == 'O'
			&& m->map[i][j + 2] != ' ')
		return (-1);
	if (m->map[i][j] == 'S' && m->map[i][j + 1] == 'O'
			&& m->map[i][j + 2] != ' ')
		return (-1);
	if (m->map[i][j] == 'W' && m->map[i][j + 1] == 'E'
			&& m->map[i][j + 2] != ' ')
		return (-1);
	if (m->map[i][j] == 'E' && m->map[i][j + 1] == 'A'
			&& m->map[i][j + 2] != ' ')
		return (-1);
	if (m->map[i][j] == 'F' && m->map[i][j + 1] != ' ')
		return (-1);
	if (m->map[i][j] == 'C' && m->map[i][j + 1] != ' ')
		return (-1);
	return (0);
}

void	check_name_of_direction(t_map *m)
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
			if (check_name_of_direction_norm(m, i, j) == -1)
				error();
			j++;
		}
		i++;
	}
}
