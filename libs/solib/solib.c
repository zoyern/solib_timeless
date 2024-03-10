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
char	*ft_get_base(int base, int lower)
{
	char	*all_digits;
	char	*res;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (base + 1));
	if (!res)
		return (NULL);
	if (lower)
		all_digits = "0123456789abcdef";
	else
		all_digits = "0123456789ABCDEF";
	i = -1;
	while (++i < base)
		res[i] = all_digits[i];
	res[base] = '\0';
	return (res);
}


unsigned long	ft_unbrlen_base(size_t n, int base)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

char	*ft_uitoa_base(size_t n, size_t base, char *ref_base)
{
	size_t	size;
	char	*result;

	if (base < 2 || base > 16)
		return (NULL);
	size = ft_unbrlen_base(n, base);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size--] = 0;
	if (!n)
		result[0] = '0';
	while (n > 0)
	{
		result[size--] = ref_base[n % base];
		n /= base;
	}
	return (result);
}

char	*ft_uputnnbr_base(unsigned int nb, int base, int lower)
{
	char			*num;
	char			*ref_base;

	ref_base = ft_get_base(base, lower);
	num = ft_uitoa_base(nb, base, ref_base);
	if (!num)
		return (NULL);
	free(ref_base);
	return (num);
}

t_solib_vector2 *solib_new_vector2(t_solib *solib, float x, float y)
{
	t_solib_vector2 *vector2;

	vector2 = (t_solib_vector2 *)solib_malloc(solib, sizeof(t_solib_vector2));
	vector2->x = x;
	vector2->y = y;
	return (vector2);
}

t_solib_resolution *solib_new_resolution(t_solib *solib, float x, float y)
{
	t_solib_resolution *resolution;

	resolution = (t_solib_resolution *)solib_malloc(solib, sizeof(t_solib_resolution));
	resolution->x = x;
	resolution->y = y;
	return (resolution);
}

t_solib_size *solib_new_size(t_solib *solib, int width, int height)
{
	t_solib_size *size;

	size = (t_solib_size *)solib_malloc(solib, sizeof(t_solib_size));
	size->width = width;
	size->height = height;
	return (size);
}

t_solib_image_data *solib_new_image_data(t_solib *solib, t_solib_image *image, char *background)
{
	t_solib_image_data	*data;
	/*int					width;
	int					height;

	width = 0;
	height = 0;*/

	data = (t_solib_image_data *)solib_malloc(solib, sizeof(t_solib_image_data));
	if (!background)
		data->img_ptr = mlx_new_image(solib->minilibx, image->size->width, image->size->height);
	/*else
	{
		data->img_ptr = mlx_xpm_file_to_image(solib->minilibx, background, &width, &height);
		if (!data->img_ptr)
		{
			data->img_ptr = mlx_new_image(solib->minilibx, image->size->width, image->size->height);
			write(2, "File could not be read\n", 23);
		}
	}*/
	data->addr = mlx_get_data_addr(data->img_ptr, &(data->bpp),
								   &(data->line_len), &(data->endian));
	return (data);
}

t_solib_image *solib_new_image(t_solib *solib, t_solib_vector2 *pos, t_solib_size *size, char *background)
{
	t_solib_image *image;

	image = (t_solib_image *)solib_malloc(solib, sizeof(t_solib_image));
	image->size = size;
	image->pos = pos;
	image->data = solib_new_image_data(solib, image, background);
	return (image);
}

int	ft_absolute(float value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}



void solib2d(t_solib *solib, float resolution_x, float resolution_y)
{
	t_solib_display *display;

	display = (t_solib_display *)solib_malloc(solib, sizeof(t_solib_display));
	display->solib = solib;
	display->resolution = solib_new_resolution(solib, resolution_x, resolution_y);

	solib->windows->ratio = ((float)solib->windows->width / (float)solib->windows->height);
	display->ratio = (resolution_x / resolution_y);

	if (solib->windows->ratio > display->ratio)
		display->size = solib_new_size(solib, (int)((float)solib->windows->height * display->ratio), solib->windows->height);
	else
		display->size = solib_new_size(solib, solib->windows->width, (int)((float)solib->windows->width / display->ratio));

	printf("----\nhori :\nresolution_x : %0.2f\n win_x : %d\nratio : %0.6f\nnew width : %d\n--\nhori :\nresolution_x : %0.2f\n win_x : %d\nratio : %0.6f\nnew height : %d\n--------\n", resolution_x, solib->windows->width, solib->windows->ratio, display->size->width, resolution_y, solib->windows->height, display->ratio, display->size->height);
	// Calcul des coordonnées de début pour centrer l'image
	display->pos = solib_new_vector2(solib, (solib->windows->width - display->size->width) / 2, (solib->windows->height - display->size->height) / 2);

	display->area = solib_new_image(solib, display->pos, display->size, NULL);
	solib->display = display;
}


