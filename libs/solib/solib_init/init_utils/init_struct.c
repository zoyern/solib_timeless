/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:06:48 by marvin            #+#    #+#             */
/*   Updated: 2024/03/15 20:19:42 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib_init.h"

typedef struct	s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_solib *solib;
}				t_data;

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

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

t_solib_transform *solib_new_transform(t_solib *solib, t_solib_vector2 *vector2, t_solib_size *size, t_solib_quate *quate)
{
	t_solib_transform *transform;

	transform = (t_solib_transform *)solib_malloc(solib, sizeof(t_solib_transform));
	transform->pos = vector2;
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

void solib_put_pixel_img(t_solib_image *img, float x, float y, int color)
{
	char *dst;

	if (color == (int)0xFF000000)
		return;
	if (x >= 0 && y >= 0 && x < img->tranform->size->width && y < img->tranform->size->height)
	{
		dst = img->data->addr + ((int)y * img->data->line_len + (int)x * (img->data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int solib_get_pixel_img(t_solib_image *img, int x, int y)
{
	return (*(unsigned int *)((img->data->addr + (y * img->data->line_len) + (x * img->data->bpp / 8))));
}

/*void solib_put_image(t_solib_image *parent, t_solib_image *child, t_solib_transform *transform)
{
	int index;
	float ratio_x;
	float ratio_y;
	float ratio_x2;
	float ratio_y2;
	float test_x;
	float test_y;
	//float vec_x;
	//float vec_y;
	//float ratio_display;
	float y;
	float x;

	y = 0;
	x = 0;

	//ratio_x = child->size->width / transform->size->width;
	//ratio_y = child->size->height / transform->size->height;
	//test_x = transform->size->width / parent->size->width;
	//test_y = transform->size->height / parent->size->height;
	(void)test_x;
	(void)test_y;

	//float size_w =  child->size->width  (parent->display->resolution->x / parent->display->size->width);
	//float size_h =  child->size->height (parent->display->resolution->y / parent->display->size->height);

	//ratio_x2 = child->data->size->width / size_w;
	//ratio_y2 = child->data->size->height / size_h;
	//vec_x = ((float)child->solib->display->resolution->x / (float)child->solib->display->size->width);
	//vec_y = ((float)child->solib->display->resolution->y / (float)child->solib->display->size->height);
	//printf("display : %0.2f -- %0.2f ------ %0.2f -- %0.2f\n", (child->data->size->width * test_x) / (parent->display->resolution->x / parent->display->size->width), (child->data->size->height * test_y) / (parent->display->resolution->y / parent->display->size->height),  child->size->width, parent->display->size->height);
	//printf("display : %0.2f -- %0.2f ------ %0.3f -- %0.3f\n", parent->data->size->width , parent->data->size->height , parent->size->width, parent->size->height);
	//printf("x %d - y %d -- ratiox : %0.3f -- ratioy : %0.3f -- ratiox : %0.3f -- ratioy : %0.3f\n - width : %0.3f -- height : %0.3f\n - width : %0.3f -- height : %0.3f\n\n", (int)((float)transform->pos->x + x + parent->pos->x), (int)((float)transform->pos->y + y + parent->pos->y), ratio_x, ratio_y,ratio_x2, ratio_y2, transform->size->width, transform->size->height, size_w, size_h);

	while (y < size_h )
	{
		x = 0;
		while (x < size_w)
		{
			//printf("%0.3f --- %0.3f --- %0.3f --- %3d --- %3d\n", x, (float)(transform->size->width * ratio_x / vec_x), (float)(transform->size->height * ratio_y / vec_y), (int)(x * vec_x), (int)(y * vec_y));
			index = solib_get_pixel_img(child,(int)( x * ratio_x2 / 1.2f), (int)( y * ratio_y2 / 1.2f));
			//printf("%d:%d,", (int)( x * ratio_x2),  (int)( y * ratio_y2));
			(void)index;
			solib_put_pixel_img(parent, (int)(transform->pos->x + x), (int)(y + transform->pos->y), index);
			x++;
		}
		//printf(" t - %d -- %d\n", (int)( x * ratio_x), (int)( y * ratio_y));
		//printf("\n");
		y++;
	}
	//printf("\n\n\n\n");
}*/

