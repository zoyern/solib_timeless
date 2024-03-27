/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_ticks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:33:51 by almounib          #+#    #+#             */
/*   Updated: 2024/03/11 13:06:15 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib_init/solib_init.h"

double	mhz_to_cycles_per_ms(double frequencyMHz)
{
	return (frequencyMHz * 1e6 / 1000000.0);
}

double	cycles_to_ms(t_uint64 cycles, double cpuFrequencyPerMs)
{
	return (cycles / cpuFrequencyPerMs);
}

t_solib_ticks	solib_init_ticks(double mhz)
{
	t_solib_ticks	ticks;

	ticks.cycles_state = SIMUL_CYCLES;
	ticks.mhz = mhz;
	ticks.millis = 0;
	ticks.ticks = 0;
	return (ticks);
}

void	solib_ticks(t_solib_ticks *ticks)
{
	ticks->ticks += cycles_to_ms(
			ticks->cycles_state, mhz_to_cycles_per_ms(ticks->mhz));
	ticks->millis = ticks->ticks * 1000 / 1000000;
}
