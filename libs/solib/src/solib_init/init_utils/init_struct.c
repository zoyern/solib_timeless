/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:06:48 by marvin            #+#    #+#             */
/*   Updated: 2024/03/20 15:48:52 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib_init.h"

void put_canva_display(t_solib_display *display, t_solib_canvas *canva)
{
	int i;
	int j;
	i = 0;
	while (i < canva->background->data->transform->size->height)
	{
		j = 0;
		while (j < canva->background->data->transform->size->width)
		{
			solib_write_pixel(display->area->data, (int)canva->background->data->transform->origin->x + j, (int)canva->background->data->transform->origin->y + i, solib_get_pixel(canva->background->data, j, i));
			j++;
		}
		i++;
	}
}

t_solib_canvas *solib_new_canvas(t_solib *solib, t_solib_construct *construct, t_solib_transform *transform)
{
	if (!solib->display)
		return (NULL);
	t_solib_canvas *canva;
	t_solib_size *final_size;

	canva = (t_solib_canvas *)solib_malloc(solib, sizeof(t_solib_canvas));

	canva->ratio = calculate_ratio_size(solib,
										solib->display->area->data->transform->size,
										transform->size, &final_size);
	float posx = ((float)solib->display->area->data->transform->size->width - final_size->width) / 2;
	float posy = ((float)solib->display->area->data->transform->size->height - final_size->height) / 2;
	transform->origin->x = posx;
	transform->origin->y = posy;
	transform->size = final_size;
	canva->background = solib_new_sprite(solib, construct, transform);
	put_canva_display(solib->display, canva);
	return (canva);
}
// t_solib_display *display = solib->new->display(solib,	solib->new->construct(solib, "display", "171717", FALSE));
t_solib_display *solib_new_display(t_solib *solib, t_solib_construct *construct)
{
	t_solib_display *display;

	display = (t_solib_display *)solib_malloc(solib, sizeof(t_solib_display));
	display->area = solib_new_sprite(solib,
					construct,
					solib->new->transform(solib,
					solib->new->vector2(solib, 0, 0),
					solib->new->size(solib, solib->windows->width, solib->windows->height)));
	solib->display = display;
	return (display);
}

// je creer

/*for (float y = 0; y < ring.h; y += 2)
	{
		for (float x = 0; x < ring.w; x += 2)
		{
			// Calcul de l'index du pixel dans les données de l'image
			index = ((int)y * ring.line_len) + ((int)x * (ring.bpp / 8));

			// Accès aux composantes R, G, B du pixel
			pixel = (unsigned char *)(ring.addr + index);
			red = pixel[0];
			green = pixel[1];
			blue = pixel[2];

			// Modification du pixel (par exemple, conversion en niveaux de gris)
			gray = (unsigned char)(0.299 * red + 0.587 * green + 0.114 * blue);
			pixel[0] = gray; // R
			pixel[1] = gray; // G
			pixel[2] = gray; // B
			if (pixel[0] || pixel[1] || pixel[2])
				printf("1,");
			else
				printf(" ,");
		}
		printf("\n");
	}
*/

