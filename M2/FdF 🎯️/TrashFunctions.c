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

void	iter2tab(t_tab *src, t_tab *dest, void (*f)(t_point*, t_point*))
{
	int	x;
	int	y;

	y = 0;
	while (y < (*src).height)
	{
		x = 0;
		while (x < (*src).width)
		{
			f(&(*src).tab[x][y], &(*dest).tab[x][y]);
			x++;
		}
		y++;
	}
}

void	free_tab(t_tab *t)
{
	int		x;

	while (x < (*t).width)
	{
		free(*(*t).tab);
		x++;
	}
	free((*t).tab);
}

void	link_points(t_data *img, t_tab tab)
{
	int	x;
	int	y;

	y = 0;
	while (y < tab.height)
	{
		x = 0;
		while (x < tab.width)
		{
			if (x + 1 < tab.width)
				draw_line(img, tab.tab[x][y], tab.tab[x + 1][y]);
			if (y + 1 < tab.height)
				draw_line(img, tab.tab[x][y], tab.tab[x][y + 1]);
			x++;
		}
		y++;
	}
}

t_tab	centermap(t_tab *tab, t_tablim t)
{
	int		gap;
	int 	yoffset;
	int		xoffset;
	int		x;
	int		y;

	yoffset = ((W_HEIGHT - 1) / 2) - ((t.ymax - t.ymin) / 2);
	xoffset = ((W_WIDTH - 1) / 2) - ((t.xmax - t.xmin) / 2);
	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			tab->tab[x][y].sy += yoffset;
			tab->tab[x][y].sx += xoffset;
			x++;
		}
		y++;
	}
	return (*tab);
}
