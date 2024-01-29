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
t_so so_init(void *minilibx, char *name, int target_frame)
{
	t_so	so;

	so.minilibx = minilibx;
	so.name = name;
	so.target_frame = target_frame;
	so.so_ticks = so_init_ticks(3000);
	return (so);
}

//so = soInitSize(solong.minilibx, 800, 400, "hey", 60);
t_so so_init_s(void *minilibx, int width, int height, char *name, int target_frame)
{
	t_so	so;

	(void)width;
	(void)height;
	so = so_init(minilibx, name, target_frame);
	//init window
	return (so);
}

t_bool	so_close(t_so *so, t_bool err)
{
	//free all
	(void)so;
	return (err);
}