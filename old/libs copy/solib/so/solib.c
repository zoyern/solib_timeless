/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 05:10:07 by marvin            #+#    #+#             */
/*   Updated: 2024/01/29 05:10:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib.h"

//so = soInit(solong.mlx, "solong", 60);
t_so so_init(void *minilibx, void *window, void *func_update, void *func_render, void *so_env, char *name, int target_frame)
{
	t_so	so;

	so.close = FALSE;
	so.minilibx = minilibx;
	so.window = window;
	so.name = name;
	so.width = 1920;
	so.height = 1080 - 75;
	so.target_frame = target_frame;
	so.so_env = so_env;
	so.so_update = so_clock_init(fps_to_ms(240));
	so.so_render = so_clock_init(fps_to_ms(240));
	so.func_update = func_update;
	so.func_render = func_render;
	so.so_ticks = so_init_ticks(3000);
	//printf("HHHHHHHHAAAAAAAAAAAAAAAAAA :%p -- %p\n", so.so_env, so_env);
	return (so);
}

//so = soInitSize(solong.minilibx, 800, 400, "hey", 60);
t_so so_init_s(void *minilibx, void *window, void *so_env, int width, int height, char *name, int target_frame)
{
	t_so	so;

	(void)so_env;
	so.minilibx = minilibx;
	so.window = window;
	so.name = name;
	so.width = width;
	so.height = height;
	so.target_frame = target_frame;
	so.so_env = so_env;
	so.so_ticks = so_init_ticks(3000);
	//init window
	return (so);
}

t_bool	so_close(t_so *so, t_bool err)
{
	//free all
	(void)so;
	so->close = TRUE;
	return (err);
}