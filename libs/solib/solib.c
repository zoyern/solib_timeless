/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:43:15 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 09:28:53 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib.h"
#include "solib_utils.h"
#include "solib_hooks/solib_hooks.h"
#include "solib_init/solib_init.h"


t_solib_vector2	*solib_new_vector2(t_solib *solib, float x, float y)
{
	t_solib_vector2	*vector2;

	vector2 = (t_solib_vector2 *)solib_malloc(solib, sizeof(t_solib_vector2));
	vector2->x = x;
	vector2->y = y;
	return (vector2);
}

t_solib_resolution	*solib_new_resolution(t_solib *solib, float x, float y)
{
	t_solib_resolution	*resolution;

	resolution = (t_solib_resolution *)solib_malloc(solib, sizeof(t_solib_resolution));
	resolution->x = x;
	resolution->y = y;
	return (resolution);
}

t_solib_size	*solib_new_size(t_solib *solib, int width, int height)
{
	t_solib_size	*size;

	size = (t_solib_size *)solib_malloc(solib, sizeof(t_solib_size));
	size->width = width;
	size->height = height;
	return (size);
}

void	new_img(t_solib *solib, float resolution_x, float resolution_y)
{
	t_solib_display		*display;
	t_solib_image		*background;

	display = (t_solib_display *)solib_malloc(solib, sizeof(t_solib_display));
	background = (t_solib_image *)solib_malloc(solib, sizeof(t_solib_image));
	display->resolution = solib_new_resolution(solib, resolution_x, resolution_y);

	solib->windows->ratio = (float)(solib->windows->width / solib->windows->height);
	display->ratio = (float)(resolution_x / resolution_y);

	if (solib->windows->ratio > display->ratio )
		display->size = solib_new_size(solib, (int)(solib->windows->height * display->ratio ), solib->windows->height);
	else
		display->size = solib_new_size(solib, solib->windows->width, (int)(solib->windows->width / display->ratio ));

	printf("----\nhori :\nresolution_x : %0.2f\n win_x : %d\nratio : %0.6f\nnew width : %d\n--\nhori :\nresolution_x : %0.2f\n win_x : %d\nratio : %0.6f\nnew height : %d\n--------\n", resolution_x , solib->windows->width, solib->windows->ratio, display->size->width, resolution_y, solib->windows->height, display->ratio , display->size->height);
	// Calcul des coordonnées de début pour centrer l'image
	display->pos = solib_new_vector2(solib, (solib->windows->width - display->size->width) / 2, (solib->windows->height - display->size->height) / 2);

	// Création de la nouvelle image avec la taille ajustée et centrée
	background->img_ptr = mlx_new_image(solib->minilibx, display->size->width, display->size->height);
	background->addr = mlx_get_data_addr(background->img_ptr, &(background->bpp),
								   &(background->line_len), &(background->endian));
	background->size = display->size;

	// Mise à jour des coordonnées de début de l'image
	background->pos = display->pos;
	display->background = background;
	solib->display = display;
}

t_solib_image new_file_img(char *path, t_solib *solib)
{
	t_solib_image image;

	image.size = solib_new_size(solib, 0, 0);
	image.img_ptr = mlx_xpm_file_to_image(solib->minilibx, path, &image.size->width, &image.size->height);
	if (!image.img_ptr)
		write(2, "File could not be read\n", 23);
	else
		image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
									   &(image.line_len), &(image.endian));
	return (image);
}

void destroy_image(t_solib *solib, t_solib_image img)
{
	if (img.img_ptr && solib->minilibx)
		mlx_destroy_image(solib->minilibx, img.img_ptr);
}

void put_pixel_img(t_solib_image *img, float x, float y, int color)
{
	char *dst;

	if (color == (int)0xFF000000)
		return;
	if (x >= 0 && y >= 0 && x < img->size->width && y < img->size->height)
	{
		dst = img->addr + ((int)y * img->line_len + (int)x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int get_pixel_img(t_solib_image img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.line_len) + (x * img.bpp / 8))));
}


