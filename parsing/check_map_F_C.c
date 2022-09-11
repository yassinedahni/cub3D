/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_F_C.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:23:24 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/10 02:26:14 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	calcul_coma(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	return (j);
}

void	check_digit_of_f_c(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '\n')
				break ;
			if (str[i][j] >= '0' && str[i][j] <= '9')
				j++;
			else
				error();
		}
		i++;
	}
}

void	check_error_of_f_c(t_map *m)
{
	int	c;
	int	f;

	c = calcul_coma(m->celling);
	f = calcul_coma(m->floor);
	if (f > 2 || c > 2 || c < 0 || f < 0)
		error();
	if (m->c_r > 255 || m->c_g > 255 || m->c_b > 255
		|| m->c_r < 0 || m->c_g < 0 || m->c_b < 0)
		error();
	if (m->f_r > 255 || m->f_g > 255
		|| m->f_b > 255 || m->f_r < 0 || m->f_g < 0 || m->f_b < 0)
		error();
}

void	add_floor(t_map *m)
{
	char	**floor;
	int		i;

	i = 0;
	floor = ft_split(m->floor, ',');
	check_digit_of_f_c(floor);
	while (floor[i])
		i++;
	if (i != 3)
		error();
	m->f_r = ft_atoi(floor[0]);
	m->f_g = ft_atoi(floor[1]);
	m->f_b = ft_atoi(floor[2]);
	i = 0;
	while (floor[i])
	{
		free(floor[i]);
		i++;
	}
	free(floor);
}

void	add_celling(t_map *m)
{
	char	**celling;
	int		i;

	i = 0;
	celling = ft_split(m->celling, ',');
	check_digit_of_f_c(celling);
	while (celling[i])
		i++;
	if (i != 3)
		error();
	m->c_r = ft_atoi(celling[0]);
	m->c_g = ft_atoi(celling[1]);
	m->c_b = ft_atoi(celling[2]);
	i = 0;
	while (celling[i])
	{
		free(celling[i]);
		i++;
	}
	free(celling);
}
