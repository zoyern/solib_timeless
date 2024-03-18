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

t_solib_transform *solib_new_transform(t_solib *solib, t_solib_vector2 *vector2, t_solib_size *size)
{
	t_solib_transform *transform;

	transform = (t_solib_transform *)solib_malloc(solib, sizeof(t_solib_transform));
	transform->origin = vector2;
	transform->size = size;
	return (transform);
}

t_solib_construct *solib_new_construct(t_solib *solib, char *name, char *args, t_bool enabled)
{
	t_solib_construct *construct;

	construct = (t_solib_construct *)solib_malloc(solib, sizeof(t_solib_construct));
	construct->name = name;
	construct->args = args;
	construct->enabled = enabled;
	return (construct);
}

void destroy_image(t_solib *solib, t_solib_image img)
{
	if (solib->minilibx)
	{
		if (img.sprite->data->ptr)
			mlx_destroy_image(solib->minilibx, img.sprite->data->ptr);
		if (img.sprite->origin->ptr)
			mlx_destroy_image(solib->minilibx, img.sprite->origin->ptr);
	}
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


t_solib_vector2 *calculate_ratio_size(t_solib *solib, t_solib_size *content_size, t_solib_size *target_size, t_solib_size **out) {
    // Calculer le ratio de mise à l'échelle pour la largeur et la hauteur
    float ratio_content = ((float)content_size->width / (float)content_size->height);
	float ratio_target = ((float)target_size->width / (float)target_size->height);
	t_solib_vector2	*ratio;
	if (ratio_content > ratio_target)
		ratio = solib->new->vector2(solib,  (float)target_size->width / ((float)content_size->height * (float)ratio_target), (float)target_size->height / (float)content_size->height);
	else
		ratio = solib->new->vector2(solib,  (float)target_size->width / (float)content_size->width, (float)target_size->height / ((float)content_size->width / (float)ratio_target));
	*out = solib->new->size(solib, (int)((float)target_size->width / ratio->x), (int)((float)target_size->height / ratio->y));
	return (ratio);
}

void	*solib_image_xpm(t_solib *solib, t_solib_construct *construct, t_solib_size **out, t_bool *is_immage)
{
	void			*ptr;
	int				width;
	int				height;

	width = 0;
	height = 0;
	if (!construct->args)
		return (NULL);
	ptr = mlx_xpm_file_to_image(solib->minilibx, construct->args, &height, &height);
	if (!ptr)
	{
		*is_immage = FALSE;
		return (NULL);
	}
	*is_immage = TRUE;
	*out = solib->new->size(solib, width, height);
	return (ptr);
}

void	*solib_image_base(t_solib *solib,  t_solib_transform *transform, t_solib_size **out)
{
	void	*ptr;

	if (!transform->size->width || !transform->size->height)
		return (NULL);
	ptr = mlx_new_image(solib->minilibx, transform->size->width, transform->size->height);
	if (!ptr)
		return (NULL);
	*out = transform->size;
	return (ptr);
}

void	solib_sprite_adress(t_solib_sprite_data *data)
{
	data->adress = mlx_get_data_addr(data->ptr, &(data->bpp),
											  &(data->line_len), &(data->endian));
}

/*void solib_put_pixel_img(t_solib_sprite_data *data, float x, float y, int color)
{
	char *dst;

	if (color == (int)0xFF000000)
		return;
	if (x >= 0 && y >= 0 && x < data->transform->size->width && y < data->transform ->size->height)
	{
		dst = data->adress + ((int)y * data->line_len + (int)x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}*/


void	solib_fill_sprite_color(t_solib_sprite_data *data, char *color) {
	int	i;
	int	j;
	int c;
	i = 0;

	c = hexToDec(color);
	if (c < 0)
		c = hexToDec("FB335B");
	if (c < 0)
		c = 16462683;

	while (i < data->transform->size->height)
	{
		j = 0;
		while (j < data->transform->size->width)
		{//                  l'addr du parent x pos j counter  taille du parent surface ecrivable
			*(unsigned int *)(data->adress + ((j + i * data->transform->size->width) * (data->bpp / 8))) = c;
			j++; // on diminue ou agrandi en fonction d'un ratio 
		}
		i++;
	}
}

void	put_canva_display(t_solib_display *display, t_solib_canvas *canva) {
	int	i;
	int	j;
	i = 0;
	t_solib_vector2	*origin;

	origin = canva->background->data->transform->origin;
	while (i < canva->background->data->transform->size->height)
	{
		j = 0;
		while (j < canva->background->data->transform->size->width)
		{//                  l'addr du parent x pos j counter  taille du parent surface ecrivable
			*(unsigned int *)(display->area->data->adress + (((int)origin->x + j + ((int)origin->y + i) * (display->area->data->transform->size->width)) * (display->area->data->bpp / 8))) = *(unsigned int *)(canva->background->data->adress + ((j + i * canva->background->data->transform->size->width) * (canva->background->data->bpp / 8)));
			j++;
		}
		i++;
	}

	printf("hey\n");
}

/*void	*get_xpm_resized(t_solib *solib, t_solib_construct *construct, t_solib_size **out)
{
	void *ptr;

	ptr = solib_image_xpm(solib, sprite->construct, &sprite->origin->size);
	if (!ptr);
}*/

t_solib_vector2	*fill_origin_data(t_solib *solib, t_solib_sprite_data *data, t_solib_sprite_data *origin)
{
	t_solib_vector2	*ratio;
	//size_si_origin_dois_etre_mis_sans_redimentionné l'imag
	t_solib_size	*size_redem;

	ratio = calculate_ratio_size(solib, data->transform->size, origin->transform->size, &size_redem);
	int	i;
	int	j;
	int yop;
	i = 0;
	printf("origin size %d - %d\n", data->transform->size->width, data->transform->size->height);

	while (i < data->transform->size->height)
	{
		j = 0;
		while (j < data->transform->size->width)
		{
			yop = (0 + (j / ratio->x) + (0 + (i / ratio->y)) * (data->transform->size->width));
			*(unsigned int *)(data->adress + ((0 + j + (0 + i) * (data->transform->size->width)) * (data->bpp / 8))) = *(unsigned int *)(origin->adress + ((int)yop * (origin->bpp / 8)));
			j++;
		}
		i++;
	}
	return (ratio);
}

//permet de reload origin et data en fonction de construct args

void	solib_sprite_data(t_solib *solib, t_solib_sprite *sprite, t_solib_transform *transform)
{

	sprite->data = (t_solib_sprite_data  *)solib_malloc(solib, sizeof(t_solib_sprite_data ));
	sprite->origin = (t_solib_sprite_data  *)solib_malloc(solib, sizeof(t_solib_sprite_data ));

	sprite->data->is_image = FALSE;
	sprite->origin->ptr = NULL;
	sprite->origin->is_image = FALSE;
	sprite->data->transform = transform;
	sprite->origin->transform = solib->new->transform(solib, transform->origin, transform->size);
	sprite->data->ptr = solib_image_base(solib, transform, &sprite->data->transform->size);
	if (!sprite->data->ptr)
		solib_close(solib);
	if (sprite->construct->args)// calcule de origin 
			sprite->origin->ptr = solib_image_xpm(solib, sprite->construct, &sprite->origin->transform->size, &sprite->origin->is_image);
	
	if (!sprite->origin->ptr)
	{
		sprite->origin->ptr = solib_image_base(solib, sprite->data->transform, &sprite->origin->transform->size);
		if (!sprite->origin->ptr)
			solib_close(solib);
	}
	sprite->data->is_image = sprite->origin->is_image;
	solib_sprite_adress(sprite->origin);
	solib_sprite_adress(sprite->data);
	if (sprite->construct->args && !sprite->origin->is_image)
		solib_fill_sprite_color(sprite->origin, sprite->construct->args);
	sprite->ratio = fill_origin_data(solib, sprite->data, sprite->origin);
}

//creer un nouveau sprite et redimentionne a la size voulu en gardant en memoire l'origin pour reinitialisé si besoin ou changement de resolution

t_solib_sprite	*solib_new_sprite(t_solib *solib, t_solib_construct *construct, t_solib_transform *transform)
{
	t_solib_sprite	*sprite; //rend un sprite

	sprite = (t_solib_sprite *)solib_malloc(solib, sizeof(t_solib_sprite));
	sprite->construct = construct;

	solib_sprite_data(solib, sprite, transform);
	if (construct->enabled)
		printf("afficher le sprite dans l'iterface de jeux et pas dans l'interface canva\n");
	return (sprite);
}

t_solib_image	*solib_new_imagette(t_solib *solib, t_solib_construct *construct, t_solib_transform *transform)
{
	t_solib_image	*image;

	image = (t_solib_image *)solib_malloc(solib, sizeof(t_solib_image));
	image->tranform = transform;
	image->construct = construct;
	image->sprite = solib_new_sprite(solib, solib->new->construct(solib, "sprite1", construct->args, FALSE), transform);

	//modification de sprite.data
	return (image);
}

t_solib_canvas *solib_new_canvas(t_solib *solib, t_solib_construct *construct, t_solib_transform *transform)
{
	
	if (!solib->display)
		return (NULL);
	t_solib_canvas *canva;
	t_solib_size	*final_size;

	canva = (t_solib_canvas *)solib_malloc(solib, sizeof(t_solib_canvas));
	
	canva->ratio = calculate_ratio_size(solib,
									solib->display->area->data->transform->size,
									transform->size, &final_size);
	float	posx = ((float)solib->display->area->data->transform->size->width - final_size->width) / 2;
	float	posy = ((float)solib->display->area->data->transform->size->height - final_size->height) / 2;
	printf("testeeeeee : %0.2f -- %0.2f\n", transform->origin->x, transform->origin->y);
	// utilise le final size
	transform->origin->x = posx;
	transform->origin->y = posy;
	transform->size = final_size;
	canva->background = solib_new_sprite(solib,	construct, transform);
	//canva->area = solib_new_sprite(solib,	construct, transform);
	put_canva_display(solib->display, canva);
	//fill_origin_data(solib, solib->display->area->data, canva->background->data);
	return (canva);
}

t_solib_display *solib_new_display(t_solib *solib, t_solib_construct *construct)
{
	t_solib_display *display;

	display = (t_solib_display *)solib_malloc(solib, sizeof(t_solib_display));

	//put_image_to_data(&data, 0, 0, solib->windows->width, solib->windows->height, "171717");
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