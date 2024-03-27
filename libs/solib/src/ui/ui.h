/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_ui.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:32:10 by marvin            #+#    #+#             */
/*   Updated: 2024/03/03 00:32:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_UI_H
# define SOLIB_UI_H
#include "../solib_init/solib_init.h"

//sprite
t_solib_sprite	*solib_new_sprite(t_solib *solib, t_solib_construct *construct, t_solib_transform *transform);
void			solib_sprite_data(t_solib *solib, t_solib_sprite *sprite, t_solib_transform *transform);
void			*solib_sprite_xpm(t_solib *solib, t_solib_construct *construct, t_solib_size **out, t_bool *is_immage);
void			*solib_sprite_base(t_solib *solib, t_solib_transform *transform, t_solib_size **out);
void			solib_sprite_adress(t_solib_sprite_data *data);

t_solib_vector2 *calculate_ratio_size(t_solib *solib, t_solib_size *content_size, t_solib_size *target_size, t_solib_size **out);
void solib_write_pixel(t_solib_sprite_data *data, int x, int y, int color);
unsigned int solib_get_pixel(t_solib_sprite_data *data, int x, int y);
#endif