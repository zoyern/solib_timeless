/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:55:15 by marvin            #+#    #+#             */
/*   Updated: 2024/01/29 03:55:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_H
# define SO_H

# include <stdio.h>
# include <unistd.h>
# include "./so_time/so_time.h"

typedef unsigned long long uint64_t;
typedef unsigned int uint32_t;
typedef int t_bool;

# define TRUE 1
# define FALSE 0

typedef struct s_so
{
	void		*minilibx;
	void		*window;
	char		*name;
	int			target_frame;
	t_so_clock	so_update;
	t_so_clock	so_render;
	t_so_ticks	so_ticks;
}	t_so;


//Setup
t_so		so_init(void *minilibx, char *name, int target_frame);
t_so		so_init_s(void *minilibx, int width, int height, char *name, int target_frame);
t_so_clock	so_clock(t_so *so, t_so_clock soClock, double ms, t_bool (*callback)(t_so *));
t_bool		so_close(t_so *so, t_bool err);

//Extern
t_bool		so_setup(int argc, char const **argv, t_so *so);
t_bool		so_start(t_so *so);
t_bool		so_update(t_so *so);
t_bool		so_render(t_so *so);

#endif