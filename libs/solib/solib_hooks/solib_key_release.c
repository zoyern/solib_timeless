/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_key_release.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:23:15 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 08:23:19 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_hooks.h"

int	solib_key_release(int keycode, t_solib *solib)
{
	if (keycode < 256)
		solib->inputs->keys[keycode] = FALSE;
	if (solib->events->key_release)
		solib->events->key_release(solib, keycode);
	return (0);
}
