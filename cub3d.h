/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:49:14 by ydahni            #+#    #+#             */
/*   Updated: 2022/09/11 03:35:53 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"
# include <mlx.h>
# include <math.h>

typedef struct dda
{
	int		dx;
	int		dy;
	int		steps;
	int		direction;
	int		h;
	int		w;
	float	angle;
	float	angle_fov;
	float	i;
	float	xinc;
	float	yinc;
	float	x;
	float	y;
	float	dis;
	float	new_dis;
	float	wall;
	float	flag;
}	t_dda;

typedef struct texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct player
{
	int		p_x;
	int		p_y;
	int		f_b;
	int		l_r;
	int		v;
	float	rot_fac;
	float	rot;
}			t_player;

typedef struct map
{
	char		**map;
	char		**map2;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*floor;
	int			f_r;
	int			f_g;
	int			f_b;
	char		*celling;
	int			c_r;
	int			c_g;
	int			c_b;
	int			n;
	int			s;
	int			w;
	int			e;
	int			h;
	int			l;
	int			p_x;
	int			p_y;
	void		*mlx;
	void		*mlx_wind;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			weight;
	t_player	*player;
	t_texture	*image;
	t_dda		*dda;
}	t_map;

//parsing_utl.c
int		ft_atoi(char *str);
char	*ft_strdup(char *str);
int		map_len(char *new, int i);
int		skip_space_2(char *map);
int		skip_space(t_map *m, int i, int j);

//parsing_utl_2.c
char	*get_map(char **av);

//ft_split
char	**ft_split(char *s, char c);
int		ft_counterword(char const *s, char c);
int		ft_counterchar(char const *s, char c);

//new_map
void	new_map(char *new, t_map *m);
void	add_arg_map(t_map *m);
void	add_map_of_play(t_map *m);

//add_arg_in_map
void	add_arg_map(t_map *m);
void	add_arg_map_norm(t_map *m, int i, int j);

//check_name_errors.c
void	error(void);
void	check_name(char *str);
void	check_name_of_direction(t_map *m);
int		check_name_of_direction_norm(t_map *m, int i, int j);

//check_arg_in_map
void	check_number_of_arg_in_map(t_map *m);
void	check_name_of_direction_if_valid(t_map *m);
void	check_name_of_direction_if_valid_available(t_map *m);

//check_wall_in_map
void	check_map_of_wall_if_valid(t_map *m);
void	check_map_of_wall_if_valid_2(t_map *m);
int		check_wall(t_map *m, float x, float y);

//check_map_if_valid
void	check_direction_in_map_if_valid(t_map *m);
void	check_map_if_valid(t_map *m);
int		check_wall(t_map *m, float x, float y);

//check_map_zero
void	check_zero_in_map_if_valid(t_map *m);
void	check_zero_in_map_if_valid_norm(t_map *m, int i, int j);
void	check_zero_in_map_if_valid_complete(t_map *m);
void	check_zero_in_map_if_valid_complete_norm(t_map *m, int i, int j);

//check_map_W_E
void	check_error_of_w(t_map *m);
void	check_error_of_w_norm(t_map *m, int i, int j);
void	check_error_of_e(t_map *m);
void	check_error_of_e_norm(t_map *m, int i, int j);

//check_map_S_N
void	check_error_of_n(t_map *m);
void	check_error_of_n_norm(t_map *m, int i, int j);
void	check_error_of_s(t_map *m);
void	check_error_of_s_norm(t_map *m, int i, int j);

//check_map_f_c
void	check_error_of_f_c(t_map *m);
void	check_digit_of_f_c(char **str);
int		calcul_coma(char *str);
void	add_floor(t_map *m);
void	add_celling(t_map *m);

//initialization
void	init_position(t_map *m);
int		final_position(t_map *m);
void	init_struct(t_map *m);
void	init_struct_dda(t_map *m);

//check_position_of_player
int		angle_of_player(t_map *m);
void	position_of_player(t_map *m);
void	position_of_player_complete(t_map *m, int x, int y);

//check_image
void	check_image_texture(t_map *m);

//cub3D_check_all
void	check_all(t_map *m);

//cub3D_DDA
void	dda_line(int x1, int y1, t_map *m);
void	draw_3d(t_map *m);

//draw
void	draw(t_map *m);

//Convert_RGB
int		color_rgb(int r, int g, int b);

//texture
void	get_image_for_texture(t_map *m);
void	my_mlx_pixel_put(t_map *m, int x, int y, int color);
int		check_direction_of_texture(t_map *m, float x, float y);
int		get_color_image(t_map *m, int x, int y, int d);

//key
int		exit_mouse(int key);
int		key_hook(int key, t_map *m);
void	key_hook_up_down(int key, t_map *m);
void	key_hook_left_right(int key, t_map *m);

//init_key
int		key_up(int key, t_map *m);
void	key_up_left_right(int key, t_map *m);
void	key_up_up_down(int key, t_map *m);

#endif