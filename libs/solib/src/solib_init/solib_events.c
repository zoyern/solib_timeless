/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:15:39 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 08:23:49 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_init.h"

void	solib_events_init(t_solib *solib)
{
	t_solib_events	*events;

	events = (t_solib_events *)solib_malloc(solib, sizeof(t_solib_events));
	events->key_press = NULL;
	events->key_release = NULL;
	solib->events = events;
}
