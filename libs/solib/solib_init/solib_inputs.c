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


void	solib_inputs_init(t_solib *solib)
{
	t_solib_inputs	*inputs;
	int				i;

	inputs = solib_malloc(solib, sizeof(t_solib_inputs));
	i = 0;
    while (i < 256)
	{
        inputs->keys[i] = FALSE;
		i++;
	}
	solib->inputs = inputs;
}