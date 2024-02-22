/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:00:14 by marvin            #+#    #+#             */
/*   Updated: 2024/02/08 18:00:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int		key_test(int keycode)
{
	(void)keycode;
	//printf ("laaaaaaaaaaaaaaaaaa - keycode : %d\n", keycode);
	return (0);
}

int		solib_start(t_solib *solib)
{
	solib->events.key_press = key_test;
	return (free(tab), 1);
}

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;

	t_solib *solib;

	solib = solib_init("solong");
	if (!solib)
		return (1);
	solib->close(solib);
	return 0;
}
