/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:03:59 by marvin            #+#    #+#             */
/*   Updated: 2024/03/15 20:10:29 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_init.h"

void	solib_new_init(t_solib *solib)
{
	t_solib_new	*event_new;

	event_new = solib_malloc(solib, sizeof(t_solib_new));
	event_new->transform = solib_new_transform;
	event_new->quate = NULL;
	event_new->construct = solib_new_construct;
	event_new->vector2 = solib_new_vector2;
	event_new->size = solib_new_size;
	event_new->canvas = solib_new_canvas;
	event_new->display = solib_new_display;
	event_new->so = solib_new_funcs;
	

	solib->new = event_new;
}