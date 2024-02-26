/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_ticks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:47:30 by marvin            #+#    #+#             */
/*   Updated: 2024/01/26 03:47:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_time.h"

t_solib_ticks	solib_init_ticks(double mhz)
{
	t_solib_ticks	ticks;

	ticks.cycles_state = so_get_cycles();
	ticks.mhz = mhz;
	ticks.millis = 0;
	ticks.ticks = 0;
	return (ticks);
}

void	solib_ticks(t_solib_ticks *ticks, uint64_t *cycles_state)
{
    uint64_t cycles_end;
	
	cycles_end = so_get_cycles();
	ticks->ticks += cycles_to_ms(cycles_end - *cycles_state, mhz_to_cycles_per_ms(ticks->mhz));
	ticks->millis = ticks->ticks * 1000 / 1000000;
	*cycles_state = cycles_end;
}