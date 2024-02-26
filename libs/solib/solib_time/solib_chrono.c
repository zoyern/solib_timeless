/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_chrono.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:52:12 by marvin            #+#    #+#             */
/*   Updated: 2024/01/29 18:52:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "solib_time_f.h"
#include "../solib.h"

t_so_chrono so_chrono_init(double millis)
{ 
	t_so_chrono so_chrono;

	so_chrono.stop = FALSE;
	so_chrono.restart = FALSE;
    so_chrono.chrono_start = millis;
    so_chrono.millis = millis;
    so_chrono.hours = 0;
    so_chrono.minutes = 0;
    so_chrono.seconds = 0;
    so_chrono.milliseconde = 0;

	return (so_chrono);
}

t_so_chrono so_chrono(t_so *so, t_so_chrono *so_chrono)
{
	if ((int)so_chrono->chrono_start <= 0)
		*so_chrono = so_chrono_init(so->so_ticks.millis);
	if (so_chrono->restart)
	{
		*so_chrono = so_chrono_init(so->so_ticks.millis);
		so_chrono->stop = FALSE;
		so_chrono->restart = FALSE;
	}
	if (!so_chrono->stop && !so_chrono->restart)
	{
		so_chrono->millis = so->so_ticks.millis - so_chrono->chrono_start;
		//printf("millis:%0.6f -- millis:%0.6f -- millis:%0.6f\n", so->so_ticks.millis, so_chrono.chrono_start, so->so_ticks.millis - so_chrono.chrono_start);
		get_time_by_millis(so_chrono->millis, &so_chrono->hours, &so_chrono->minutes, &so_chrono->seconds, &so_chrono->milliseconde);
	}
	return (*so_chrono);
<<<<<<< HEAD:libs/solib/so_time/so_chrono.c
}
=======
}*/
>>>>>>> 219fddf0229d67aa579b1fcedaa712a12327e966:libs/solib/solib_time/solib_chrono.c