/*void put_img_to_img_2(t_solib *solib, t_solib_image *dst, t_solib_image *src, int pos_x, int pos_y, float width, float height)
{
	int index;
	float ratio_x;
	float ratio_y;
	//float ratio_display;
	float y;
	float x;

	y = 0;
	x = 0;

	//ratio_x = (float)src->size->width / width;
	//ratio_y = (float)src->size->height / height;

	//printf("x %d - y %d -- ratiox : %0.3f -- ratioy : %0.3f\n - width : %0.3f -- height : %0.3f\n - width : %0.3f -- height : %0.3f\n\n", (int)((float)pos_x + x + solib->display->pos->x), (int)((float)pos_y + y + solib->display->pos->y), ratio_x, ratio_y, width, height, (float)(width / vec_x), (float)(height / vec_y));

	while (y < (float)((height / solib->display->ratio)))
	{
		x = 0;
		while (x < (float)(width / solib->display->ratio))
		{
			index = solib_get_pixel_img(src,(int)(x  * ratio_x *  solib->display->ratio), (int)(y * ratio_y * solib->display->ratio));
			solib_put_pixel_img(dst, (int)((float)pos_x + x), (int)((float)pos_y + y), index);
			x++;
		}
		y++;
	}
}*/

t_solib_image_data *solib_new_image_data(t_solib *solib, t_solib_image *image, char *background)
{
	t_solib_image_data *data;
	int width;
	int height;

	(void)image;
	width = 0;
	height = 0;

	data = (t_solib_image_data *)solib_malloc(solib, sizeof(t_solib_image_data));
	if (!background)
	{
		// data->img_ptr = mlx_new_image(solib->minilibx, image->size->width, image->size->height);
		// width = image->size->width;
		// height = image->size->height;
	}
	else
	{
		data->img_ptr = mlx_xpm_file_to_image(solib->minilibx, background, &width, &height);
		if (!data->img_ptr)
		{
			// data->img_ptr = mlx_new_image(solib->minilibx, image->size->width, image->size->height);
			// width = image->size->width;
			// height = image->size->height;
			write(2, "File could not be read\n", 23);
		}
	}
	data->size = solib->new->size(solib, width, height);
	data->addr = mlx_get_data_addr(data->img_ptr, &(data->bpp),
								   &(data->line_len), &(data->endian));
	return (data);
}

/*t_solib_image *solib_new_image_tmp(t_solib_image *parent, t_solib_construct *construct, t_solib_transform *transform)
{
	t_solib_image *image;

	image = (t_solib_image *)solib_malloc(parent->solib, sizeof(t_solib_image));
	image->solib = parent->solib;
	image->canva = parent->canva;
	image->name = construct->name;
	image->link = construct->args;
	image->buttons = NULL;
	image->data = solib_new_image_data(parent->solib, image, construct->args);
	//
	// j'ai une image avec un data sa size original je veux sa size afficher
	//
	//image->size = transform->size;
	//printf("image created size : %0.2f -- %0.2f ------ %0.2f -- %0.2f ------ %0.2f -- %0.2f\n\n",image->size->width , image->size->height , image->data->size->width, image->data->size->height, transform->size->width, transform->size->height);
	//scale avec la taille de la fenetre si la fenetre augmente la taille reste a la meme resolution sur la grille
	solib_put_image(parent, image,
		parent->solib->new->transform(
			parent->solib,
			transform->pos,
			transform->size,
			transform->quate
	));
	return (image);
}*/

t_solib_image *solib_new_image(t_solib *solib, t_solib_construct *construct, t_solib_transform *transform)
{
	t_solib_image *image;

	(void)transform;
	image = (t_solib_image *)solib_malloc(solib, sizeof(t_solib_image));
	image->solib = solib;
	image->canva = NULL;
	image->name = construct->name;
	image->link = construct->args;
	image->buttons = NULL;
	image->data = solib_new_image_data(solib, image, construct->args);
	return (image);
}

void destroy_image(t_solib *solib, t_solib_image img)
{
	if (img.data->img_ptr && solib->minilibx)
		mlx_destroy_image(solib->minilibx, img.data->img_ptr);
}

int hexToDec(char *hex) {
    int decimal = 0;
    int i = 0;

    // Parcours chaque caractère de l'hexadécimal
    while (hex[i] != '\0') {
        char currentChar = hex[i];
        int currentValue;

        // Convertit le caractère hexadécimal en décimal
        if (currentChar >= '0' && currentChar <= '9') {
            currentValue = currentChar - '0';
        } else if (currentChar >= 'a' && currentChar <= 'f') {
            currentValue = 10 + currentChar - 'a';
        } else if (currentChar >= 'A' && currentChar <= 'F') {
            currentValue = 10 + currentChar - 'A';
        } else {
            printf("Caractère hexadécimal invalide: %c\n", currentChar);
            return -1;
        }

        // Met à jour la valeur décimale
        decimal = decimal * 16 + currentValue;
        i++;
    }

    return decimal;
}



