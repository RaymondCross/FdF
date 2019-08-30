/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:45:01 by rcross            #+#    #+#             */
/*   Updated: 2019/05/04 22:45:02 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		toggle_rotation(int keycode, t_data *data, int toggle)
{
	if (keycode == KEY_W)
		data->pressed->w = toggle;
	if (keycode == KEY_A)
		data->pressed->a = toggle;
	if (keycode == KEY_S)
		data->pressed->s = toggle;
	if (keycode == KEY_D)
		data->pressed->d = toggle;
	if (keycode == KEY_Q)
		data->pressed->q = toggle;
	if (keycode == KEY_E)
		data->pressed->e = toggle;
}

static void		toggle_translate(int keycode, t_data *data, int toggle)
{
	if (keycode == KEY_UP)
		data->pressed->up = toggle;
	if (keycode == KEY_DOWN)
		data->pressed->down = toggle;
	if (keycode == KEY_LEFT)
		data->pressed->left = toggle;
	if (keycode == KEY_RIGHT)
		data->pressed->right = toggle;
}

void			toggle_pressed(int keycode, t_data *data, int toggle)
{
	toggle_rotation(keycode, data, toggle);
	toggle_translate(keycode, data, toggle);
	if (keycode == KEY_PAD_ADD)
		data->pressed->plus = toggle;
	if (keycode == KEY_PAD_SUB)
		data->pressed->minus = toggle;
}
