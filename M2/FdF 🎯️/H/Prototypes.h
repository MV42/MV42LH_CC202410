#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "FdF.h"

// CloseWindow.c
int		close_window(t_data *data);
int		key_hook(int keycode, t_data *data);

// Colors.c
t_rgba	itorgb(unsigned int color);
int		rgbtoi(t_rgba rgb);

// DrawLine.c
void	draw_line(t_data *img, t_point start, t_point end);

// FdF.c

// Main.c

#endif