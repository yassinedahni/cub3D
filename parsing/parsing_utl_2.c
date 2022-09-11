/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utl_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 02:04:14 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/10 02:26:46 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_map(char **av)
{
	char	*new;
	char	*str;
	int		fd;

	new = ft_strdup("");
	check_name(av[1]);
	fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		new = ft_strjoin(new, str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	if (new[0] == '\0')
		exit(1);
	return (new);
}
