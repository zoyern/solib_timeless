/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:48:11 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 08:21:37 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_hooks.h"

void	solib_hooks(t_solib *solib)
{
	mlx_hook(solib->windows->window,
		17, 1L << 0, solib->close, solib);
	mlx_hook(solib->windows->window,
		KeyPress, KeyPressMask, &solib_key_press, solib);
	mlx_hook(solib->windows->window,
		KeyRelease, KeyReleaseMask, &solib_key_release, solib);
}
