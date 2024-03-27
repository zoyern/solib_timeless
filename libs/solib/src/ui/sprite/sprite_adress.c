/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:37:18 by marvin            #+#    #+#             */
/*   Updated: 2024/03/22 14:37:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void solib_sprite_adress(t_solib_sprite_data *data)
{
	data->adress = mlx_get_data_addr(data->ptr, &(data->bpp),
									 &(data->line_len), &(data->endian));
}