void put_img_to_img(t_solib_image *dst, t_solib_image src, int pos_x, int pos_y, float width, float height)
{
	int index;
	float ratio_x;
	float ratio_y;

	int	i;
	int j;

	if (width < 1)
		ratio_x = 1;
	else
		ratio_x = src.size->width / width ;
	if (width < 1)
		ratio_y = 1;
	else
		ratio_y = src.size->height / height;

	printf("ratiox : %0.3f -- ratioy : %0.3f\n", ratio_x, ratio_y);

	// Accès aux composantes R, G, B du pixel
	i = 0;
	for (float y = 0; y < src.size->height; y += ratio_y)
	{
		j = 0;
		for (float x = 0; x < src.size->width; x += ratio_x)
		{
			// Calcul de l'index du pixel dans les données de l'image
			index = get_pixel_img(src, x, y);
			//index = ((int)y * src.line_len) + ((int)x * (src.bpp / 8));
			// Accès aux composantes R, G, B du pixel
			//pixel = (unsigned char *)(src.addr + index);
			put_pixel_img(dst, pos_x + j, pos_y + i, index);
			/*if (index != (int)0xFF000000)
				//printf("1,");
			else
				printf(" ,");*/
			j++;
		}
		i++;
		//printf("\n");
	}
	/*float i_y;
	float i_x;

	i_y = 0;
	while (i_y < src.h)
	{
		i_x = 0;
		while (i_x < src.w)
		{
			put_pixel_img(dst, x + i_x, y + i_y, get_pixel_img(src, i_x, i_y));
			i_x+=0.5;
		}
		i_y+= 0.5;
	}*/
}

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
int solib_close(t_solib *solib)
{
	if (solib)
	{
		if (solib->windows)
		{
			if (solib->windows->window)
				mlx_destroy_window(solib->minilibx, solib->windows->window);
		}
		if (solib->minilibx)
		{
			mlx_destroy_display(solib->minilibx);
			free(solib->minilibx);
		}
		if (solib->memory)
			solib_memory_clear(solib);
		free(solib);
	}
	exit(0);
}

int solib_loop(t_solib *solib)
{
	solib_ticks(&solib->time->ticks);
	solib->time->update = solib_clock(
		solib, &solib->time->update, fps_to_ms(240), solib_update);
	solib->time->render = solib_clock(
		solib, &solib->time->render, fps_to_ms(solib->target_frame), solib_render);
	return (0);
}

t_bool solib_init(char *name, int width, int height, int target_frame)
{
	t_solib *solib;

	solib = (t_solib *)malloc(sizeof(t_solib));
	if (!solib)
		return (TRUE);
	solib_memory_init(solib);
	solib->minilibx = mlx_init();
	if (!solib->minilibx)
		return (solib_close(solib));
	solib->target_frame = target_frame;
	solib_windows_init(solib, name, width, height);
	solib_inputs_init(solib);
	solib_events_init(solib);
	solib_time_init(solib, SIMUL_MHZ, 240, target_frame);
	solib->close = solib_close;
	solib_hooks(solib);
	if (solib_start(solib))
		solib_close(solib);
	/*solib_memory_show(solib);
	solib_free(solib, solib->inputs);
	solib_memory_show(solib);*/
	t_solib_image bg;
	t_solib_image ring;

	new_img(solib, 1920 , 1080);
	bg = new_file_img("test.xpm", solib);
	if (!bg.img_ptr)
		return (2);
	put_img_to_img(solib->display->background, bg, 0, 0, solib->display->background->size->width, solib->display->background->size->height);
	ring = new_file_img("ring.xpm", solib);
	if (!ring.img_ptr)
		return (2);
	printf("ring %d - %d - %d\n", ring.bpp, ring.line_len, ring.endian);
	put_img_to_img(solib->display->background, ring, 50, 100, 100, 100);
	mlx_put_image_to_window(solib->minilibx, solib->windows->window, solib->display->background->img_ptr, solib->display->background->pos->x, solib->display->background->pos->y);
	mlx_loop_hook(solib->minilibx, solib_loop, solib);
	mlx_loop(solib->minilibx);
	solib_close(solib);
	return (FALSE);
}