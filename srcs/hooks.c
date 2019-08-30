/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:39:42 by rcross            #+#    #+#             */
/*   Updated: 2019/05/04 22:39:43 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			expose_hook(t_data *data)
{
	redraw(data);
	return (0);
}

int			key_hook_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(data->mlx, data->win);
		destroy_everything(&data);
		free(data);
		exit(0);
		return (0);
	}
	if (keycode == KEY_R)
	{
		reset(data);
		return (0);
	}
	toggle_pressed(keycode, data, 1);
	return (0);
}

int			key_hook_release(int keycode, t_data *data)
{
	toggle_pressed(keycode, data, 0);
	return (0);
}

int			loop_hook(t_data *data)
{
	key_hook_translation(data);
	if (data->pressed->w)
		data->xrot += 0.05;
	if (data->pressed->a)
		data->yrot -= 0.05;
	if (data->pressed->s)
		data->xrot -= 0.05;
	if (data->pressed->d)
		data->yrot += 0.05;
	if (data->pressed->q)
		data->zrot -= 0.05;
	if (data->pressed->e)
		data->zrot += 0.05;
	if (data->pressed->plus)
		data->scale += 0.05;
	if (data->pressed->minus)
		data->scale -= 0.05;
	redraw(data);
	return (0);
}

void		set_hooks(t_data *data)
{
	mlx_expose_hook(data->win, expose_hook, data);
	mlx_do_key_autorepeatoff(data->mlx);
	mlx_hook(data->win, 2, 0, key_hook_press, data);
	mlx_hook(data->win, 3, 0, key_hook_release, data);
	mlx_loop_hook(data->mlx, loop_hook, data);
}
