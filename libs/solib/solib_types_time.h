/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:01:35 by marvin            #+#    #+#             */
/*   Updated: 2024/01/29 21:01:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_TYPES_TIME_H
# define SOLIB_TYPES_TIME_H

# include "solib_def.h"

typedef struct s_so_chrono
{
	t_bool	stop;
	t_bool	restart;
	double	chrono_start;
	double	millis;
	int		hours;
	int		minutes;
	int		seconds;
	int		milliseconde;
}	t_so_chrono;

typedef struct s_so_timer
{
	t_bool	stop;
	double	timer_start;
	double	timer_end;
	double	timer_ttc;
}	t_so_timer;

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
	uint64_t	cycles_state;
	double		mhz;
	double		millis;
	double		ticks;
}	t_solib_ticks;

#endif