/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 06:40:28 by almounib          #+#    #+#             */
/*   Updated: 2024/02/28 09:27:50 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_UTILS_H
# define SOLIB_UTILS_H

#include "../solib.h"

//Utils
t_solib_construct	*solib_new_construct(t_solib *solib, char *name, char *args, t_bool enabled);
t_solib_funcs		*solib_new_funcs(t_solib *solib, void *environement, int (*start)(t_solib *solib, void *environement), int (*update)(t_solib *solib, void *environement));
t_solib_size		*solib_new_size(t_solib *solib, float width, float height);
t_solib_transform	*solib_new_transform(t_solib *solib, t_solib_vector2 *vector2, t_solib_size *size);
t_solib_vector2		*solib_new_vector2(t_solib *solib, float x, float y);
t_solib_timing		get_time_by_millis(double millis);
double				fps_to_ms(int fps);
int					ms_to_fps(double ms);

#endif