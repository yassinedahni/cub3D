/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:48:34 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/11 02:29:13 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int			fd;
	char		*new;
	t_map		*m;

	m = malloc(sizeof(t_map));
	m->player = malloc(sizeof(t_player));
	m->dda = malloc(sizeof(t_dda));
	init_struct(m);
	if (ac == 2)
	{
		new = get_map(av);
		new_map(new, m);
		free (new);
		check_all(m);
		draw(m);
	}
}
