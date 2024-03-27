/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:43:15 by marvin            #+#    #+#             */
/*   Updated: 2024/03/15 20:18:17 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_init/solib_init.h"

int solib_close(t_solib *solib)
{
	if (solib)
	{
		if (solib->windows)
		{
			if (solib->windows->window)
				mlx_destroy_window(solib->minilibx, solib->windows->window);
		}
		if (solib->minilibx)
		{
			mlx_destroy_display(solib->minilibx);
			free(solib->minilibx);
		}
		if (solib->memory)
			solib_memory_clear(solib);
		free(solib);
	}
	exit(0);
}

int	solib_update_callback(t_solib *solib)
{
	if (solib->func->upate)
		solib->func->upate(solib, solib->environement);
	return (0);
}

int	solib_render_callback(t_solib *solib)
{
	mlx_put_image_to_window(solib->minilibx, solib->windows->window, solib->display->area->data->ptr, 0, 0);
	mlx_put_image_to_window(solib->minilibx, solib->windows->window, solib->display->area->data->ptr, 0, 0);
	return (0);
}

int solib_loop(t_solib *solib)
{
	solib_ticks(&solib->time->ticks);
	solib->time->update = solib_clock(
		solib, &solib->time->update, fps_to_ms(240), solib_update_callback);
	solib->time->render = solib_clock(
		solib, &solib->time->render, fps_to_ms(solib->target_frame), solib_render_callback);
	return (0);
}

int solib_start(t_solib *solib, t_solib_construct *construct, t_solib_vector2 *vector2, t_solib_funcs *init)
{
	solib->minilibx = mlx_init();
	if (!solib->minilibx)
		return (solib_close(solib));
	solib->target_frame = 60;
	solib_funcs_init(solib, init); 
	solib_windows_init(solib, construct->name, vector2->x, vector2->y);
	solib_inputs_init(solib);
	solib_events_init(solib);
	solib_time_init(solib, SIMUL_MHZ, 240, solib->target_frame);
	solib->close = solib_close;
	solib_hooks(solib);
	if (solib->func->start(solib, solib->environement))
		solib->close(solib);
	mlx_loop_hook(solib->minilibx, solib_loop, solib);
	mlx_loop(solib->minilibx);
	solib_close(solib);
	return (0);
}

t_solib *sonew(void)
{
	t_solib *solib;

	solib = (t_solib *)malloc(sizeof(t_solib));
	if (!solib)
		return (NULL);
	solib_memory_init(solib);
	solib_new_init(solib);
	solib->close = solib_close;
	solib->start = solib_start;
	solib->malloc = solib_malloc;
	solib->free = solib_free;
	return (solib);
}
