/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:00:14 by marvin            #+#    #+#             */
/*   Updated: 2024/03/11 11:50:32 by almounib         ###   ########.fr       */
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
	(void)solib;
	solib->events->key_press = key_test;

	t_solib_display *display = solib2d(solib, 1920, 1080);
	
	(void)display;
	printf("main------%0.2f -- %0.2f\n\n", solib->display->area->size->width, solib->display->area->size->height);

	t_solib_canvas	*canva = solib->new->canvas(
		solib->display,
		solib->new->construct(solib, "menu", "test.xpm"),
		solib->new->transform(
			solib,
			solib->new->vector2(solib, 0,0),
			solib->new->size(solib, display->size->width, display->size->height),
			solib->new->quate(solib, 0, 0, 0)));

	display->current = canva;
	printf("main------%0.2f -- %0.2f\n\n", canva->background->size->width, canva->background->size->height);

	t_solib_image *image1 = solib->new->image(
    solib->display->area,
    solib->new->construct(solib, "image1", "ring.xpm"),
    solib->new->transform(
		solib,
        solib->new->vector2(solib, 0, 0),
        solib->new->size(solib, 1920, 1080),
        solib->new->quate(solib, 0, 0, 0)));


	(void)image1;
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
	/*int i;
	int j;
	int t;
	char **strs;

	t = 500;
	(void)solib;
	strs = (char **)malloc(sizeof(char *) * (t + 1));
	i = 0;
	j = 0;
	while (i < t)
	{
		strs[i] = (char *)malloc(sizeof(char) * (t + 1));
		while (j < t)
		{
			strs[i][j] = 'v';
			j++;
		}
		strs[i][j] = '\0';
		j = 0;
		i++;
	}
	strs[i] = 0;
	i = 0;
	while (i < t)
	{
		free(strs[i]);
		i++;
	}
	free(strs);*/
	return (0);
}

int	main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	//solib = solib_init("solong",1905, 1050, 60);
	//if (solib_init("solong", 1905, 675, 60))
	if (solib_init("solong", 1905, 900, 60))
		return (1);
	return (0);
}