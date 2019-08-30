/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:53:27 by rcross            #+#    #+#             */
/*   Updated: 2019/05/04 22:53:28 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		reset(t_data *data)
{
	data->xtrans = 0.0;
	data->ytrans = 0.0;
	data->xrot = 0.0;
	data->yrot = 0.0;
	data->zrot = 0.0;
	data->scale = 0.5;
}

void		key_hook_translation(t_data *data)
{
	if (data->pressed->up)
		data->ytrans -= 5;
	if (data->pressed->down)
		data->ytrans += 5;
	if (data->pressed->left)
		data->xtrans -= 5;
	if (data->pressed->right)
		data->xtrans += 5;
}
