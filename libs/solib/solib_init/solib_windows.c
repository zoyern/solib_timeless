/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:07:34 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 08:34:28 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_init.h"

void	solib_windows_init_size(t_solib *solib, int width, int height)
{
	int				_width;
	int				_height;

	_width = 0;
	height = 0;
	if (width >= 1 && height >= 1)
		return ;
	mlx_get_screen_size(solib->minilibx, &_width, &_height);
	if (width < 1)
		width = _width;
	if (height < 1)
		height = _height;
}

void	solib_windows_init(t_solib *solib, char *name, int width, int height)
{
	t_solib_windows	*windows;

	windows = (t_solib_windows *)solib_malloc(solib, sizeof(t_solib_windows));
	windows->name = name;
	solib_windows_init_size(solib, width, height);
	windows->width = width;
	windows->height = height;
	windows->window = mlx_new_window(solib->minilibx, width, height, name);
	if (!windows->window)
		solib->close(solib);
	solib->windows = windows;
}
