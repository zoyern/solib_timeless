/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_types_time.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:01:35 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 09:40:31 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_TYPES_TIME_H
# define SOLIB_TYPES_TIME_H

# include "solib_def.h"

typedef struct s_solib_timing
{
	double	millis;
	int		hours;
	int		minutes;
	int		seconds;
	int		milliseconds;
}	t_solib_timing;

typedef struct s_solib_clock
{
	t_bool	stop;
	int		frame;
	int		fps;
	int		fps_count;
	double	clock_start;
	double	clock_end;
	double	fps_start;
	double	fps_end;
	double	clock_ttc;
}	t_solib_clock;

typedef struct s_solib_ticks
{
	t_uint64	cycles_state;
	double		mhz;
	double		millis;
	double		ticks;
}	t_solib_ticks;

#endif