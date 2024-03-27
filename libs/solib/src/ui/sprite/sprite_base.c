/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:38:05 by marvin            #+#    #+#             */
/*   Updated: 2024/03/22 14:38:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void *solib_sprite_base(t_solib *solib, t_solib_transform *transform, t_solib_size **out)
{
	void *ptr;

	if (!transform->size->width || !transform->size->height)
		return (NULL);
	ptr = mlx_new_image(solib->minilibx, transform->size->width, transform->size->height);
	if (!ptr)
		return (NULL);
	*out = transform->size;
	return (ptr);
}