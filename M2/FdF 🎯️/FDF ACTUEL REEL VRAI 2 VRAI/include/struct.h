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

typedef struct s_tab
{
	t_point		**tab;
	char		**lines;
	int			width;
	int			height;
	double		scale;
}				t_tab;

typedef struct s_line
{
	t_point		start;
	t_point		index;
	t_point		end;
	t_point		d;
}				t_line;

typedef struct s_tablim
{
	int			xmin;
	int			xmax;
	int			ymin;
	int			ymax;
}				t_tablim;

typedef struct s_image
{
	void		*img_ptr;
	char		*px_ptr;
	int			bits_pp;
	int			line_len;
	int			endian;
}				t_image;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_tab		*map;
	int			win_width;
    int			win_height;
}				t_data;

typedef struct s_inputs
{
	int			rot_x;
	int			rot_y;
	int			rot_z;
	int			zoom;
	int			pos_x;
	int			pos_y;
}				t_inputs;

#endif
