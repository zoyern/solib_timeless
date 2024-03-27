/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:38:14 by marvin            #+#    #+#             */
/*   Updated: 2024/03/22 14:38:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void *solib_sprite_xpm(t_solib *solib, t_solib_construct *construct, t_solib_size **out, t_bool *is_immage)
{
	void *ptr;
	int width;
	int height;

	width = 0;
	height = 0;
	if (!construct->args)
		return (NULL);
	ptr = mlx_xpm_file_to_image(solib->minilibx, construct->args, &height, &height);
	if (!ptr)
	{
		*is_immage = FALSE;
		return (NULL);
	}
	*is_immage = TRUE;
	*out = solib->new->size(solib, width, height);
	return (ptr);
}