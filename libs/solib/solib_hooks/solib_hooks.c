/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:48:11 by marvin            #+#    #+#             */
/*   Updated: 2024/02/09 13:48:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_hooks.h"

void	solib_hooks(t_solib *solib)
{
	mlx_hook(solib->windows->window, 17, 1L << 0, &solib_close, solib);
	/* 1. KeyPress */
	/*     Prototype : int keyPressCallback(int keycode, t_solib_inputs *inputs);
	*     Valeur : keycode - Code de la touche pressée.
	*     Utilisation : Utilisez keycode pour réagir à la touche pressée. */
	mlx_hook(solib->windows->window, KeyPress, KeyPressMask, &solib_key_press, solib);

	/* 2. KeyRelease */
	/*     Prototype : int keyReleaseCallback(int keycode, t_solib_inputs *inputs);
	*     Valeur : keycode - Code de la touche relâchée.
	*     Utilisation : Utilisez keycode pour réagir à la touche relâchée. */
	mlx_hook(solib->windows->window, KeyRelease, KeyReleaseMask, &solib_key_release, solib);
}