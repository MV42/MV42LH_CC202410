/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "fdf.h"

typedef struct s_rgb
{
	float		r;
	float		g;
	float		b;
}				t_rgb;

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	t_rgb		color;
	int			sx;
	int			sy;
}				t_point;

typedef struct s_tablim
{
	int			xmin;
	int			xmax;
	int			ymin;
	int			ymax;
}				t_tablim;

typedef struct s_mat4
{
	float		m[4][4];
}				t_mat4;

typedef struct s_tab
{
	t_point		**tab;
	char		**lines;
	int			width;
	int			height;
	t_tablim	lim;
	t_mat4		mtrx;
}				t_tab;

typedef struct s_line
{
	t_point		start;
	t_point		index;
	t_point		end;
	t_point		d;
}				t_line;

typedef struct s_image
{
	void		*img_ptr;
	char		*px_ptr;
	int			bits_pp;
	int			line_len;
	int			endian;
}				t_image;

typedef struct s_input
{
	float		rot_x;
	float		rot_y;
	float		rot_z;
	float		zoom;
	char		zoom_bool;
	float		h_factr;
	int			pos_x;
	int			pos_y;
}				t_input;


typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_tab		tab;
	t_input		in;
}				t_data;

typedef struct s_pmath
{
	float		cos_rx;
	float		sin_rx;
	float		cos_ry;
	float		sin_ry;
	float		cos_rz;
	float		sin_rz;
}				t_pmath;

#endif
