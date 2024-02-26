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
	if (keycode < 256)
		solib->inputs->keys[keycode] = FALSE;
	//printf("keyRelease keycode :%d -- %c\n", keycode, (unsigned char)keycode);
	if (solib->events->key_release)
		solib->events->key_release(solib, keycode);
    return 0;
}