void draw_image(t_solib_image *image, t_solib_transform *transform, char *color)
{
	int x;
	int y;
	//char *color_str;
	int new_color;

	(void)transform;
	y = 0;
	//color_str = ft_convert_base(color, "0123456789abcdef", "0123456789");
	new_color = hexToDec(color);
	printf("color : %d\n", new_color);
	//new_color = atoi(color_str);
	while (y < image->tranform->size->height)
	{
		x = 0;
		while (x < image->tranform->size->width)
		{
			*(unsigned int *)(image->data->addr + ((x + y * image->solib->windows->width) * (image->data->bpp / 8))) = new_color;
			x++;
		}
		y++;
	}
}

t_solib_image *solib_new_img(t_solib *solib, t_solib_construct *construct, t_solib_transform *transform)
{
	t_solib_image *image;
	int width;
	int height;

	image = (t_solib_image *)solib_malloc(solib, sizeof(t_solib_image));
	image->solib = solib;
	image->canva = NULL;
	image->name = construct->name;
	image->link = construct->args;
	image->tranform = transform;
	image->buttons = NULL;
	width = transform->size->width;
	height = transform->size->height;
	image->data = (t_solib_image_data *)solib_malloc(solib, sizeof(t_solib_image_data));
	image->data->img_ptr = mlx_xpm_file_to_image(solib->minilibx, construct->args, &width, &height);
	if (!image->data->img_ptr)
	{
		image->data->img_ptr = mlx_new_image(solib->minilibx, width, height);
		image->data->addr = mlx_get_data_addr(image->data->img_ptr, &(image->data->bpp),
											  &(image->data->line_len), &(image->data->endian));
		if (construct->args)
		{
			draw_image(image, image->tranform, construct->args);
		}
	}
	else
	{
		image->data->addr = mlx_get_data_addr(image->data->img_ptr, &(image->data->bpp),
											  &(image->data->line_len), &(image->data->endian));
	}
	image->data->size = solib->new->size(solib, width, height);
	return (image);
}

void	draw_rectangle(t_data *data, char *color) {
	int		x;
	int		y;
	int		max_x;
	int		max_y;

	// Convertit la couleur hexadécimale en décimal (rouge=208, vert=115, bleu=35)
	y = 0;
	max_x = data->solib->windows->width;
	max_y = data->solib->windows->height;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			*(unsigned int *)(data->addr + ((x + y * data->solib->windows->width) * (data->bits_per_pixel / 8))) = hexToDec(color);
			x++;
		}
		y++;
	}
}



void	put_image_to_data(t_data *data, int x, int y, int width, int height, char *color) {
	int	i;
	int	j;
	int	decalage = 100;
	i = decalage;
	while (i < height)
	{
		j = decalage;
		while (j < width)
		{//                  l'addr du parent x pos j counter  taille du parent surface ecrivable
			*(unsigned int *)(data->addr + ((x + j + (y + i) * (data->solib->windows->width)) * (data->bits_per_pixel / 8))) = hexToDec(color);
			j++; // on diminue ou agrandi en fonction d'un ratio 
		}
		i++;
	}
}

// data :
// la copy de mon addr d'origine la pos x et y la size

void	put_image_to_data_test(t_data *data, int x, int y, int width, int height, char *addr) {
	int	i;
	int	j;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{//                  l'addr du parent x pos j counter  taille du parent surface ecrivable
			*(unsigned int *)(data->addr + ((x + j + (y + i) * (data->solib->windows->width)) * (data->bits_per_pixel / 8))) = *(unsigned int *)(addr + ((x + j + (y + i) * (data->solib->windows->width)) * (data->bits_per_pixel / 8)));
			j++;
		}
		i++;
	}
}

#include <string.h>

/*t_solib_image_data {
	char *image; //addr
	char *origin;
}

t_solib_image {
	t_solib_image_data = data
}*/

// j'ai besoin d'un addr d'une pos et d'une size
// si je veux afficher malloc + memcpy = copy de ce qu'il y a dans un 

typedef struct {
    int width;
    int height;
} Size;

typedef struct {
    float x;
    float y;
} ScaleRatio;

typedef struct {
    int x;
    int y;
} Position;

Size calculate_final_size(Size content_size, Size target_size) {
    // Calculer le ratio de mise à l'échelle pour la largeur et la hauteur
    float ratio_content = ((float)content_size.width / (float)content_size.height);
	float ratio_target = ((float)target_size.width / (float)target_size.height);
	Size display_size;

	if (ratio_content > ratio_target)
	{
		display_size.width = (int)((float)content_size.height * ratio_target);
		display_size.height = content_size.height;
	}
	else
	{
		display_size.width = content_size.width;
		display_size.height = (int)((float)content_size.width / ratio_target);
	}
	return (display_size);
}

