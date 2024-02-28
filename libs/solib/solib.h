/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:55:15 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 01:31:21 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_H
# define SOLIB_H

#include <stdlib.h>
#include <stdio.h>

# include "../minilibx/mlx.h"
# include "./solib_types/solib_types.h"

//Setup
t_bool			solib_init(char *name,int width, int height, int target_frame);
int				solib_start(t_solib *solib);
int				solib_close(t_solib *solib);
int				solib_update(t_solib *solib);
int				solib_render(t_solib *solib);

t_solib_clock	solib_clock(t_solib *solib, t_solib_clock *clock, double ms, t_bool (*callback)(t_solib *));
t_solib_clock	solib_clock_init(double ms);

t_solib_ticks	solib_init_ticks(double mhz);
void			solib_ticks(t_solib_ticks *so_ticks, uint64_t *cycles_state);

//Memory
void	*solib_malloc(t_solib *solib, int size);

//Utils
void			get_time_by_millis(double millis, int *hours, int	*minutes, int *seconds, int	*milliseconds);
double			fps_to_ms(int fps);
int 			ms_to_fps(double ms);

#endif