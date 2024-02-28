/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:08:27 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 09:25:16 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_INIT_H
# define SOLIB_INIT_H

# include "../solib.h"
# include "../solib_utils.h"

//solib
int				solib_close(t_solib *solib);
//ticks
t_solib_ticks	solib_init_ticks(double mhz);
void			solib_ticks(t_solib_ticks *ticks);
//clock
t_solib_clock	solib_clock(t_solib *solib, t_solib_clock *clock,
					double ms, t_bool (*callback)(t_solib *));
t_solib_clock	solib_clock_init(double ms);
//windows :
void			solib_windows_init_size(t_solib *solib, int width, int height);
void			solib_windows_init(t_solib *solib,
					char *name, int width, int height);
//memory
void			solib_memory_init(t_solib *solib);
void			solib_memory_add(t_solib *solib, void *ptr);
void			solib_memory_show(t_solib *solib);
void			solib_memory_clear(t_solib *solib);
//events :
void			solib_events_init(t_solib *solib);
//inputs :
void			solib_inputs_init(t_solib *solib);
//time :
void			solib_time_init(t_solib *solib,
					int mhz, int targf_update, int targf_render);

#endif