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

#ifndef SOLIB_TIME_H
# define SOLIB_TIME_H

#include "../solib.h"

//Cycles
uint64_t	so_get_cycles(void);
double		mhz_to_cycles_per_ms(double frequencyMHz);
double		cycles_to_ms(uint64_t cycles, double cpuFrequencyPerMs);



#endif