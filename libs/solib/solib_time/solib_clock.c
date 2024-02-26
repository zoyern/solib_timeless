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

#include "solib_time.h"
#include "../solib.h"

t_solib_clock solib_clock_init(double ms)
{
	t_solib_clock so_clock;

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

<<<<<<< HEAD:libs/solib/so_time/so_clock.c
t_so_clock	so_clock(t_so *so, t_so_clock *so_clock, double ms, t_bool (*callback)(t_so *))
{
	if ((int)so_clock->clock_end <= 0)
		*so_clock = so_clock_init(ms);
	if (!so_clock->stop)
	{
		if ((so_clock->clock_end - so_clock->clock_start) <= 0)
		{
			if (callback(so))
				return (*so_clock);
			so_clock->frame += 1;
			so_clock->fps_count += 1;
			so_clock->clock_end = so_clock->clock_start + ms;
		}
		if (so_clock->fps_end - so_clock->fps_start  <= 0)
		{
			so_clock->fps = so_clock->fps_count;
			so_clock->fps_count = 0;
			so_clock->fps_end = so_clock->fps_start + 1000.0f;
		}
		so_clock->clock_start = so->so_ticks.millis;
		so_clock->fps_start = so->so_ticks.millis;
	}
	else
		so_clock->fps = 0;
	return (*so_clock);
=======
t_solib_clock solib_clock(t_solib *solib, t_solib_clock *clock, double ms, t_bool (*callback)(t_solib *))
{
	if (!clock->stop)
	{
		if ((clock->clock_end - clock->clock_start) <= 0)
		{
			if (callback(solib))
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
		clock->clock_start = solib->time->ticks.millis;
		clock->fps_start = solib->time->ticks.millis;
	}
	else
		clock->fps = 0;
	return *clock;
>>>>>>> 219fddf0229d67aa579b1fcedaa712a12327e966:libs/solib/solib_time/solib_clock.c
}