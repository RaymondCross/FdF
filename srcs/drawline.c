/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:53:02 by rcross            #+#    #+#             */
/*   Updated: 2019/05/04 22:53:03 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		swap_vars(t_3dpoint *p0, t_3dpoint *p1)
{
	float temp;

	if (fabs(p1->x - p0->x) > fabs(p1->y - p0->y))
		return (0);
	temp = p0->y;
	p0->y = p0->x;
	p0->x = temp;
	temp = p1->y;
	p1->y = p1->x;
	p1->x = temp;
	return (1);
}

static void		get_deltas(float *delta, t_3dpoint p0, t_3dpoint p1)
{
	delta[0] = p1.x - p0.x;
	delta[1] = p1.y - p0.y;
	delta[2] = p1.z - p0.z;
}

void			draw_point(t_data *data, int x, int y, float z)
{
	unsigned int	color;
	float			which;

	if (x > 0 && y > 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
	{
		if (!data->map->z_max && !data->map->z_min)
			data->map->z_max = 1;
		which = ((z - data->map->z_min) /
					(data->map->z_max - data->map->z_min)) * 100;
		color = data->colors[abs((int)which - 1)];
		mlx_pixel_put(data->mlx, data->win, x, y, color);
	}
}

void			drawline(t_data *data, t_3dpoint p0, t_3dpoint p1)
{
	float		delta[3];
	float		error;
	float		slope;
	int			dir;

	dir = swap_vars(&p0, &p1);
	get_deltas(delta, p0, p1);
	slope = fabs(delta[1] / delta[0]);
	error = -1.0;
	while ((int)p0.x != (int)p1.x)
	{
		draw_point(data, dir ? p0.y : p0.x, dir ? p0.x : p0.y, p0.z);
		error += slope;
		if (error >= 0.0)
		{
			p0.y += (p0.y > p1.y) ? -1 : 1;
			error -= 1.0;
		}
		p0.z += delta[2] / fabs(delta[0]);
		p0.x += (p0.x > p1.x) ? -1 : 1;
	}
}
