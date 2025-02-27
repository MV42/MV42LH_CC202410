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
int			close_window(t_data *data);
int			key_hook(int keycode, t_data *data);

// Colors.c
t_rgba		itorgb(unsigned int color);
int			rgbtoi(t_rgba rgb);
t_rgba		gradient(t_line l);

// DrawLine.c
void		draw_line(t_data *img, t_point start, t_point end);
int			c_abs(int x);

// FdF.c

// Main.c

#endif