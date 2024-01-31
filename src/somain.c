/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 04:54:45 by marvin            #+#    #+#             */
/*   Updated: 2024/01/29 04:54:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mysolonglib.h"

t_bool callback_timer(t_so *so, void *so_env)
{
	(void)so;
	(void)so_env;
	so->target_frame = 300;
	return (FALSE);
}

//sexecute tout les 240htz (valeur max de boucle)
t_bool so_update(t_so *so, t_solong *so_env)
{
	(void)so;
	(void)so_env;
	//printf("update :%d\n", so_env->test);
	//t_so_chrono chrono;
	//t_so_timer timer;
	//printf("Update : %d -- Render : %d -- renderframe : %d -- test : %d\n", so->so_update.fps, so->so_render.fps, so->so_render.frame, so_env->test);
	//chrono = so_chrono(so, chrono);
	//printf("hey : %d\n", chrono.stop);
	//timer = so_timer(so, timer, 20000, callback_timer);
	//printf("Update : %d -- Render : %d -- updateframe %d-- renderframe : %d|| %02d:%02d:%02d:%04d stop : %d -- test : %d\n", so->so_update.fps, so->so_render.fps, so->so_update.frame, so->so_render.frame, chrono.hours, chrono.minutes, chrono.seconds, chrono.milliseconde, chrono.stop, so_env->test);
	if (so->so_render.frame == 500)
	{
		//chrono.stop = TRUE;
		so_env->test = 10;
	}
	if (so->so_render.frame == 1000)
	{
		//chrono.restart = TRUE;
		so_env->test = 20;
	}
	//printf("Update : %d -- Render : %d -- renderframe : %d -- test : %d\n", so->so_update.fps, so->so_render.fps, so->so_render.frame, so_env->test);
	return (FALSE);
}



//séxecute en fonction du nombre de fps voulu dans init
t_bool so_render(t_so *so, t_solong *so_env)
{
	(void)so;
	(void)so_env;
	//printf("render :%p\n", so_env);
	//printf("Update : %d -- Render : %d -- renderframe : %d -- test : %d\n", so->so_update.fps, so->so_render.fps, so->so_render.frame, so_env->test);
	return (FALSE);
}

//séxecute au debut pendant le main 
t_bool so_start(int argc, char const **argv, t_so *so)
{
	t_solong 	solong;

	(void)argc;
	(void)so;
	(void)argv;

	solong.mlx = NULL;
	solong.test = 2;
	so = so_init(solong.mlx, solong.win, so_update, so_render, &solong, "solong", 60);
	printf("HHHHHHHHBBBBBBBBBBBBBBBBBBBBB :%p\n", so->so_env);
	printf("start :%p\n", &so->so_env->test);
	printf("start :%d\n", so->so_env->test);
	return (FALSE);
}