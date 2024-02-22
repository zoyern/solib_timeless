/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_clock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:44:22 by marvin            #+#    #+#             */
/*   Updated: 2024/01/26 03:44:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_time.h"
#include "../solib.h"

t_so_clock so_clock_init(double ms)
{
	t_so_clock so_clock;

	so_clock.stop = FALSE;
	so_clock.frame = 0;
	so_clock.fps = 0;
	so_clock.fps_count = 0;

	so_clock.clock_start = 0;
	so_clock.clock_end = 0;
	so_clock.fps_start = 0;
	so_clock.fps_end = 0;

	so_clock.clock_ttc = ms;
	return (so_clock);
}

t_so_clock so_clock(t_so *so, void *solong, t_so_clock *clock, double ms, t_bool (*callback)(t_so *, void *))
{
	if (!clock)
		*clock = so_clock_init(ms);
	if (!clock->stop)
	{
		if ((clock->clock_end - clock->clock_start) <= 0)
		{
			if (callback(so, solong))
				return *clock;
			clock->frame += 1;
			clock->fps_count += 1;
			clock->clock_end = clock->clock_start + ms;
		}
		if (clock->fps_end - clock->fps_start <= 0)
		{
			clock->fps = clock->fps_count;
			clock->fps_count = 0;
			clock->fps_end = clock->fps_start + 1000.0f;
		}
		clock->clock_start = so->so_ticks.millis;
		clock->fps_start = so->so_ticks.millis;
	}
	else
		clock->fps = 0;
	return *clock;
}