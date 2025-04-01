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

#ifndef PROTOTYPE_H
# define PROTOTYPE_H
# include "fdf.h"

// build_map_utils.c
void			**ft_realloc_tab(void **ptr, size_t old_size, size_t new_size);
int				count_columns(char *line);
char			read_map_file(t_tab *tab, const char *filename);
int				add_line_to_map(char ***lines, char *line, int height);
void			free_map_lines(char **lines, int height);

// build_map_utils2.c
/* Description */
void			iter2tab(t_tab *src, t_tab *dest, t_point (*f)(t_point));
int				adjust_coord(t_data *data);
void			autozoom(t_data *data);
t_tab			centermap(t_data *data);
void			enlargetab(t_data *data);

// build_map.c
char			build_map(const char *filename, t_tab *tab);
t_point			**allocate_map(int width, int height);
void			free_map(t_tab *tab);

// color_utils.c
t_rgb			itorgb(unsigned int color);
int				rgbtoi(t_rgb rgb);
t_rgb			gradient(t_line l);


// draw_line_utils.c
int				put_pixel(t_data *data, t_point p);

// draw_line.c
void			bresenham(t_data *img, t_line l);
void			draw_line(t_data *img, t_point start, t_point end);
void			draw_grid(t_data *data);

// fill_map.c
void			fill_map(t_point **tab, char **lines, int width, int height);
t_point			extract_point(char *value, int x, int y);
char			*extract_color(char *value);
char			*extract_z_value(char *value);
void			free_split(char **split_line);

// hooks.c
int				key_handler(int key, t_data *data);
int				rotate_key(int key, t_data *data);
int				translate_key(int key, t_data *data);
int				mouse_handler(int mousecode, int x, int y, t_data *data);

// rasterize.c
t_tab			rasterize(t_data *win);
void			getlim(t_tab *tab);
void			drawtabiso(t_data *data);
int				c_abs(int x);

// fdf.c
char			init_img(t_data *data);
char			init(t_data *data);

// tests.c
void			checktab(t_tab tab);

// window.c
int				close_window(t_data *data);

#endif
