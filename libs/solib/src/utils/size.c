/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:18:58 by marvin            #+#    #+#             */
/*   Updated: 2024/03/22 14:18:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_solib_size *solib_new_size(t_solib *solib, float width, float height)
{
	t_solib_size *size;

	size = (t_solib_size *)solib->malloc(solib, sizeof(t_solib_size));
	size->width = width;
	size->height = height;
	return (size);
}