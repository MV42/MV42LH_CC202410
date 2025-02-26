#ifndef STRUCTS_H
# define STRUCTS_H
# include "FdF.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
}	t_data;

typedef struct s_rgba
{
	size_t	r;
	size_t	g;
	size_t	b;
	size_t	a;
}	t_rgba;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	float		s;
	t_rgba		color;
}	t_point;

typedef struct s_line
{
	t_point	start;
	t_point index;
	t_point	end;
	t_point d;
}	t_line;

#endif