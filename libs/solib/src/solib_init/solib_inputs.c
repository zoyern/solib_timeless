/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:23:00 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 08:30:30 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_init.h"

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
