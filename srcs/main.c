/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:52:16 by rcross            #+#    #+#             */
/*   Updated: 2019/05/04 22:52:17 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int				ft_usage(void)
{
	ft_putendl("usage: ./fdf [input file]");
	exit(0);
}

int				main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 2)
		ft_usage();
	if (!(data = malloc(sizeof(t_data))))
		ft_error("could not malloc data structure");
	if (!(data->map = malloc(sizeof(t_map))))
		ft_error("could not malloc map");
	check_file(&data, argv[1]);
	fdf(data);
	return (0);
}
