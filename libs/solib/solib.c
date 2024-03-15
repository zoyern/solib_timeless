/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:43:15 by marvin            #+#    #+#             */
/*   Updated: 2024/03/11 13:18:22 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib.h"
#include "solib_utils.h"
#include "solib_hooks/solib_hooks.h"
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
	solib_update(solib);
	return (0);
}

int	solib_render_callback(t_solib *solib)
{
	mlx_clear_window(solib->minilibx, solib->windows->window);
	solib_render(solib);
	printf("\n\n\n\n----------------------------------------------\n\n\n\n");
	solib_put_image(solib->display->area, solib->display->current->background,
		solib->new->transform(
			solib,
			solib->display->current->background->pos,
			solib->display->current->background->size,
			solib->display->current->background->quate
	));
	mlx_put_image_to_window(
		solib->minilibx, solib->windows->window,
		solib->display->area->data->img_ptr,
		solib->display->area->pos->x,
		solib->display->area->pos->y);
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

t_bool solib_init(char *name, int width, int height, int target_frame)
{
	t_solib *solib;

	solib = (t_solib *)malloc(sizeof(t_solib));
	if (!solib)
		return (TRUE);
	solib_memory_init(solib);
	solib->minilibx = mlx_init();
	if (!solib->minilibx)
		return (solib_close(solib));
	solib->target_frame = target_frame;
	solib_new_init(solib);
	solib_windows_init(solib, name, width, height);
	solib_inputs_init(solib);
	solib_events_init(solib);
	solib_time_init(solib, SIMUL_MHZ, 240, target_frame);
	solib->close = solib_close;
	solib_hooks(solib);
	if (solib_start(solib))
		solib_close(solib);
	//solib_free(solib, solib->inputs);
	//solib_memory_show(solib);

	//solib_memory_show(solib);
	mlx_loop_hook(solib->minilibx, solib_loop, solib);
	mlx_loop(solib->minilibx);
	solib_close(solib);
	return (FALSE);
}