/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:33:03 by marvin            #+#    #+#             */
/*   Updated: 2024/03/22 14:33:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib.h"

void destroy_image(t_solib *solib, t_solib_image img)
{
	if (solib->minilibx)
	{
		if (img.sprite->data->ptr)
			mlx_destroy_image(solib->minilibx, img.sprite->data->ptr);
		if (img.sprite->origin->ptr)
			mlx_destroy_image(solib->minilibx, img.sprite->origin->ptr);
	}
}