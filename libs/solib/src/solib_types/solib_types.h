/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:57:58 by marvin            #+#    #+#             */
/*   Updated: 2024/03/15 20:01:31 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_TYPES_H
# define SOLIB_TYPES_H

# include "solib_types_time.h"
# include "solib_err.h"

typedef struct s_solib_vector2 {
	float	x;
	float	y;
}	t_solib_vector2;

typedef struct s_solib_quate {
	float	x;
	float	y;
	float	z;
}	t_solib_quate;

typedef struct s_solib_size {
	int	width;
	int	height;
}	t_solib_size;

typedef struct s_solib_transform {
	t_solib_vector2	*origin;
	t_solib_size	*size;
}	t_solib_transform;

typedef struct s_solib_events {
	int	(*key_press)(t_solib *solib, int keycode);
	int	(*key_release)(t_solib *solib, int keycode);
}	t_solib_events;

typedef struct s_solib_keys {
	char	*name;
	t_bool	pressed;
}	t_solib_keys;

typedef struct s_solib_inputs {
	t_solib_vector2	mouse_position;
	int				level;
	t_bool			keys[256];
}	t_solib_inputs;

// Structure représentant une fenetre
typedef struct s_solib_windows {
	char	*name;
	void	*window;
	int		width;
	int		height;
	float	ratio;
}	t_solib_windows;

typedef struct s_solib_time {
	t_solib_ticks	ticks;
	t_solib_clock	update;
	t_solib_clock	render;
}	t_solib_time;

typedef struct s_solib_memory {
	void			*ptr;
	t_solib_memory	*next;
}	t_solib_memory;

typedef struct s_solib_image_data
{
	t_solib_size		*size;
	void *img_ptr;
	char *addr;
	int bpp;
	int endian;
	int line_len;
} t_solib_image_data;


typedef struct s_solib_button
{
	t_solib_size		*size;
	t_solib_image_data	*data;
} t_solib_button;

typedef struct s_solib_image_set
{
	int				(*transform)(t_solib_image *image, t_solib_transform transform);
} t_solib_image_set;

typedef struct s_solib_image_get
{
} t_solib_image_get;

typedef struct s_solib_image_func
{
	int				(*set)(t_solib_canvas *canva, t_solib_image *image);
	int				(*get)(t_solib_canvas *canva, char *name);
	int				(*enabled)(t_solib_canvas *canva, t_solib_image *image, t_bool enabled);
	int				(*remove)(t_solib_canvas *canva, t_solib_image *image);
} t_solib_image_func;

typedef struct {
	t_bool	is_image;
	t_solib_transform	*transform; // 41 par 39
	char	*adress; //addr // j'ai
	void	*ptr;	
	int bpp;
	int endian;
	int line_len;
} t_solib_sprite_data;

typedef struct {		// j'ai
	t_solib_construct	*construct; // j'ai
	t_solib_vector2		*ratio;
	t_solib_sprite_data	*origin; // 41 par 39
	t_solib_sprite_data	*data;
} t_solib_sprite;

typedef struct s_solib_image
{
	t_solib_construct	*construct;
	t_solib_transform	*tranform; // tranforme 1920 x 1080
    t_solib_sprite		*sprite;
} t_solib_image;

typedef struct s_solib_canvas {
	t_solib_construct	*construct;
	t_solib_vector2		*ratio;
	t_solib_sprite		*background;
}	t_solib_canvas;

typedef struct s_solib_display {
	t_solib_sprite		*area; 
	t_solib_canvas		*current;
	t_solib_canvas		*canvas;
}	t_solib_display;

typedef struct s_solib_construct {
	char	*name;
	char	*args;
	t_bool	enabled;
}	t_solib_construct;

typedef struct s_solib_funcs {
	void	*environement;
	int		(*func1)(t_solib *solib, void *environement);
	int		(*func2)(t_solib *solib, void *environement);
}	t_solib_funcs;

typedef struct s_solib_new
{
	t_solib_transform	*(*transform)(t_solib *solib, t_solib_vector2 *vector2, t_solib_size *size);
	t_solib_quate		*(*quate)(t_solib *solib, float x, float y, float z);
    t_solib_construct	*(*construct)(t_solib *solib, char *name, char *args, t_bool enabled);
    t_solib_vector2	*(*vector2)(t_solib *solib, float x, float y);
    t_solib_size	*(*size)(t_solib *solib, float width, float height);
    t_solib_display	*(*display)(t_solib *solib, t_solib_construct *construct);
    t_solib_canvas	*(*canvas)(t_solib *solib, t_solib_construct *construct, t_solib_transform	*transform);
    t_solib_image	*(*image)(t_solib_image *parent, t_solib_construct *construct, t_solib_transform *transform);
    t_solib_funcs	*(*so)(t_solib *solib, void *environement, int (*start)(t_solib *solib, void *environement), int (*update)(t_solib *solib, void *environement));
} t_solib_new;

typedef struct s_solib_func
{
	int		(*on_destroy)(t_solib *solib, void *environement);
	int		(*upate)(t_solib *solib, void *environement);
    int		(*render)(t_solib *solib, void *environement);
    int		(*start)(t_solib *solib, void *environement);
} t_solib_func;

typedef struct s_solib_get
{
} t_solib_get;

typedef struct s_solib_set
{
} t_solib_set;

typedef struct s_solib_remove
{
} t_solib_remove;

// Structure représentant solib
typedef struct s_solib{
	void			*minilibx;
	t_solib_display	*display;
	t_solib_windows	*windows;
	t_solib_inputs	*inputs;
	t_solib_events	*events;
	t_solib_time	*time;
	t_solib_memory	*memory;
	t_solib_new		*new;
	t_solib_func	*func;
	void			*environement;
	int				target_frame;
	int				(*close)(t_solib *solib);
	int				(*start)(t_solib *solib, t_solib_construct *construct, t_solib_vector2 *vector2, t_solib_funcs *init);
	void			*(*malloc)(t_solib *solib, int size);
	t_bool			(*free)(t_solib *solib, void *ptr);
}	t_solib;

#endif