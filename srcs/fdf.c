/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:52:51 by rcross            #+#    #+#             */
/*   Updated: 2019/06/17 22:40:37 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		init_color_table(t_data *data)
{
	int				i;
	float			f;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	data->colors = (int *)malloc(sizeof(int) * 100);
	f = 0;
	i = -1;
	while (++i < 100)
	{
		r = (sin(f) + 1) * 127;
		g = (sin(f) + 1) * 5;
		b = (cos(f) + 1) * 127;
		data->colors[i] = ((int)r) << 16 | ((int)g) << 8 | b;
		f += M_PI / 100;
	}
}

void			show_controls(void)
{
	ft_putendl("\n============CONTROLS============\n\n\
	Translation:\n\
	Y: Key: UP, DOWN\n\
	X: Key: LEFT, RIGHT\n\n\
	Rotation:\n\
	X: Key: W, S\n\
	Y: Key: A, D\n\
	Z: Key: Q, E\n\n\
	Zoom:\n\
	IN: Keypad: +\n\
	OUT: Keypad: -\n\n\
	Reset:\n\
	Key: R");
}

/*
** just starting values for wireframe
*/

void			setup(t_data *data)
{
	data->xtrans = 0.0;
	data->ytrans = 0.0;
	data->xrot = 0.0;
	data->yrot = 0.0;
	data->zrot = 0.0;
	data->scale = 0.5;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	data->pressed = (t_keys *)ft_memalloc(sizeof(t_keys));
}

/*
**	this sets the origin at the center of the wireframe
*/

void			local_to_world(t_data *data)
{
	float	matrix[4][4];
	int		i;
	int		j;

	get_id_matrix(matrix);
	matrix_translate(matrix, -(data->map->width / 2),
								-(data->map->height / 2), 0);
	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			matrix_vector_multiply(data->map->points[i][j]->local, matrix,
									data->map->points[i][j]->world);
		}
	}
}

void			fdf(t_data *data)
{
	setup(data);
	init_color_table(data);
	show_controls();
	local_to_world(data);
	set_hooks(data);
	mlx_loop(data->mlx);
}