t_solib_image new_file_img(char *path, t_solib *solib)
{
	t_solib_image image;

	image.size = solib_new_size(solib, 0, 0);
	image.data = (t_solib_image_data *)solib_malloc(solib, sizeof(t_solib_image_data));
	image.data->img_ptr = mlx_xpm_file_to_image(solib->minilibx, path, &image.size->width, &image.size->height);
	if (!image.data->img_ptr)
		write(2, "File could not be read\n", 23);
	else
		image.data->addr = mlx_get_data_addr(image.data->img_ptr, &(image.data->bpp),
											 &(image.data->line_len), &(image.data->endian));
	return (image);
}

void destroy_image(t_solib *solib, t_solib_image img)
{
	if (img.data->img_ptr && solib->minilibx)
		mlx_destroy_image(solib->minilibx, img.data->img_ptr);
}

void put_pixel_img(t_solib_image *img, float x, float y, int color)
{
	char *dst;

	if (color == (int)0xFF000000)
		return;
	if (x >= 0 && y >= 0 && x < img->size->width && y < img->size->height)
	{
		dst = img->data->addr + ((int)y * img->data->line_len + (int)x * (img->data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int get_pixel_img(t_solib_image img, int x, int y)
{
	return (*(unsigned int *)((img.data->addr + (y * img.data->line_len) + (x * img.data->bpp / 8))));
}

void put_img_to_img(t_solib *solib, t_solib_image *dst, t_solib_image src, int pos_x, int pos_y, float width, float height)
{
	int index;
	float ratio_x;
	float ratio_y;
	float vec_x;
	float vec_y;
	//float ratio_display;
	float y;
	float x;

	y = 0;
	x = 0;

	ratio_x = (float)src.size->width / width;
	ratio_y = (float)src.size->height / height;
	vec_x = ((float)solib->display->resolution->x / (float)solib->display->size->width);
	vec_y = ((float)solib->display->resolution->y / (float)solib->display->size->height);

	printf("x %d - y %d -- ratiox : %0.3f -- ratioy : %0.3f\n - width : %0.3f -- height : %0.3f\n - width : %0.3f -- height : %0.3f\n\n", (int)((float)pos_x + x + solib->display->pos->x), (int)((float)pos_y + y + solib->display->pos->y), ratio_x, ratio_y, width, height, (float)(width / vec_x), (float)(height / vec_y));

	while (y < (float)((height / vec_y)))
	{
		x = 0;
		while (x < (float)(width / vec_x))
		{
			index = get_pixel_img(src,(int)(x  * ratio_x *  vec_x), (int)(y * ratio_y * vec_x));
			put_pixel_img(dst, (int)((float)pos_x + x), (int)((float)pos_y + y), index);
			x++;
		}
		y++;
	}
}

void put_img_to_img_2(t_solib *solib, t_solib_image *dst, t_solib_image src, int pos_x, int pos_y, float width, float height)
{
	int index;
	float ratio_x;
	float ratio_y;
	float vec_x;
	float vec_y;
	//float ratio_display;
	float y;
	float x;

	y = 0;
	x = 0;

	ratio_x = (float)src.size->width / width;
	ratio_y = (float)src.size->height / height;
	vec_x = ((float)solib->display->resolution->x / (float)solib->display->size->width);
	vec_y = ((float)solib->display->resolution->y / (float)solib->display->size->height);

	printf("x %d - y %d -- ratiox : %0.3f -- ratioy : %0.3f\n - width : %0.3f -- height : %0.3f\n - width : %0.3f -- height : %0.3f\n\n", (int)((float)pos_x + x + solib->display->pos->x), (int)((float)pos_y + y + solib->display->pos->y), ratio_x, ratio_y, width, height, (float)(width / vec_x), (float)(height / vec_y));

	while (y < (float)((height / solib->display->ratio)))
	{
		x = 0;
		while (x < (float)(width / solib->display->ratio))
		{
			index = get_pixel_img(src,(int)(x  * ratio_x *  solib->display->ratio), (int)(y * ratio_y * solib->display->ratio));
			put_pixel_img(dst, (int)((float)pos_x + x), (int)((float)pos_y + y), index);
			x++;
		}
		y++;
	}
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

	/*const char *hex = "33A4FB";

    long decimal;

    char *endptr;


    decimal = strtol(hex, &endptr, 16);


    if (*endptr != '\0') {

        printf("Error: Invalid hexadecimal number.\n");

        return 1;

    }


    printf("Decimal: %ld\n", decimal);*/

	solib2d(solib, 4096, 2160);
	bg = new_file_img("test.xpm", solib);
	if (!bg.data->img_ptr)
		return (2);
	//scale avec la taille de la fenetre si la fenetre augmente la taille augmente aussi 
	put_img_to_img(solib, solib->display->area, bg, 0, 0, solib->display->resolution->x, solib->display->resolution->y);
	ring = new_file_img("ring.xpm", solib);
	if (!ring.data->img_ptr)
		return (2);
	//scale avec la taille de la fenetre si la fenetre augmente la taille reste a la meme resolution sur la grille
	put_img_to_img_2(solib, solib->display->area, ring, 0, 0, 50, 50);
	mlx_put_image_to_window(solib->minilibx, solib->windows->window, solib->display->area->data->img_ptr, solib->display->area->pos->x, solib->display->area->pos->y);
	mlx_loop_hook(solib->minilibx, solib_loop, solib);
	mlx_loop(solib->minilibx);
	solib_close(solib);
	return (FALSE);
}