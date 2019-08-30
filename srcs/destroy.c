/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:44:56 by rcross            #+#    #+#             */
/*   Updated: 2019/05/04 22:44:57 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	destroy_everything(t_data **data)
{
	int i;

	i = -1;
	free((*data)->colors);
	free((*data)->pressed);
	destroy_map((*data)->map);
	free((*data)->map);
}

void	destroy_map(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			free(map->points[i][j]->local);
			free(map->points[i][j]->world);
			free(map->points[i][j]->aligned);
			free(map->points[i][j]);
		}
		free(map->points[i]);
	}
	free(map->points);
}
