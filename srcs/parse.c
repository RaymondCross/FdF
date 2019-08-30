/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:41:31 by rcross            #+#    #+#             */
/*   Updated: 2019/05/04 22:57:13 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** i[0] is the iterator until max width (x)
** i[1] is the position in the struct array (y)
** i[2] is number after atoi (z)
*/

static void	parse_points(t_data **data, int fd)
{
	char	*line;
	char	**points;
	int		i[3];

	(*data)->map->points = malloc(sizeof(t_vertex **) * (*data)->map->height);
	i[1] = 0;
	while (get_next_line(fd, &line))
	{
		points = ft_strsplit(line, ' ');
		(*data)->map->points[i[1]] = malloc(sizeof(t_vertex *)
										* (*data)->map->width);
		i[0] = -1;
		while (++i[0] < (*data)->map->width)
		{
			i[2] = ft_atoi(points[i[0]]);
			(*data)->map->points[i[1]][i[0]] = get_vertex(i[0], i[1], i[2]);
			(*data)->map->z_min = (*data)->map->z_min > i[2] ?
									i[2] : (*data)->map->z_min;
			(*data)->map->z_max = (*data)->map->z_max < i[2] ?
									i[2] : (*data)->map->z_max;
		}
		i[1]++;
		free(line);
		ft_mapdel(points);
	}
}

static void	ft_parse_file(t_data **data, int fd)
{
	char	*line;
	char	**points;
	int		width;

	width = 0;
	(*data)->map->height = 0;
	(*data)->map->width = 0;
	(*data)->map->z_min = 2147483647;
	(*data)->map->z_max = -2147483648;
	while (get_next_line(fd, &line))
	{
		points = ft_strsplit(line, ' ');
		width = 0;
		while (points[width])
			width++;
		if ((*data)->map->width != 0 && (*data)->map->width != width)
			ft_error("error: varying line width in file");
		(*data)->map->width = width;
		(*data)->map->height++;
		free(line);
		ft_mapdel(points);
	}
}

static int	safe_open(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("error: could not open file");
	return (fd);
}

void		check_file(t_data **data, char *file)
{
	int		fd;

	fd = safe_open(file);
	ft_parse_file(data, fd);
	fd = safe_open(file);
	parse_points(data, fd);
	close(fd);
}
