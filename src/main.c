/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:00:14 by marvin            #+#    #+#             */
/*   Updated: 2024/03/15 20:19:26 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "../libs/solib/solib_init/solib_init.h"

int key_test(t_solib *solib, int keycode)
{
	if (keycode == 65307)
		solib->close(solib);
	return (0);
}

int solib_start(t_solib *solib)
{
	solib->events->key_press = key_test;

	t_solib_display *display = solib->new->display(solib,
						solib->new->construct(solib, "display", "171717", FALSE));

	t_solib_canvas *canva = solib->new->canvas(solib,
		solib->new->construct(solib,
			"canva1", "2122121", TRUE),
		solib->new->transform(solib,
			solib->new->vector2(solib, 0, 0),
			solib->new->size(solib, 1920, 1080)));

	(void)display;
	(void)canva;
	return (0);
}

int solib_update(t_solib *solib)
{
	(void)solib;
	/*printf("fpsupdate : %d -- fpsrender : %d -- ms : %0.3f\n",
		solib->time->update.fps, solib->time->render.fps,
		solib->time->ticks.millis);*/
	return (0);
}

int solib_render(t_solib *solib)
{
	(void)solib;
	return (0);
}

int	main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	//solib = solib_init("solong",1905, 1050, 60);
	//if (solib_init("solong", 1905, 675, 60))
	if (solib_init("solong", 1905, 675, 60))
		return (1);
	return (0);
}