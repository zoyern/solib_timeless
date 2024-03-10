/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:57:58 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 09:43:34 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_TYPES_H
# define SOLIB_TYPES_H

# include "solib_types_time.h"
# include "solib_err.h"

typedef struct s_solib				t_solib;
typedef struct s_solib_memory		t_solib_memory;
typedef struct s_solib_memory_var	t_solib_memory_var;

typedef struct s_solib_vector2 {
	float	x;
	float	y;
}	t_solib_vector2;

typedef struct s_solib_size {
	float	width;
	float	height;
}	t_solib_size;

typedef struct s_solib_resolution {
	int		x;
	int		y;
}	t_solib_resolution;

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

typedef struct s_solib_image
{
	unsigned long		id;
	char				*link;
	t_solib_size		*size;
	t_solib_vector2		*pos;
	t_solib_image_data	*data;
} t_solib_image;

typedef struct s_solib_button
{
	t_solib_size		*size;
	t_solib_vector2		*pos;
	t_solib_image_data	*data;
} t_solib_button;

typedef struct s_solib_canvas {
	unsigned long	id;
	char			*name;
	char			*link;
	int				width;
	int				height;
	t_solib_image	background;
	t_solib_image	*images;
	t_solib_button	*buttons;
	int				(*canvas)(t_solib *solib);
	int				(*close)(t_solib *solib);
	int				(*close)(t_solib *solib);
	t_solib_memory	*next;
}	t_solib_canvas;

typedef struct s_solib_display {
	t_solib				*solib;
	t_solib_image		*area;
	t_solib_vector2		*pos;
	float				ratio;
	t_solib_size		*size;
	t_solib_resolution	*resolution;
	t_solib_canvas		*current;
	t_solib_canvas		*canvas;
	//add canvas
	//get canvas
}	t_solib_display;

typedef struct s_solib_name {
	char	*name;
	char	*args;
}	t_solib_name;

typedef struct s_solib_new
{
    t_solib_name	*(*name)(char *name, char *args);
    t_solib_vector2	*(*vector2)(float x, float y);
    t_solib_size	*(*size)(float x, float y);
    t_solib_canvas	*(*canvas)(t_solib_display *display, t_solib *solib, t_solib_name *(*name)(char *name, char *link), t_solib_vector2 *(*vector2)(float x, float y), t_solib_size *(*size)(float width, float height));
    t_solib_image	*(*image)(t_solib_canvas *canvas, t_solib_name *(*name)(char *name, char *link), t_solib_vector2 *(*vector2)(float x, float y), t_solib_size *(*size)(float width, float height));
} t_solib_new;


typedef struct s_solib_get
{
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
} t_solib_new;

typedef struct s_solib_set
{
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
} t_solib_set;

typedef struct s_solib_remove
{
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
	t_solib_canvas		*(*get_canvas)(t_solib *solib, char *name);
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