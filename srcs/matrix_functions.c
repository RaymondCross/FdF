/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:38:22 by rcross            #+#    #+#             */
/*   Updated: 2019/05/04 22:38:24 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	matrix_bzero(float mat[4][4])
{
	ft_bzero(mat[0], sizeof(float) * 4);
	ft_bzero(mat[1], sizeof(float) * 4);
	ft_bzero(mat[2], sizeof(float) * 4);
	ft_bzero(mat[3], sizeof(float) * 4);
}

void	get_id_matrix(float mat[4][4])
{
	matrix_bzero(mat);
	mat[0][0] = 1;
	mat[1][1] = 1;
	mat[2][2] = 1;
	mat[3][3] = 1;
}

void	matrix_translate(float mat[4][4], float x, float y, float z)
{
	float	tran_mat[4][4];

	get_id_matrix(tran_mat);
	tran_mat[3][0] = x;
	tran_mat[3][1] = y;
	tran_mat[3][2] = z;
	matrix_multiply(mat, tran_mat, mat);
}

void	matrix_scale(float mat[4][4], float x, float y, float z)
{
	float	scale_mat[4][4];

	matrix_bzero(scale_mat);
	scale_mat[0][0] = x;
	scale_mat[1][1] = y;
	scale_mat[2][2] = z;
	scale_mat[3][3] = 1;
	matrix_multiply(mat, scale_mat, mat);
}

void	matrix_rotate(float mat[4][4], float xrot,
						float yrot, float zrot)
{
	float rotx[4][4];
	float roty[4][4];
	float rotz[4][4];
	float mat1[4][4];
	float mat2[4][4];

	get_id_matrix(rotx);
	get_id_matrix(roty);
	get_id_matrix(rotz);
	rotx[1][1] = cos(xrot);
	rotx[1][2] = sin(xrot);
	rotx[2][1] = -sin(xrot);
	rotx[2][2] = cos(xrot);
	roty[0][0] = cos(yrot);
	roty[0][2] = -sin(yrot);
	roty[2][0] = sin(yrot);
	roty[2][2] = cos(yrot);
	rotz[0][0] = cos(zrot);
	rotz[0][1] = sin(zrot);
	rotz[1][0] = -sin(zrot);
	rotz[1][1] = cos(zrot);
	matrix_multiply(mat, roty, mat1);
	matrix_multiply(mat1, rotx, mat2);
	matrix_multiply(mat2, rotz, mat);
}
