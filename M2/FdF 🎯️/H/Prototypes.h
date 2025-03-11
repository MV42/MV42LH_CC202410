/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "FdF.h"

// CloseWindow.c
void		free_resources(t_data *data);
int			key_hook(int keycode, t_data *data);
int			close_window(t_data *data);

// Colors.c
t_rgba		itorgb(unsigned int color);
int			rgbtoi(t_rgba rgb);
t_rgba		gradient(t_line l);

// DrawLine.c
void		bresenham(t_data *img, t_line l);
void		draw_line(t_data *img, t_point start, t_point end);
void		draw_grid(t_data *img, t_tab *grid);

// FdF.c

// Main.c
void		init(t_data *img);
int			main(void);

// Rasterize.c
void		ft_matrix_identity(t_matrix4x4 *m);
void		ft_setup_isometric_view(t_matrix4x4 *m);
void		ft_transform_point(t_point *src, t_point *dest);

// ReadMap.c
t_point		**allocate_tab(int width, int height);

// Test.c
void		tabvalues(t_tab *tab);
void		initfaketab(t_tab *t);

// Utils.c
int			put_pixel(t_data *data, t_point p);
void		swap(void **ptr1, void **ptr2);
int			c_abs(int x);
void		link_points(t_data *img, t_tab tab);
void		*ft_calloc(size_t size);

#endif