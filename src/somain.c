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
t_bool so_setup(int argc, char const **argv, t_so *so)
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

//séxecute frame 1 de Update 
t_bool so_start(t_so *so)
{
	(void)so;
	return (FALSE);
}

t_bool testeee(t_so *so)
{
	(void)so;
	printf("hello\n");
	return (FALSE);
}

//sexecute tout les 240htz (valeur max de boucle)
t_bool so_update(t_so *so)
{
	(void)so;
	//so_close(so, FALSE);
	//printf("Update : %d -- Render : %d\n", so->so_update.fps, so->so_render.fps);
	return (FALSE);
}

//séxecute en fonction du nombre de fps voulu dans init
t_bool so_render(t_so *so)
{
	(void)so;
	return (FALSE);
}