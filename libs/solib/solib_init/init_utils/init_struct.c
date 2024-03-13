/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:06:48 by marvin            #+#    #+#             */
/*   Updated: 2024/03/12 21:06:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib_init.h"

t_solib_vector2 *solib_new_vector2(t_solib *solib, float x, float y)
{
	t_solib_vector2 *vector2;

	vector2 = (t_solib_vector2 *)solib_malloc(solib, sizeof(t_solib_vector2));
	vector2->x = x;
	vector2->y = y;
	return (vector2);
}

t_solib_quate *solib_new_quate(t_solib *solib, float x, float y, float z)
{
	t_solib_quate *quate;

	quate = (t_solib_quate *)solib_malloc(solib, sizeof(t_solib_quate));
	quate->x = x;
	quate->y = y;
	quate->z = z;
	return (quate);
}

t_solib_size *solib_new_size(t_solib *solib, float width, float height)
{
	t_solib_size *size;

	size = (t_solib_size *)solib_malloc(solib, sizeof(t_solib_size));
	size->width = width;
	size->height = height;
	return (size);
}

t_solib_transform *solib_new_transform(t_solib *solib, t_solib_vector2 *vector2, t_solib_size *size,t_solib_quate *quate)
{
	t_solib_transform *transform;

	transform = (t_solib_transform *)solib_malloc(solib, sizeof(t_solib_transform));
	transform->vector2 = vector2;
	transform->size = size;
	transform->quate = quate;
	return (transform);
}

t_solib_construct *solib_new_construct(t_solib *solib, char *name, char *args)
{
	t_solib_construct *construct;

	construct = (t_solib_construct *)solib_malloc(solib, sizeof(t_solib_construct));
	construct->name = name;
	construct->args = args;
	return (construct);
}

t_solib_canvas *solib_new_canvas(t_solib_display *display, t_solib_construct *construct, t_solib_transform *transform)
{
	t_solib_canvas *canva;

	canva = (t_solib_canvas *)solib_malloc(display->solib, sizeof(t_solib_canvas));
	canva->solib = display->solib;
	canva->display = display;
	canva->name = construct->name;
	canva->link = construct->args;
	canva->pos = transform->vector2;
	canva->size = transform->size;
	canva->quate = transform->quate;
	canva->background = NULL;
	canva->images = NULL;
	canva->buttons = NULL;
	return (canva);
}

t_solib_image *solib_new_image_tmp(t_solib_canvas *canvas, t_solib_construct *construct, t_solib_transform *transform)
{
	t_solib_image *image;

	image = (t_solib_image *)solib_malloc(canvas->solib, sizeof(t_solib_image));
	image->solib = canvas->solib;
	image->display = canvas->display;
	image->canva = canvas;
	image->name = construct->name;
	image->link = construct->args;
	image->pos = transform->vector2;
	image->size = transform->size;
	image->quate = transform->quate;
	image->set = NULL;
	image->get = NULL;
	image->buttons = NULL;
	return (image);
}
