/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavander <mavander@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:42:42 by mavander          #+#    #+#             */
/*   Updated: 2024/12/21 21:42:42 by mavander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stddef.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <X11/Xlib.h>

# include <stdio.h>

# include "mlx_int.h"
# include "mlx.h"

# include "libft.h"

# include "struct.h"
# include "prototype.h"

# define W_WIDTH 1800
# define W_HEIGHT 900

# define ERR_FILE "Error: File \"%s\" Couldn't Be Opened\n"
# define ERR_ARGC "Error: Wrong Argument Count ! Need 2, Got %i.\n"

#endif
