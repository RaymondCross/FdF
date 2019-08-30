/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:39:27 by rcross            #+#    #+#             */
/*   Updated: 2019/05/04 22:50:25 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_3dpoint		*get_3dpoint(float x, float y, float z)
{
	t_3dpoint	*out;

	out = malloc(sizeof(t_3dpoint));
	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
}

t_vertex		*get_vertex(float x, float y, float z)
{
	t_vertex	*out;

	out = malloc(sizeof(t_vertex));
	out->local = get_3dpoint(x, y, z);
	out->world = get_3dpoint(0, 0, 0);
	out->aligned = get_3dpoint(0, 0, 0);
	return (out);
}

void			matrix_multiply(float m1[4][4], float m2[4][4], float dst[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			dst[i][j] = m1[i][0] * m2[0][j] +
						m1[i][1] * m2[1][j] +
						m1[i][2] * m2[2][j] +
						m1[i][3] * m2[3][j];
	}
}

void			matrix_vector_multiply(t_3dpoint *src, float mat[4][4],
														t_3dpoint *dst)
{
	float	x;
	float	y;
	float	z;

	x = src->x * mat[0][0] +
		src->y * mat[1][0] +
		src->z * mat[2][0] +
		mat[3][0];
	y = src->x * mat[0][1] +
		src->y * mat[1][1] +
		src->z * mat[2][1] +
		mat[3][1];
	z = src->x * mat[0][2] +
		src->y * mat[1][2] +
		src->z * mat[2][2] +
		mat[3][2];
	dst->x = x;
	dst->y = y;
	dst->z = z;
}