t_solib_display *solib_display_init(t_solib *solib)
{
	t_solib_display *display;
	t_data	data;
	//t_data	data2;

	display = (t_solib_display *)solib_malloc(solib, sizeof(t_solib_display));
	display->solib = solib;
	display->size = solib_new_size(solib, solib->windows->width, solib->windows->height);

	data.img_ptr = mlx_new_image(solib->minilibx, solib->windows->width, solib->windows->height);
	//data2.img_ptr = mlx_new_image(solib->minilibx, solib->windows->width, solib->windows->height);
	data.addr = mlx_get_data_addr(data.img_ptr, &data.bits_per_pixel, &data.line_length, &data.endian);
	//data2.addr = mlx_get_data_addr(data2.img_ptr, &data2.bits_per_pixel, &data2.line_length, &data2.endian);
	data.solib = solib;
	//data2.solib = solib;

	printf("hey -- len : %ld addr :%s\n", strlen(data.addr), data.addr);
	//printf("hey2 -- len : %ld addr :%s\n", strlen(data2.addr), data2.addr);

	Size content_size = {1905, 900};

    // Taille cible
    Size target_size = {1920, 1080};

	

	Size final_size = calculate_final_size(content_size, target_size);

	 printf("Ratio de mise a l'echelle : %d - %d\n", final_size.width, final_size.height);

	//draw_rectangle(&data, "d07323");
	put_image_to_data(&data, 0, 0, 1905, 900, "171717");
	//put_image_to_data(&data2, 0, 0, 400, 500, "4886E4");
	float	posx = ((float)solib->windows->width - final_size.width) / 2;
	float	posy = ((float)solib->windows->height - final_size.height) / 2;

	//float resolutionx = 1920; // dois faire ma fenetre final dans ma fenetre principal
	//float resolutiony = 1080;

	//float	windoww	= 1905; // fenetre principal

	//float	windowh = 900;


	//float ratiox = (float)windoww / (float)resolutionx;
	//float ratioy = (float)windowh / (float)resolutiony;

	printf("- %d - %d --- %0.2f - %0.2f\n", (int)(final_size.width), (int)(final_size.height), posx, posy);
	(void)posx;
	(void)posy;
	put_image_to_data(&data, (int)posx - 1, (int)posy, (int)(final_size.width), (int)(final_size.height), "212121");
	//put_image_to_data(&data, 600, 200, 250, 250, "35140D");

	//put_image_to_data_test(&data, 0, 0, 400, 600, data2.addr);

	mlx_put_image_to_window(solib->minilibx, solib->windows->window, data.img_ptr, 0, 0);

	/*display->area = solib_new_img(
		solib,
		solib->new->construct(
			solib,
			"display",
			"d07323"),
		solib->new->transform(
			solib,
			solib->new->vector2(solib, 0, 0),
			display->size,
			solib->new->quate(solib, 0, 0, 0)));*/
	return (display);

	/*solib->windows->ratio = ((float)solib->windows->width / (float)solib->windows->height);
	display->ratio = (resolution_x / resolution_y);

	if (solib->windows->ratio > display->ratio)
		display_size = solib_new_size(solib, (int)((float)solib->windows->height * display->ratio), solib->windows->height);
	else
		display_size = solib_new_size(solib, solib->windows->width, (int)((float)solib->windows->width / display->ratio));

	printf("----\nhori :\nresolution_x : %0.2f\n win_x : %d\nratio : %0.6f\nnew width : %0.2f\n--\nhori :\nresolution_x : %0.2f\n win_x : %d\nratio : %0.6f\nnew height : %0.2f\n--------\n", resolution_x, solib->windows->width, solib->windows->ratio, display->size->width, resolution_y, solib->windows->height, display->ratio, display->size->height);
	// Calcul des coordonnées de début pour centrer l'image
	solib->display = display;
	display->area = solib_new_image(
		solib,
		solib->new->construct(solib, "display", NULL),
		solib->new->transform(
			solib,
			display->pos,
			display_size,
			solib->new->quate(solib, 0, 0, 0)
		));
	return (display);*/
}

// je creer

t_solib_canvas *solib_new_canvas(t_solib_display *display, t_solib_construct *construct, t_solib_transform *transform)
{
	if (!display)
		return (NULL);
	t_solib_canvas *canva;

	canva = (t_solib_canvas *)solib_malloc(display->solib, sizeof(t_solib_canvas));
	canva->solib = display->solib;
	canva->display = display;
	canva->name = construct->name;
	canva->link = construct->args;
	canva->pos = transform->pos;
	canva->size = transform->size;
	canva->quate = transform->quate;
	canva->background = NULL;
	canva->images = NULL;
	canva->buttons = NULL;
	/*canva->background = solib_new_image_tmp(display->area, construct,
							display->solib->new->transform(
								display->solib,
								transform->pos,
								transform->size,
								transform->quate));*/
	return (canva);
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