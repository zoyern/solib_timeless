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

t_solib_events	solib_events_init()
{
	t_solib_events events;

	events.key_press = NULL;
	events.key_release = NULL;

	return (events);
}

int		solib_close(t_solib *solib)
{
	int	i;

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
	i = -1;
	while (i++ < 256)
		free(solib->inputs.keys[i].symbol);

	if (solib)
    	free(solib);
    exit(1);
}


t_solib_inputs solib_inputs_init()
{
	t_solib_inputs	inputs;
	char			*symbol;

	

    for (int i = 0; i < (int)sizeof(inputs.keys) / (int)sizeof(inputs.keys[0]); i++)
    {
        inputs.keys[i].pressed = FALSE;
        inputs.keys[i].keycode = (unsigned char)i;
		symbol = (char *)malloc(sizeof(char) + 1);
		symbol[0] = (unsigned char)i;
		symbol[1] = '\0';
        inputs.keys[i].symbol = symbol;
    }
	return (inputs);
}


int		updatetest(t_solib *solib)
{
	//solib->close(solib);
	//printf("a : %d\n", solib->inputs.keys[225].pressed);
	if (solib->inputs.keys['a'].pressed)
    {
        // Faire quelque chose lorsque la touche 'A' est pressée
        //printf("Touche 'maj' pressée\n");
    }
	return (0);
}

void	*solib_init(char *name)
{
	t_solib *solib;

	solib = (t_solib *)malloc(sizeof(t_solib));
	if (!solib)
		return (NULL);
	solib->minilibx = mlx_init();
	if (!solib->minilibx)
	{
		free(solib);
		return (NULL);
	}
	solib->windows = (t_solib_windows *)malloc(sizeof(t_solib_windows));
	if (!solib->windows)
	{
		free(solib->minilibx);
		free(solib);
		return (NULL);
	}
	solib->windows->width = 1080;
	solib->windows->height = 720;
	//mlx_get_screen_size(solib->minilibx, &solib->windows->width, &solib->windows->height);
	solib->windows->window = mlx_new_window(solib->minilibx, solib->windows->width, solib->windows->height, name);
	if (!solib->windows->window)
	{
		free(solib->minilibx);
		free(solib->windows);
		free(solib);
		return (NULL);
	}
	solib->close = solib_close;
	solib->inputs = solib_inputs_init();
	solib->events = solib_events_init();
	solib_start(solib);

	mlx_hook(solib->windows->window, 17, 1L<<0, &solib_close, solib);
	solib_hooks(solib);
	mlx_loop_hook(solib->minilibx, updatetest, solib);
	/*int i = 0;
	while (i < 256)
	{
		printf("input : %d -- %s\n", solib->inputs.keys[i].keycode, solib->inputs.keys[i].symbol);
		i++;
	}*/
	

/* 1. KeyPress */
	/*     Prototype : int keyPressCallback(int keycode, t_solib_inputs *inputs);
	*     Valeur : keycode - Code de la touche pressée.
	*     Utilisation : Utilisez keycode pour réagir à la touche pressée. */
	//mlx_hook(solib->windows->window, KeyPress, KeyPressMask, &keyPressCallback, solib);

	//mlx_key_hook(solib->windows->window, &keyPress, &solib->inputs);

    //mlx_hook(solib->windows->window, 3, 0, &keyRelease, &solib->inputs);

	mlx_loop(solib->minilibx);
	return (solib);
}