/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:08:27 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 02:16:10 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_INIT_H
# define SOLIB_INIT_H

# include "../solib_types/solib_types.h"

//windows :
void	solib_windows_init_size(t_solib *solib, int width, int height);
t_bool	solib_windows_init(t_solib *solib, char *name, int width, int height, int target_frame);

//memory
t_bool	solib_memory_init(t_solib *solib);
void	solib_memory_add(t_solib *solib, void *ptr);
void	solib_memory_show(t_solib *solib);
void	solib_memory_clear(t_solib *solib);

//events :
t_bool	solib_events_init(t_solib *solib);

//inputs :
t_bool solib_inputs_init(t_solib *solib);

//time :
t_bool solib_time_init(t_solib *solib, int mhz, int targf_update, int targf_render);


#endif