/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "fdf.h"

// build_map_utils.c
void		**ft_realloc_tab(void **ptr, size_t old_size, size_t new_size);
int			count_columns(char *line);
char		**read_map_file(const char *filename, int *width, int *height);
int			add_line_to_map(char ***lines, char *line, int height);
void		free_map_lines(char **lines, int height);

// build_map.c
t_tab		build_map(const char *filename);
t_point		**allocate_map(int width, int height);
void		free_map(t_tab *map);

// close_window.c
void		free_resources(t_data *data);
int			key_hook(int keycode, t_data *data);
int			close_window(t_data *data);

// colors.c
t_rgba		itorgb(unsigned int color);
int			rgbtoi(t_rgba rgb);
t_rgba		gradient(t_line l);

// draw_line.c
void		bresenham(t_data *img, t_line l);
void		draw_line(t_data *img, t_point start, t_point end);
void		draw_grid(t_data *img, t_tab grid);

// fdf.c
int			main(int argc, char **argv);

// fill_map.c
void		fill_map(t_point **map, char **lines, int width, int height);
t_point		extract_point(char *value, int x, int y);
char		*extract_color(char *value);
char		*extract_z_value(char *value);
void		free_split(char **split_line);

// rasterize.c
t_tab		rasterize(t_tab *tab);
t_tablim	getlim(t_tab *tab);
void		autozoom(t_tab *tab, t_tablim t);
t_tab		centermap(t_tab *tab, t_tablim t);
void		enlargetab(t_tab *tab);
void		drawtabiso(t_data *img, t_tab tab);

// test.c
void		tabvalues(t_tab *tab);
void		initfaketab(t_tab *t);
void		checktab(t_tab tab);

// utils.c
int			put_pixel(t_data *data, t_point p);
void		swap(void **ptr1, void **ptr2);
int			c_abs(int x);
void		iter2tab(t_tab *src, t_tab *dest, t_point (*f)(t_point));
t_point		cartesian_to_screen(t_point point);
void		*ft_memset(void *b, int c, size_t len);
void		init(t_data *img);

#endif
