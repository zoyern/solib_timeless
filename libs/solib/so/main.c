/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 05:10:11 by marvin            #+#    #+#             */
/*   Updated: 2024/01/29 05:10:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib.h"
#include "../so_time/so_time.h"

int main(int argc, char const **argv)
{
	t_so		so;
	uint64_t	cycles_state;

	cycles_state = so_get_cycles();
	if (so_start(argc, argv, &so))
		so_close(&so, TRUE);
	while (1)
		{
			so.so_update = so_clock(&so, &so.so_update,  fps_to_ms(240), so_update);
			so.so_render = so_clock(&so, &so.so_render,  fps_to_ms(so.target_frame), so_render);
			so_update_ticks(&so.so_ticks, &cycles_state);
		}
    return (so_close(&so, FALSE));
}
