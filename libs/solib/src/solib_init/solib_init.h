/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:08:27 by marvin            #+#    #+#             */
/*   Updated: 2024/03/15 20:10:19 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_INIT_H
# define SOLIB_INIT_H

# include "../../libs/minilibx/mlx.h"
# include "../solib.h"
# include "../ui/ui.h"
# include "../utils/utils.h"
# include "../hooks/solib_hooks.h"
# include "../solib.h"

//solib
int					solib_close(t_solib *solib);
void				*solib_malloc(t_solib *solib, int size);
t_bool				solib_free(t_solib *solib, void *ptr);
//ticks
t_solib_ticks		solib_init_ticks(double mhz);
void				solib_ticks(t_solib_ticks *ticks);
//clock
t_solib_clock		solib_clock(t_solib *solib, t_solib_clock *clock,
						double ms, t_bool (*callback)(t_solib *));
t_solib_clock		solib_clock_init(double ms);
//windows :
void				solib_windows_init_size(t_solib *solib, int width, int height);
void				solib_windows_init(t_solib *solib,
						char *name, int width, int height);
//memory
void				solib_memory_init(t_solib *solib);
void				solib_memory_add(t_solib *solib, void *ptr);
t_solib_memory		*solib_memory_free(t_solib *solib, void *ptr);
void				solib_memory_show(t_solib *solib);
void				solib_memory_clear(t_solib *solib);
//events :
void				solib_events_init(t_solib *solib);
//inputs :
void				solib_inputs_init(t_solib *solib);
//time :
void				solib_time_init(t_solib *solib,
						int mhz, int targf_update, int targf_render);
//new :
void				solib_new_init(t_solib *solib);
void				solib_funcs_init(t_solib *solib, t_solib_funcs *init);

//ui
t_solib_display		*solib_new_display(t_solib *solib, t_solib_construct *construct);
t_solib_canvas		*solib_new_canvas(t_solib *solib,
						t_solib_construct *construct, t_solib_transform *transform);
//t_solib_image		*solib_new_image(t_solib *solib, t_solib_construct *construct, t_solib_transform *transform);
void				destroy_image(t_solib *solib, t_solib_image img);
//utils :
t_solib_vector2		*solib_new_vector2(t_solib *solib, float x, float y);
t_solib_size		*solib_new_size(t_solib *solib, float width, float height);
t_solib_transform	*solib_new_transform(t_solib *solib, t_solib_vector2 *vector2, t_solib_size *size);
t_solib_construct	*solib_new_construct(t_solib *solib, char *name, char *args, t_bool enabled);
t_solib_funcs		*solib_new_funcs(t_solib *solib, void *environement, int (*start)(t_solib *solib, void *environement), int (*update)(t_solib *solib, void *environement));
#endif