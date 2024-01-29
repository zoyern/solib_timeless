/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soTime.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:52:37 by marvin            #+#    #+#             */
/*   Updated: 2024/01/24 22:52:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_TIME_H
# define SO_TIME_H

# include "../so_types.h"

//Cycles
uint64_t	so_get_cycles(void);
double		mhz_to_cycles_per_ms(double frequencyMHz);
double		cycles_to_ms(uint64_t cycles, double cpuFrequencyPerMs);

t_so_ticks	so_init_ticks(double cpuFrequencyMHz);
void		so_update_ticks(t_so_ticks *soTicks, uint64_t *startCycles);


#endif