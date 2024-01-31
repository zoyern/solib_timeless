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
	//t_solong	*solong;
	uint64_t	cycles_state;
	int	*testing;

	cycles_state = so_get_cycles();
	so_start(argc, argv, &so);
	printf("so.env :%p\n", so.so_env);
	testing = &so.so_env->test;
	printf("main :%d\n", testing[0]);
	printf("main t :%d\n", so.so_env->test);
	while (!so.close)
	{
		so.so_update = so_clock(&so, so.so_env, so.so_update,  fps_to_ms(240), so.func_update);
		so.so_render = so_clock(&so, so.so_env, so.so_render,  fps_to_ms(so.target_frame), so.func_render);
		so_update_ticks(&so.so_ticks, &cycles_state);
	}
    return (so_close(&so, FALSE));
}
