/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_key_release.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:23:15 by marvin            #+#    #+#             */
/*   Updated: 2024/02/11 02:23:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_hooks.h"

int solib_key_release (int keycode, t_solib *solib)
{
	if (((unsigned char)keycode >= 'a' && (unsigned char)keycode >= 'z') && solib->inputs.keys[255].pressed)
		solib->inputs.keys[(unsigned char)keycode - 32].pressed = FALSE;                             
	solib->inputs.keys[(unsigned char)keycode].pressed = FALSE;
	//printf("keyRelease keycode :%d -- %c\n", (unsigned char)keycode, (unsigned char)keycode);
	if (solib->events.key_release)
		solib->events.key_release((unsigned char)keycode);
    return 0;
}