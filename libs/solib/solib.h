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
# include "so_types.h"
# include "./so_time/so_time.h"

//Setup
t_so		so_init(void *minilibx, char *name, int target_frame);
t_so		so_init_s(void *minilibx, int width, int height, char *name, int target_frame);
t_so_clock	so_clock(t_so *so, t_so_clock soClock, double ms, t_bool (*callback)(t_so *));
t_so_timer	so_timer(t_so *so, t_so_timer so_timer, double ms, t_bool (*callback)(t_so *));
t_so_chrono so_chrono(t_so *so, t_so_chrono so_chrono);
t_bool		so_close(t_so *so, t_bool err);

//Extern
t_bool		so_start(int argc, char const **argv, t_so *so);
t_bool		so_update(t_so *so);
t_bool		so_render(t_so *so);

//Utils
void		get_time_by_millis(double millis, int *hours, int	*minutes, int *seconds, int	*milliseconds);
double		fps_to_ms(int fps);
int 		ms_to_fps(double ms);

#endif