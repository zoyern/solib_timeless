/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_canvas_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 03:12:29 by marvin            #+#    #+#             */
/*   Updated: 2024/03/10 03:12:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solib_types/solib_types.h"

void	solib_windows_init(t_solib *solib, char *name, int width, int height)
{
	t_solib_windows	*windows;

	windows = (t_solib_windows *)solib_malloc(solib, sizeof(t_solib_windows));
	windows->name = name;
	solib_windows_init_size(solib, width, height);
	windows->width = width;
	windows->height = height;
	windows->ratio = 0;
	windows->window = mlx_new_window(solib->minilibx, width, height, name);
	if (!windows->window)
		solib->close(solib);
	solib->windows = windows;
}

t_solib_canvas	solib_canvas_init(t_solib *solib, char *name, char *background)
{
	
}
