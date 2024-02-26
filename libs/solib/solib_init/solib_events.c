/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:15:39 by marvin            #+#    #+#             */
/*   Updated: 2024/02/26 23:15:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib.h"

t_bool	solib_events_init(t_solib *solib)
{
	t_solib_events *events;

	events = (t_solib_events *)malloc(sizeof(t_solib_events));
	if (!events)
		return (free(solib->windows), free(solib->minilibx),free(solib), TRUE);

	events->key_press = NULL;
	events->key_release = NULL;
	solib->events = events;
	return (FALSE);
}