/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 02:02:19 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/10 02:26:51 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_atoi(char *str)
{
	unsigned long	r;
	int				i;
	int				c;

	i = 0;
	r = 0;
	c = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			c *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (c * r);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new;

	i = ft_strlen(str);
	new = malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	map_len(char *new, int i)
{
	int	j;

	j = 0;
	while (new[i])
	{
		j++;
		if (new[i] == '\n')
			break ;
		i++;
	}
	return (j);
}

int	skip_space_2(char *map)
{
	int	i;

	i = 0;
	while (map[i] == ' ')
		i++;
	return (i);
}

int	skip_space(t_map *m, int i, int j)
{
	while (m->map[i][j] == ' ')
		j++;
	return (j);
}
