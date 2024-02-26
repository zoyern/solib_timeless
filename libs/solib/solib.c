/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:43:15 by marvin            #+#    #+#             */
/*   Updated: 2024/02/08 17:43:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib.h"
#include "solib_hooks/solib_hooks.h"
#include "./solib_init/solib_init.h"

int solib_close(t_solib *solib)
{
	if (solib)
	{
		free(solib->events);
		free(solib->time);
		free(solib->inputs);
		if (solib->windows)
		{
			if (solib->windows->window)
				mlx_destroy_window(solib->minilibx, solib->windows->window);
			free(solib->windows);
		}

		if (solib->minilibx)
		{
			mlx_destroy_display(solib->minilibx);
			free(solib->minilibx);
		}
		free(solib);
	}
	exit(1);
}

int solib_loop(t_solib *solib)
{
	solib_ticks(&solib->time->ticks, &solib->time->ticks.cycles_state);
	solib->time->update = solib_clock(solib, &solib->time->update, fps_to_ms(240), solib_update);
	solib->time->render = solib_clock(solib, &solib->time->render, fps_to_ms(solib->windows->target_frame), solib_render);
	return (0);
}

t_bool solib_init(char *name, int width, int height, int target_frame)
{
	t_solib *solib;

	solib = (t_solib *)malloc(sizeof(t_solib));
	if (!solib)
		return (TRUE);

	solib->minilibx = mlx_init();
	if (!solib->minilibx)
		return (free(solib), TRUE);

	if (solib_windows_init(solib, name, width, height, target_frame))
		return (TRUE);
	if (solib_inputs_init(solib))
		return (TRUE);
	if (solib_events_init(solib))
		return (TRUE);
	if (solib_time_init(solib, 3000, 240, target_frame))
		return (TRUE);
	solib->close = solib_close;
	mlx_hook(solib->windows->window, 17, 1L << 0, &solib_close, solib);
	solib_hooks(solib);

	solib_start(solib);
	mlx_loop_hook(solib->minilibx, solib_loop, solib);
	mlx_loop(solib->minilibx);
	solib_close(solib);
	return (FALSE);
}