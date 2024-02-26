/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_key_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:15:15 by marvin            #+#    #+#             */
/*   Updated: 2024/02/11 02:15:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_hooks.h"

int	solib_key_press(int keycode, t_solib *solib)
{
	if (keycode < 256)
		solib->inputs->keys[keycode] = TRUE;
	//printf("keyPress keycode :%d -- %c\n", keycode, (unsigned char)keycode);
	if (solib->events->key_press)
		solib->events->key_press(solib, keycode);
    return 0;
}
