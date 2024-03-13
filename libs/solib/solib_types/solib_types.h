/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:57:58 by marvin            #+#    #+#             */
/*   Updated: 2024/03/11 11:39:57 by almounib         ###   ########.fr       */
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
	float	width;
	float	height;
}	t_solib_size;

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
	t_solib_vector2		*pos;
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

typedef struct s_solib_image
{
	t_solib			*solib;
	t_solib_display	*display;
	t_solib_canvas 	*canva;
	unsigned long		id;
	char				*name;
	char				*link;
	t_solib_vector2		*pos;
	t_solib_size		*size;
	t_solib_quate		*quate;
	t_solib_image_data	*data;
	t_solib_image_set	*set;
	t_solib_image_get	*get;
	t_solib_button	*buttons;
} t_solib_image;

typedef struct s_solib_canvas {
	t_solib			*solib;
	t_solib_display	*display;
	unsigned long	id;
	char			*name;
	char			*link;
	t_solib_vector2		*pos;
	t_solib_size		*size;
	t_solib_quate		*quate;
	t_solib_image	*background;
	t_solib_image_func	*images;
	t_solib_button	*buttons;
}	t_solib_canvas;

typedef struct s_solib_display {
	t_solib				*solib;
	t_solib_image		*area;
	t_solib_vector2		*pos;
	float				ratio;
	t_solib_size		*size;
	t_solib_vector2		*resolution;
	t_solib_canvas		*current;
	t_solib_canvas		*canvas;
	//add canvas
	//get canvas
}	t_solib_display;

typedef struct s_solib_construct {
	char	*name;
	char	*args;
}	t_solib_construct;

typedef struct s_solib_transform {
	t_solib_vector2 *pos;
	t_solib_size *size;
	t_solib_quate *quate;
}	t_solib_transform;

typedef struct s_solib_new
{
	t_solib_transform	*(*transform)(t_solib *solib, t_solib_vector2 *vector2, t_solib_size *size,t_solib_quate *quate);
	t_solib_quate		*(*quate)(t_solib *solib, float x, float y, float z);
    t_solib_construct	*(*construct)(t_solib *solib, char *name, char *args);
    t_solib_vector2	*(*vector2)(t_solib *solib, float x, float y);
    t_solib_size	*(*size)(t_solib *solib, float width, float height);
    t_solib_canvas	*(*canvas)(t_solib_display *display, t_solib_construct *construct, t_solib_transform	*transform);
    t_solib_image	*(*image)(t_solib_canvas *canvas, t_solib_construct *construct, t_solib_transform *transform);
} t_solib_new;


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
	int				target_frame;
	int				(*close)(t_solib *solib);
}	t_solib;

#endif