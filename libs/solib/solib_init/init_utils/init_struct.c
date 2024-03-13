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


void destroy_image(t_solib *solib, t_solib_image img)
{
	if (img.data->img_ptr && solib->minilibx)
		mlx_destroy_image(solib->minilibx, img.data->img_ptr);
}

t_solib_display	*solib2d(t_solib *solib, float resolution_x, float resolution_y)
{
	t_solib_display *display;

	display = (t_solib_display *)solib_malloc(solib, sizeof(t_solib_display));
	display->solib = solib;
	display->resolution = solib_new_vector2(solib, resolution_x, resolution_y);

	solib->windows->ratio = ((float)solib->windows->width / (float)solib->windows->height);
	display->ratio = (resolution_x / resolution_y);

	if (solib->windows->ratio > display->ratio)
		display->size = solib_new_size(solib, (int)((float)solib->windows->height * display->ratio), solib->windows->height);
	else
		display->size = solib_new_size(solib, solib->windows->width, (int)((float)solib->windows->width / display->ratio));

	printf("----\nhori :\nresolution_x : %0.2f\n win_x : %d\nratio : %0.6f\nnew width : %0.2f\n--\nhori :\nresolution_x : %0.2f\n win_x : %d\nratio : %0.6f\nnew height : %0.2f\n--------\n", resolution_x, solib->windows->width, solib->windows->ratio, display->size->width, resolution_y, solib->windows->height, display->ratio, display->size->height);
	// Calcul des coordonnées de début pour centrer l'image
	display->pos = solib_new_vector2(solib, (solib->windows->width - display->size->width) / 2, (solib->windows->height - display->size->height) / 2);

	display->area = solib_new_image(solib, display->pos, display->size, NULL);
	solib->display = display;
	return (display);
}

t_solib_image *new_file_img(char *path, t_solib *solib)
{
	t_solib_image *image;
	int				width;
	int				height;
	image = (t_solib_image *)solib_malloc(solib, sizeof(t_solib_image));
	image->data = (t_solib_image_data *)solib_malloc(solib, sizeof(t_solib_image_data));
	image->data->img_ptr = mlx_xpm_file_to_image(solib->minilibx, path, &width, &height);
	image->size = solib_new_size(solib, width, height);
	if (!image->data->img_ptr)
		write(2, "File could not be read\n", 23);
	else
		image->data->addr = mlx_get_data_addr(image->data->img_ptr, &(image->data->bpp),
											 &(image->data->line_len), &(image->data->endian));
	return (image);
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

unsigned int get_pixel_img(t_solib_image *img, int x, int y)
{
	return (*(unsigned int *)((img->data->addr + (y * img->data->line_len) + (x * img->data->bpp / 8))));
}

void put_img_to_img(t_solib *solib, t_solib_image *dst, t_solib_image *src, int pos_x, int pos_y, float width, float height)
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

	ratio_x = src->size->width / width;
	ratio_y = (float)src->size->height / height;
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

void put_img_to_img_2(t_solib *solib, t_solib_image *dst, t_solib_image *src, int pos_x, int pos_y, float width, float height)
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

	ratio_x = (float)src->size->width / width;
	ratio_y = (float)src->size->height / height;
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