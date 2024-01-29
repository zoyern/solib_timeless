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

#include "../solib.h"

t_so_ticks	so_init_ticks(double mhz)
{
	t_so_ticks	so_ticks;

	so_ticks.mhz = mhz;
	so_ticks.millis = 0;
	so_ticks.ticks = 0;
	return (so_ticks);
}

void	so_update_ticks(t_so_ticks *so_ticks, uint64_t *cycles_state)
{
    uint64_t cycles_end;
	
	cycles_end = so_get_cycles();
	so_ticks->ticks += cycles_to_ms(cycles_end - *cycles_state, mhz_to_cycles_per_ms(so_ticks->mhz));
	so_ticks->millis = so_ticks->ticks * 1000 / 1000000;
	*cycles_state = cycles_end;
}