/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:26:32 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 08:34:20 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_init.h"

void	solib_time_init(t_solib *solib,
			int mhz, int targf_update, int targf_render)
{
	t_solib_time	*time;

	time = solib_malloc(solib, sizeof(t_solib_time));
	time->ticks = solib_init_ticks(mhz);
	time->update = solib_clock_init(fps_to_ms(targf_update));
	time->render = solib_clock_init(fps_to_ms(targf_render));
	solib->time = time;
}
