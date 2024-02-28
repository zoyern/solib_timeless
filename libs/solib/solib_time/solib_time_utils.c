/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_time_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:47:51 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 09:37:28 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib_init/solib_init.h"

t_solib_timing	get_time_by_millis(double millis)
{
	t_solib_timing	time;

	time.millis = millis;
	time.hours = ((int)millis / (3600 * 1000));
	time.minutes = (((int)millis / 60000) % 60);
	time.seconds = (((int)millis / 1000) % 60);
	time.milliseconds = ((int)millis - (time.hours * 3600 * 1000)
			- (time.minutes * 60000) - (time.seconds * 1000));
	return (time);
}

double	fps_to_ms(int fps)
{
	return (1000.0 / fps);
}

int	ms_to_fps(double ms)
{
	return ((int)(1000.0 / ms));
}
