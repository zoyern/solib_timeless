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

# include "../solib.h"
# include "../solib_utils.h"

//solib
int					solib_close(t_solib *solib);
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

//ui
t_solib_canvas		*solib_new_canvas(t_solib_display *display,
						t_solib_construct *construct, t_solib_transform *transform);
//t_solib_image		*solib_new_image_tmp(t_solib_image *parent,
//						t_solib_construct *construct, t_solib_transform *transform);
t_solib_image_data	*solib_new_image_data(t_solib *solib, t_solib_image *image, char *background);
t_solib_image		*solib_new_image(t_solib *solib, t_solib_construct *construct, t_solib_transform *transform);
void				destroy_image(t_solib *solib, t_solib_image img);
t_solib_display		*solib_display_init(t_solib *solib);
void				solib_put_pixel_img(t_solib_image *img, float x, float y, int color);
unsigned int		solib_get_pixel_img(t_solib_image *img, int x, int y);
//void				solib_put_image(t_solib_image *parent, t_solib_image *child, t_solib_transform *transform);
//oid				put_img_to_img_2(t_solib *solib, t_solib_image *dst, t_solib_image *src, int pos_x, int pos_y, float width, float height);

//utils :
t_solib_vector2		*solib_new_vector2(t_solib *solib, float x, float y);
t_solib_quate		*solib_new_quate(t_solib *solib, float x, float y, float z);
t_solib_size		*solib_new_size(t_solib *solib, float width, float height);
t_solib_transform	*solib_new_transform(t_solib *solib, t_solib_vector2 *vector2, t_solib_size *size,t_solib_quate *quate);
t_solib_construct	*solib_new_construct(t_solib *solib, char *name, char *args);

#endif