/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_timer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:32:56 by marvin            #+#    #+#             */
/*   Updated: 2024/01/29 18:32:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib.h"

t_so_timer so_timer_init(double ms, double millis)
{ 
	t_so_timer so_timer;

	so_timer.stop = FALSE;
    so_timer.timer_start = millis;
	so_timer.timer_end = millis + ms;

    so_timer.timer_ttc = ms;
	return (so_timer);
}

t_so_timer so_timer(t_so *so, t_so_timer *so_timer, double ms, t_bool (*callback)(t_so *))
{
	if ((int)so_timer->timer_end <= 0)
		*so_timer = so_timer_init(ms, so->so_ticks.millis);
	if (!so_timer->stop)
	{
		if ((so_timer->timer_end - so_timer->timer_start) <= 0)
		{
			if (callback(so))
				return (*so_timer);
			so_timer->stop = TRUE;
		}
		so_timer->timer_start = so->so_ticks.millis;
	}
	return (*so_timer);
}