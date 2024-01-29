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

typedef unsigned long long uint64_t;
typedef unsigned int uint32_t;
typedef int t_bool;

# define TRUE 1
# define FALSE 0

typedef struct s_so_chrono
{
}	t_so_chrono;

typedef struct s_so_timer
{
}	t_so_timer;

typedef struct s_so_clock
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
}	t_so_clock;

typedef struct s_so_ticks
{
	double mhz;
	double millis;
	double ticks;
}	t_so_ticks;

//Cycles
uint64_t	so_get_cycles(void);
double		mhz_to_cycles_per_ms(double frequencyMHz);
double		cycles_to_ms(uint64_t cycles, double cpuFrequencyPerMs);
double		fps_to_ms(int fps);
int 		ms_to_fps(double ms);

t_so_ticks	so_init_ticks(double cpuFrequencyMHz);
void		so_update_ticks(t_so_ticks *soTicks, uint64_t *startCycles);

//Utils
void	get_time_by_millis(double millis, int *hours, int	*minutes, int *seconds, int	*milliseconds);


#endif