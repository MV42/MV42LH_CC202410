# define W_WIDTH 1800
# define W_HEIGHT 900

typedef struct s_rgba
{
	float	r;
	float	g;
	float	b;
	float	a;
}	t_rgba;

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	t_rgba		color;
}	t_point;

typedef struct s_tab
{
	t_point **tab;
	int		width;
	int		height;
}	t_tab;

typedef struct s_matrix
{
	float	m[4][4];
}	t_matrix;

t_matrix	ft_init_transform_matrix(t_tab *grid)
{
	t_matrix	matrix;
	float		scale;
	float		max_dim;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix.m[i][j] = 0;
			j++;
		}
		i++;
	}
	matrix.m[0][0] = 0.866;
	matrix.m[0][1] = 0.5;
	matrix.m[0][2] = 0;
	matrix.m[1][0] = -0.354;
	matrix.m[1][1] = 0.612;
	matrix.m[1][2] = 0.707;
	matrix.m[2][0] = 0.354;
	matrix.m[2][1] = -0.612;
	matrix.m[2][2] = 0.707;
	matrix.m[0][3] = W_WIDTH / 2;
	matrix.m[1][3] = W_HEIGHT / 2;
	matrix.m[2][3] = 0;
	max_dim = grid->width > grid->height ? grid->width : grid->height;
	scale = (W_WIDTH < W_HEIGHT ? W_WIDTH : W_HEIGHT) * 0.8 / max_dim;
	matrix.m[0][0] *= scale;
	matrix.m[0][1] *= scale;
	matrix.m[1][0] *= scale;
	matrix.m[1][1] *= scale;
	matrix.m[1][2] *= scale;
	matrix.m[2][0] *= scale;
	matrix.m[2][1] *= scale;
	matrix.m[2][2] *= scale;
	matrix.m[3][3] = 1;
	return (matrix);
}

void	ft_transform_point(t_tab *grid, t_point *src, t_point *dst)
{
	static t_matrix	matrix;
	static int		initialized = 0;
	
	if (!initialized)
	{
		matrix = ft_init_transform_matrix(grid);
		initialized = 1;
	}
	dst->x = matrix.m[0][0] * src->x + matrix.m[0][1] * src->y 
		+ matrix.m[0][2] * src->z + matrix.m[0][3];
	dst->y = matrix.m[1][0] * src->x + matrix.m[1][1] * src->y 
		+ matrix.m[1][2] * src->z + matrix.m[1][3];
	dst->z = matrix.m[2][0] * src->x + matrix.m[2][1] * src->y 
		+ matrix.m[2][2] * src->z + matrix.m[2][3];
	dst->color = src->color;
}

void	draw_grid(t_data *img, t_tab *grid)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	y = 0;
	while (y < grid->height)
	{
		x = 0;
		while (x < grid->width)
		{
			ft_transform_point(grid, &grid->tab[x][y], &p1);
			if (x < grid->width - 1)
			{
				ft_transform_point(grid, &grid->tab[x + 1][y], &p2);
				draw_line(img, p1, p2);
			}
			if (y < grid->height - 1)
			{
				ft_transform_point(grid, &grid->tab[x][y + 1], &p2);
				draw_line(img, p1, p2);
			}
			x++;
		}
		y++;
	}
}
