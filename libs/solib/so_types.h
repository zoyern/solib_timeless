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

#ifndef SO_TYPES_H
# define SO_TYPES_H

typedef unsigned long long uint64_t;
typedef unsigned int uint32_t;
typedef int t_bool;

# define TRUE 1
# define FALSE 0

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

typedef struct s_solong
{
	void		*mlx;
	void		*win;
	int			test;
}	t_solong;

typedef struct s_so
{
	t_bool		close;
	void		*minilibx;
	void		*window;
	char		*name;
	int			width;
	int			height;
	int			target_frame;
	t_so_clock	so_update;
	t_so_clock	so_render;
	t_so_ticks	so_ticks;
	t_solong	*so_env;
	t_bool		(*func_update)();
	t_bool		(*func_render)();
}	t_so;

#endif