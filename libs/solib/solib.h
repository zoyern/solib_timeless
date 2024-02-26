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

#ifndef SOLIB_H
# define SOLIB_H

#include <stdlib.h>
#include <stdio.h>

# include "../minilibx/mlx.h"
# include "solib_types.h"

//Setup
<<<<<<< HEAD
t_so		so_init(void *minilibx, char *name, int target_frame);
t_so		so_init_s(void *minilibx, int width, int height, char *name, int target_frame);
t_so_clock	so_clock(t_so *so, t_so_clock *soClock, double ms, t_bool (*callback)(t_so *));
t_so_timer	so_timer(t_so *so, t_so_timer *so_timer, double ms, t_bool (*callback)(t_so *));
t_so_chrono so_chrono(t_so *so, t_so_chrono *so_chrono);
t_bool		so_close(t_so *so, t_bool err);
=======
t_bool			solib_init(char *name,int width, int height, int target_frame);
int				solib_start(t_solib *solib);
int				solib_close(t_solib *solib);
int				solib_update(t_solib *solib);
int				solib_render(t_solib *solib);
>>>>>>> 219fddf0229d67aa579b1fcedaa712a12327e966

t_solib_clock	solib_clock(t_solib *solib, t_solib_clock *clock, double ms, t_bool (*callback)(t_solib *));
t_solib_clock	solib_clock_init(double ms);

t_solib_ticks	solib_init_ticks(double mhz);
void			solib_ticks(t_solib_ticks *so_ticks, uint64_t *cycles_state);

//Utils
void			get_time_by_millis(double millis, int *hours, int	*minutes, int *seconds, int	*milliseconds);
double			fps_to_ms(int fps);
int 			ms_to_fps(double ms);

#endif