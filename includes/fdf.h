/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:42:44 by rcross            #+#    #+#             */
/*   Updated: 2019/06/06 02:50:01 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "keys.h"
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# define COLOR1 0xffffff
# define COLOR2 0xff0000

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 1200

typedef struct	s_3dpoint
{
	float		x;
	float		y;
	float		z;
}				t_3dpoint;

/*
** local is just the x, y, z data we get from file
** world is the transformed data with an origin in the center
** aligned is the data changed by user input
*/

typedef struct	s_vertex
{
	t_3dpoint	*local;
	t_3dpoint	*world;
	t_3dpoint	*aligned;
}				t_vertex;

typedef struct	s_map
{
	t_vertex	***points;
	int			width;
	int			height;
	float		z_min;
	float		z_max;
}				t_map;

typedef struct	s_keys
{
	int			w:1;
	int			a:1;
	int			s:1;
	int			d:1;
	int			q:1;
	int			e:1;
	int			up:1;
	int			down:1;
	int			left:1;
	int			right:1;
	int			plus:1;
	int			minus:1;
}				t_keys;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	float		xtrans;
	float		ytrans;
	float		xrot;
	float		yrot;
	float		zrot;
	float		scale;
	int			*colors;
	t_map		*map;
	t_keys		*pressed;
}				t_data;

int				ft_usage(void);
int				ft_error(char *str);
void			check_file(t_data **data, char *file);
void			fdf(t_data *data);
void			local_to_world(t_data *data);
void			show_controls(void);
void			setup(t_data *data);
int				expose_hook(t_data *data);
void			key_hook_translation(t_data *data);
int				key_hook_press(int keycode, t_data *data);
void			draw_wireframe(t_data *data);
void			world_to_aligned(t_data *data);
void			redraw(t_data *data);
void			drawline(t_data *data, t_3dpoint p0, t_3dpoint p1);
void			draw_point(t_data *data, int x, int y, float z);
void			matrix_rotate(float mat[4][4], float xrot,
									float yrot, float zrot);
void			matrix_scale(float mat[4][4], float x, float y, float z);
void			matrix_translate(float mat[4][4], float x, float y, float z);
void			get_id_matrix(float mat[4][4]);
void			matrix_bzero(float mat[4][4]);
t_3dpoint		*get_3dpoint(float x, float y, float z);
t_vertex		*get_vertex(float x, float y, float z);
void			matrix_multiply(float m1[4][4],
									float m2[4][4], float dst[4][4]);
void			matrix_vector_multiply(t_3dpoint *src, float mat[4][4],
														t_3dpoint *dst);
void			set_hooks(t_data *data);
int				loop_hook(t_data *data);
int				key_hook_release(int keycode, t_data *data);
void			reset(t_data *data);
void			toggle_pressed(int keycode, t_data *data, int toggle);
void			destroy_everything(t_data **data);
void			destroy_map(t_map *map);
void			print_check(t_data *data);

#endif
