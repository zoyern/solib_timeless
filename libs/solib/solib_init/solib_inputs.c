/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:23:00 by marvin            #+#    #+#             */
/*   Updated: 2024/02/26 23:23:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib.h"

t_bool solib_inputs_init(t_solib *solib)
{
	t_solib_inputs	*inputs;
	unsigned long	i;

	inputs = (t_solib_inputs *)malloc(sizeof(t_solib_inputs));
	if (!inputs)
		return (free(solib->windows), free(solib->minilibx),free(solib), TRUE);
	i = 0;
    while (i < 256)
	{
        inputs->keys[i] = FALSE;
		i++;
	}
	solib->inputs = inputs;
	return (FALSE);
}