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

// alloc_tab.c
t_point			**allocate_map(int width, int height);
void			free_map(t_tab *tab);
void			**ft_realloc_tab(void **ptr, size_t old_size, size_t new_size);

// build_tab_utils.c
int				count_columns(char *line);
char			read_map_file(t_tab *tab, const char *filename);
int				add_line_to_map(char ***lines, char *line, int height);
void			free_map_lines(char **lines, int height);

// build_tab.c
char			build_tab(const char *filename, t_tab *tab);

// color_utils.c
t_rgb			itorgb(unsigned int color);
int				rgbtoi(t_rgb rgb);
t_rgb			gradient(t_line l);

// draw_map_utils.c
int				adjust_coord(t_data *data);
t_tab			centermap(t_data *data);
void			enlargetab(t_data *data);
void			restoretab(t_data *data);

// draw_map.c
int				put_pixel(t_data *data, t_point p);
void			bresenham(t_data *data, t_line l);
void			draw_line(t_data *data, t_point start, t_point end);
void			draw_grid(t_data *data);

// fdf.c
char			init_img(t_data *data);
char			init(t_data *data);
int				main(int argc, char **argv);

// fill_tab.c
void			fill_map(t_point **tab, char **lines, int width, int height);
t_point			extract_point(char *value, int x, int y);
char			*extract_color(char *value);
char			*extract_z_value(char *value);
void			free_split(char **split_line);

// hooks.c
int				key_handler(int key, t_data *data);
int				rotate_hook(int key, t_data *data);
int				translate_hook(int key, t_data *data);
int				height_hook(int key, t_data *data);
int				zoom_hook(int key, t_data *data);

// rasterize.c
void			init_matrix(t_data *data, t_mat4 *m);
void			apply_mat4(t_point *p, t_mat4 *m);
t_tab			rasterize(t_data *data);
void			getlim(t_tab *tab);
void			drawtabiso(t_data *data);

// window.c
int				close_window(t_data *data);

// zoom.c
void			getscale(t_data *data);
void			mapzoom(t_data *data);

#endif
