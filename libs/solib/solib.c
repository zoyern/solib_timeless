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

int solib_loop(t_solib *solib)
{
	solib_ticks(&solib->time->ticks);
	solib->time->update = solib_clock(
		solib, &solib->time->update, fps_to_ms(240), solib_update);
	solib->time->render = solib_clock(
		solib, &solib->time->render, fps_to_ms(solib->target_frame), solib_render);
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
	solib_windows_init(solib, name, width, height);
	solib_inputs_init(solib);
	solib_events_init(solib);
	solib_new_init(solib);
	solib_time_init(solib, SIMUL_MHZ, 240, target_frame);
	solib->close = solib_close;
	solib_hooks(solib);
	if (solib_start(solib))
		solib_close(solib);
	//solib_free(solib, solib->inputs);
	//solib_memory_show(solib);

	t_solib_image	*bg;
	t_solib_image *ring;
	t_solib_display *display = solib2d(solib, 1920, 1080);
	
	(void)display;
	t_solib_canvas	*canva = solib->new->canvas(
		solib->display,
		solib->new->construct(solib, "menu", "test.xpm"),
		solib->new->transform(
			solib,
			solib->new->vector2(solib, 0,0),
			solib->new->size(solib, display->size->width, display->size->height),
			solib->new->quate(solib, 0, 0, 0)));

	t_solib_image *image1 = solib->new->image(
    canva,
    solib->new->construct(solib, "image1", "ring.xpm"),
    solib->new->transform(
		solib,
        solib->new->vector2(solib, 0, 0),
        solib->new->size(solib, 50, 50),
        solib->new->quate(solib, 0, 0, 0)));

	/*image1->set->transform(
		image1,
		solib->new.transform(
			solib,
			solib->new.vector2(solib, 0,0),
			solib->new.size(solib, display->size.width, display->size.height),
			solib->new.quate(solib, 0, 0, 0)));*/
			
	//canva->images->set(canva, image1);

	(void)image1;

	bg = new_file_img("test.xpm", solib);
	if (!bg->data->img_ptr)
		return (2);
	//scale avec la taille de la fenetre si la fenetre augmente la taille augmente aussi 
	put_img_to_img(solib, solib->display->area, bg, 0, 0, solib->display->resolution->x, solib->display->resolution->y);
	ring = new_file_img("ring.xpm", solib);
	if (!ring->data->img_ptr)
		return (2);
	//scale avec la taille de la fenetre si la fenetre augmente la taille reste a la meme resolution sur la grille
	put_img_to_img(solib, solib->display->area, ring, 0 , 0, 50, 50);
	mlx_put_image_to_window(solib->minilibx, solib->windows->window, solib->display->area->data->img_ptr, solib->display->area->pos->x, solib->display->area->pos->y);
	solib_memory_show(solib);
	mlx_loop_hook(solib->minilibx, solib_loop, solib);
	mlx_loop(solib->minilibx);
	solib_close(solib);
	return (FALSE);
}