/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_check_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:05:45 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/11 00:25:42 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_all(t_map *m)
{
	add_arg_map(m);
	add_map_of_play(m);
	add_floor(m);
	add_celling(m);
	check_name_of_direction(m);
	check_number_of_arg_in_map(m);
	check_name_of_direction_if_valid(m);
	check_name_of_direction_if_valid_available(m);
	check_map_of_wall_if_valid(m);
	check_map_of_wall_if_valid_2(m);
	check_direction_in_map_if_valid(m);
	check_map_if_valid(m);
	check_zero_in_map_if_valid(m);
	check_zero_in_map_if_valid_complete(m);
	check_error_of_w(m);
	check_error_of_e(m);
	check_error_of_n(m);
	check_error_of_s(m);
	check_error_of_f_c(m);
	check_image_texture(m);
}
