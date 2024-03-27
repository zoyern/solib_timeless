/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:17:10 by marvin            #+#    #+#             */
/*   Updated: 2024/03/22 14:17:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_solib_transform *solib_new_transform(t_solib *solib, t_solib_vector2 *vector2, t_solib_size *size)
{
	t_solib_transform *transform;

	transform = (t_solib_transform *)solib->malloc(solib, sizeof(t_solib_transform));
	transform->origin = vector2;
	transform->size = size;
	return (transform);
}