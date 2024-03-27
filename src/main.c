/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:00:14 by marvin            #+#    #+#             */
/*   Updated: 2024/03/20 15:48:00 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int key_test(t_solib *solib, int keycode)
{
	if (keycode == 65307)
		solib->close(solib);
	return (0);
}

int start(t_solib *solib, void *env)
{
	printf("hey\n");
	(void)env;
	solib->events->key_press = key_test;

	t_solib_display *display = solib->new->display(solib,
						solib->new->construct(solib, "display", "171717", FALSE));

	t_solib_canvas *canva = solib->new->canvas(solib,
		solib->new->construct(solib,
			"canva1", "212121", TRUE),
		solib->new->transform(solib,
			solib->new->vector2(solib, 0, 0),
			solib->new->size(solib, 1920, 1080)));

	display->canvas = canva;
	(void)display;
	(void)canva;
	return (0);
}

int update(t_solib *solib, void *env)
{
	(void)env;
	(void)solib;
	/*printf("fpsupdate : %d -- fpsrender : %d -- ms : %0.3f\n",
		solib->time->update.fps, solib->time->render.fps,
		solib->time->ticks.millis);*/
	return (0);
}

t_environement	*environement_init()
{
	t_environement *env;

	env = malloc(sizeof(t_environement));
	env->x = 15;
	env->y = 10;
	env->mavalue = 60;
	return (env);
}


//solib = solib_init("solong",1905, 1050, 60);
//if (solib_init("solong", 1905, 675, 60))
int	main(int argc, char const **argv)
{
	(void)argc;
	(void)argv;

	t_environement *env;

	env = environement_init(argc, argv);
	(void)env;
	t_solib	*solib = sonew();
	(void)solib;
	int error = solib->start(
		solib,
		solib->new->construct(solib, "solong", NULL, TRUE),
		solib->new->vector2(solib, 1905, 675),
		solib->new->so(solib, env, start, update)
	);
	if (error)
		return (1);
	return (0);
}