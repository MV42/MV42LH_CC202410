/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "FdF.h"

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
}	t_data;

typedef struct s_rgba
{
	float		r;
	float		g;
	float		b;
	float		a;
}	t_rgba;

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	t_rgba		color;
	int			sx;
	int			sy;
}	t_point;

typedef struct s_tab
{
	t_point		**tab;
	char		**lines;
	int			width;
	int			height;
	double		scale;
}	t_tab;

typedef struct s_line
{
	t_point		start;
	t_point		index;
	t_point		end;
	t_point		d;
}	t_line;

typedef struct s_tablim
{
	int	xmin;
	int	xmax;
	int	ymin;
	int	ymax;
}	t_tablim;

#endif
