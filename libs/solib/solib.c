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

typedef struct s_img
{
	t_solib_windows *win;
	void *img_ptr;
	char *addr;
	int h;
	int w;
	int x;
	int y;
	int bpp;
	int endian;
	int line_len;
} t_img;

t_img new_img(int w, int h, t_solib *solib)
{
	t_img image;

	// Calcul du ratio d'aspect original de l'image
	float image_ratio = (float)w / h;

	// Calcul du ratio d'aspect de la fenêtre
	solib->windows->ratio = (float)(solib->windows->width / solib->windows->height);

	// Calcul de la nouvelle largeur et hauteur en conservant le ratio d'aspect original
	int new_width, new_height;

	if (solib->windows->ratio > image_ratio)
	{
		// La fenêtre est plus large que l'image, ajuster en fonction de la hauteur
		new_height = solib->windows->height;
		new_width = (int)(new_height * image_ratio);
	}
	else
	{
		// La fenêtre est plus haute que l'image, ajuster en fonction de la largeur
		new_width = solib->windows->width;
		new_height = (int)(new_width / image_ratio);
	}

	// Calcul des coordonnées de début pour centrer l'image
	int x_offset = (solib->windows->width - new_width) / 2;
	int y_offset = (solib->windows->height - new_height) / 2;

	// Création de la nouvelle image avec la taille ajustée et centrée
	image.win = solib->windows;
	image.img_ptr = mlx_new_image(solib->minilibx, new_width, new_height);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
								   &(image.line_len), &(image.endian));
	image.w = new_width;
	image.h = new_height;

	// Mise à jour des coordonnées de début de l'image
	image.x = x_offset;
	image.y = y_offset;

	return image;
}

t_img new_file_img(char *path, t_solib *solib)
{
	t_img image;

	image.win = solib->windows;
	image.img_ptr = mlx_xpm_file_to_image(solib->minilibx, path, &image.w, &image.h);
	if (!image.img_ptr)
		write(2, "File could not be read\n", 23);
	else
		image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
									   &(image.line_len), &(image.endian));
	return (image);
}

void destroy_image(t_solib *solib, t_img img)
{
	if (img.img_ptr && solib->minilibx)
		mlx_destroy_image(solib->minilibx, img.img_ptr);
}

void put_pixel_img(t_img img, float x, float y, int color)
{
	char *dst;

	if (color == (int)0xFF000000)
		return;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + ((int)y * img.line_len + (int)x * (img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.line_len) + (x * img.bpp / 8))));
}


void put_img_to_img(t_img dst, t_img src, int pos_x, int pos_y, float width, float height)
{
	int index;
	float ratio_x;
	float ratio_y;

	int	i;
	int j;

	ratio_x = src.w / width ;
	ratio_y = src.h / height;

	printf("ratiox : %0.3f -- ratioy : %0.3f\n", ratio_x, ratio_y);

	// Accès aux composantes R, G, B du pixel
	i = 0;
	for (float y = 0; y < src.h; y += ratio_y)
	{
		j = 0;
		for (float x = 0; x < src.w; x += ratio_x)
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
	t_img base_image;
	t_img bg;
	t_img ring;

	base_image = new_img(1920, 1080, solib);
	bg = new_file_img("test.xpm", solib);
	if (!bg.img_ptr)
		return (2);
	put_img_to_img(base_image, bg, 0, 0, 0, 0);
	ring = new_file_img("ring.xpm", solib);
	if (!ring.img_ptr)
		return (2);
	printf("ring %d - %d - %d\n", ring.bpp, ring.line_len, ring.endian);
	put_img_to_img(base_image, ring, 50, 100, 100, 100);
	mlx_put_image_to_window(solib->minilibx, solib->windows->window, base_image.img_ptr, base_image.x, base_image.y);
	mlx_loop_hook(solib->minilibx, solib_loop, solib);
	mlx_loop(solib->minilibx);
	solib_close(solib);
	return (FALSE);
}