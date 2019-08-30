/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:52:01 by rcross            #+#    #+#             */
/*   Updated: 2019/05/04 22:52:02 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_wireframe(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			if (j < data->map->width - 1)
				drawline(data, *data->map->points[i][j]->aligned,
									*data->map->points[i][j + 1]->aligned);
			if (i < data->map->height - 1)
				drawline(data, *data->map->points[i][j]->aligned,
									*data->map->points[i + 1][j]->aligned);
		}
	}
}

/*
**	this transforms the wireframe
*/

void	world_to_aligned(t_data *data)
{
	float	matrix[4][4];
	int		i;
	int		j;

	get_id_matrix(matrix);
	matrix_rotate(matrix, data->xrot, data->yrot, data->zrot);
	matrix_scale(matrix,
				(WINDOW_WIDTH * data->scale) / data->map->width,
				(WINDOW_HEIGHT * data->scale) / data->map->height, 0);
	matrix_translate(matrix,
					WINDOW_WIDTH / 2 + data->xtrans,
					WINDOW_HEIGHT / 2 + data->ytrans, 0);
	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			matrix_vector_multiply(data->map->points[i][j]->world,
								matrix, data->map->points[i][j]->aligned);
			data->map->points[i][j]->aligned->z =
								data->map->points[i][j]->local->z;
		}
	}
}

void	redraw(t_data *data)
{
	world_to_aligned(data);
	mlx_clear_window(data->mlx, data->win);
	draw_wireframe(data);
}
