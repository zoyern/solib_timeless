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
#include "../../../src/mysolonglib.h"

int main(int argc, char const **argv)
{
	t_so		so;
	uint64_t	cycles_state;
	t_bool		ex;
	int i = 0;

	cycles_state = so_get_cycles();
<<<<<<< HEAD:libs/solib/so/main.c
	if (so_start(argc, argv, &so))
		so_close(&so, TRUE);
	while (1)
		{
			so.so_update = so_clock(&so, &so.so_update,  fps_to_ms(240), so_update);
			so.so_render = so_clock(&so, &so.so_render,  fps_to_ms(so.target_frame), so_render);
			so_update_ticks(&so.so_ticks, &cycles_state);
		}
=======
	ex = so_start(argc, argv, &so);
	if (ex)
		return (so_close(&so, ex));
	//printf("so.env :%p\n", so.so_env);
	//printf("main :%d\n", testing[0]);

	while (!so.close)
	{
		so.so_update = so_clock(&so, so.so_env, &so.so_update,  fps_to_ms(240), so.func_update);
		so.so_render = so_clock(&so, so.so_env, &so.so_render,  fps_to_ms(so.target_frame), so.func_render);
		so_update_ticks(&so.so_ticks, &cycles_state);

		// Reste de ta boucle principale ...

		i++;
	}
>>>>>>> 219fddf0229d67aa579b1fcedaa712a12327e966:old/libs copy/solib/so/main.c
    return (so_close(&so, FALSE));
}
