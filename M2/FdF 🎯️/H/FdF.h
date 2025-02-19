/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../mlx_linux/mlx.h"

typedef struct s_line
{
	int i;
	int	len;
}	t_line;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

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

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef	struct s_inputs
{
	size_t	win_x;
	size_t	win_y;
}	t_inputs;

unsigned int	ft_hsl(int h, int s, int l);

int	close_window(t_data *data);
int	key_hook(int keycode, t_data *data);

int	main(void);