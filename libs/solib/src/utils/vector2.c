/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:11:52 by marvin            #+#    #+#             */
/*   Updated: 2024/03/22 14:11:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_solib_vector2 *solib_new_vector2(t_solib *solib, float x, float y)
{
	t_solib_vector2 *vector2;

	vector2 = (t_solib_vector2 *)solib->malloc(solib, sizeof(t_solib_vector2));
	vector2->x = x;
	vector2->y = y;
	return (vector2);
}