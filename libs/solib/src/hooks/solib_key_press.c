/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_key_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:15:15 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 08:22:51 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_hooks.h"

int	solib_key_press(int keycode, t_solib *solib)
{
	if (keycode < 256)
		solib->inputs->keys[keycode] = TRUE;
	if (solib->events->key_press)
		solib->events->key_press(solib, keycode);
	return (0);
}
