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

//séxecute au debut pendant le main 
t_bool so_start(int argc, char const **argv, t_so *so)
{
	t_solong 	solong;

	(void)argc;
	(void)so;
	(void)argv;
	(void)solong;

	solong.mlx = NULL;
	*so = so_init(solong.mlx, "solong", 60);
	return (FALSE);
}

t_bool callback_timer(t_so *so)
{
	(void)so;
	//so->target_frame = 300;
	return (FALSE);
}

//sexecute tout les 240htz (valeur max de boucle)
t_bool so_update(t_so *so)
{
	(void)so;
	t_so_chrono chrono;
	t_so_timer timer;

	chrono = so_chrono(so, chrono);
	timer = so_timer(so, timer, 20000, callback_timer);
	printf("Update : %d -- Render : %d -- renderframe -- renderframe : %d || %02d:%02d:%02d:%04d stop : %d\n", so->so_update.fps, so->so_render.fps, so->so_render.frame, chrono.hours, chrono.minutes, chrono.seconds, chrono.milliseconde, chrono.stop);
	if (so->so_render.frame == 500)
		chrono.stop = TRUE;
	if (so->so_render.frame == 1000)
		chrono.restart = TRUE;
	return (FALSE);
}

//séxecute en fonction du nombre de fps voulu dans init
t_bool so_render(t_so *so)
{
	(void)so;
	//printf("Update : %d -- Render : %d -- renderframe -- renderframe : %d\n", so->so_update.fps, so->so_render.fps, so->so_render.frame);
	return (FALSE);
}