/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:36:30 by marvin            #+#    #+#             */
/*   Updated: 2024/03/22 14:36:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"


unsigned long ft_strlen(const char *s)
{
	unsigned long i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(const char *s)
{
	unsigned long len;
	char *t;

	len = ft_strlen(s);
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (!t)
		return (NULL);
	while (*s)
		*t++ = *s++;
	*t = '\0';
	return (t -= len);
}

char *lower_case(char *dest, char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		if (src[i] >= 'A' && src[i] <= 'Z')
			dest[i] += 32;
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

int get_base_length(char *base)
{
	int base_length;
	int j;

	base_length = 0;
	while (base[base_length])
	{
		if (base[base_length] == '-' || base[base_length] == '+')
			return (0);
		j = base_length + 1;
		while (base[j])
		{
			if (base[base_length] == base[j])
				return (0);
			++j;
		}
		++base_length;
	}
	if (base_length < 2)
		return (0);
	return (base_length);
}

int check_errors(char *str, char *base)
{
	int i;
	int j;
	int start;

	start = 0;
	while (str[start] != '\0' && (str[start] == ' ' || str[start] == '\t' ||
								  str[start] == '\r' || str[start] == '\n' || str[start] == '\v' ||
								  str[start] == '\f'))
		start++;
	i = start;
	while (str[i])
	{
		j = 0;
		while (base[j] && (str[i] != base[j] ||
						   (str[i] == '-' || str[i] == '+')))
			++j;
		if (str[i] != base[j] && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int get_nb(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int solib_convert_color(char *color)
{
	int s;
	int i;
	int res;
	int negative;
	int base_length;

	char *base = "0123456789abcdef";
	char *str = ft_strdup(color);
	lower_case(str, color);

	if (!(base_length = get_base_length(base)) || !check_errors(str, base))
		return (0);
	s = 0;
	while (str[s] != '\0' && (str[s] == ' ' || str[s] == '\t' || str[s] == '\r' || str[s] == '\n' || str[s] == '\v' || str[s] == '\f'))
		s++;
	i = s - 1;
	res = 0;
	negative = 1;
	while (str[++i] && (((str[i] == '-' || str[i] == '+') && i == s) ||
						(str[i] != '-' && str[i] != '+')))
	{
		if (str[i] == '-')
			negative = -1;
		else if (str[i] != '+')
			res = (res * base_length) + (get_nb(str[i], base));
	}
	free(str);
	return (res * negative);
}

t_solib_vector2 *calculate_ratio_size(t_solib *solib, t_solib_size *content_size, t_solib_size *target_size, t_solib_size **out)
{
	float ratio_content = ((float)content_size->width / (float)content_size->height);
	float ratio_target = ((float)target_size->width / (float)target_size->height);
	t_solib_vector2 *ratio;
	if (ratio_content > ratio_target)
		ratio = solib->new->vector2(solib, (float)target_size->width / ((float)content_size->height * (float)ratio_target), (float)target_size->height / (float)content_size->height);
	else
		ratio = solib->new->vector2(solib, (float)target_size->width / (float)content_size->width, (float)target_size->height / ((float)content_size->width / (float)ratio_target));
	*out = solib->new->size(solib, (int)((float)target_size->width / ratio->x), (int)((float)target_size->height / ratio->y));
	return (ratio);
}

void solib_write_pixel(t_solib_sprite_data *data, int x, int y, int color)
{
	char *dst;

	dst = NULL;
	if (color == (int)0xFF000000)
		return;
	if (x >= 0 && y >= 0 && x < data->transform->size->width && y < data->transform->size->height)
	{
		dst = (data->adress + ((x + (y) * (data->transform->size->width)) * (data->bpp / 8)));
	}
	*(unsigned int *)dst = color;
}

unsigned int solib_get_pixel(t_solib_sprite_data *data, int x, int y)
{
	return (*(unsigned int *)(data->adress + ((x + (y) * (data->transform->size->width)) * (data->bpp / 8))));
}

void solib_fill_sprite_color(t_solib_sprite_data *data, char *color)
{
	int i;
	int j;
	int c;
	i = 0;
	c = solib_convert_color(color);
	if (c < 0)
		c = solib_convert_color("FB335B");
	if (c < 0)
		c = 16462683;
	while (i < data->transform->size->height)
	{
		j = 0;
		while (j < data->transform->size->width)
		{
			solib_write_pixel(data, j, i, c);
			j++;
		}
		i++;
	}
}

t_solib_vector2 *fill_origin_data(t_solib *solib, t_solib_sprite_data *data, t_solib_sprite_data *origin)
{
	t_solib_vector2 *ratio;
	// size_si_origin_dois_etre_mis_sans_redimentionné l'imag
	t_solib_size *size_redem;

	ratio = calculate_ratio_size(solib, data->transform->size, origin->transform->size, &size_redem);
	int i;
	int j;
	i = 0;
	printf("origin size %d - %d\n", data->transform->size->width, data->transform->size->height);

	while (i < data->transform->size->height)
	{
		j = 0;
		while (j < data->transform->size->width)
		{
			solib_write_pixel(data, j, i, solib_get_pixel(origin, j / ratio->x, i / ratio->y));
			j++;
		}
		i++;
	}
	return (ratio);
}

void solib_sprite_data(t_solib *solib, t_solib_sprite *sprite, t_solib_transform *transform)
{

	sprite->data = (t_solib_sprite_data *)solib->malloc(solib, sizeof(t_solib_sprite_data));
	sprite->origin = (t_solib_sprite_data *)solib->malloc(solib, sizeof(t_solib_sprite_data));

	sprite->data->is_image = FALSE;
	sprite->origin->ptr = NULL;
	sprite->origin->is_image = FALSE;
	sprite->data->transform = transform;
	sprite->origin->transform = solib->new->transform(solib, transform->origin, transform->size);
	sprite->data->ptr = solib_sprite_base(solib, transform, &sprite->data->transform->size);
	if (!sprite->data->ptr)
		solib->close(solib);
	if (sprite->construct->args)
		sprite->origin->ptr = solib_sprite_xpm(solib, sprite->construct, &sprite->origin->transform->size, &sprite->origin->is_image);
	if (!sprite->origin->ptr)
	{
		sprite->origin->ptr = solib_sprite_base(solib, sprite->data->transform, &sprite->origin->transform->size);
		if (!sprite->origin->ptr)
			solib->close(solib);
	}
	sprite->data->is_image = sprite->origin->is_image;
	solib_sprite_adress(sprite->origin);
	solib_sprite_adress(sprite->data);
	if (sprite->construct->args && !sprite->origin->is_image)
		solib_fill_sprite_color(sprite->origin, sprite->construct->args);
	sprite->ratio = fill_origin_data(solib, sprite->data, sprite->origin);
}


t_solib_sprite *solib_new_sprite(t_solib *solib, t_solib_construct *construct, t_solib_transform *transform)
{
	t_solib_sprite *sprite;

	sprite = (t_solib_sprite *)solib->malloc(solib, sizeof(t_solib_sprite));
	sprite->construct = construct;

	solib_sprite_data(solib, sprite, transform);
	if (construct->enabled)
		printf("afficher le sprite dans l'iterface de jeux et pas dans l'interface canva\n");
	return (sprite);
}