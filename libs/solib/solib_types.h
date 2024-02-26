/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:57:58 by marvin            #+#    #+#             */
/*   Updated: 2024/02/08 17:57:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_TYPES_H
# define SOLIB_TYPES_H

# include "solib_types_time.h"
# include "solib_err.h"

typedef struct s_solib t_solib;
typedef struct s_soc t_soc;

typedef enum {
	VOID_TYPE,
	CHAR_TYPE,
	SIGNED_CHAR_TYPE,
	UNSIGNED_CHAR_TYPE,
	SHORT_TYPE,
	SHORT_INT_TYPE,
	SIGNED_SHORT_TYPE,
	SIGNED_SHORT_INT_TYPE,
	UNSIGNED_SHORT_TYPE,
	UNSIGNED_SHORT_INT_TYPE,
	SIGNED_TYPE,
	SIGNED_INT_TYPE,
	UNSIGNED_TYPE,
	UNSIGNED_INT_TYPE,
	LONG_TYPE,
	LONG_INT_TYPE,
	SIGNED_LONG_TYPE,
	SIGNED_LONG_INT_TYPE,
	UNSIGNED_LONG_TYPE,
	UNSIGNED_LONG_INT_TYPE,
	LONG_LONG_TYPE,
	LONG_LONG_INT_TYPE,
	SIGNED_LONG_LONG_TYPE,
	SIGNED_LONG_LONG_INT_TYPE,
	UNSIGNED_LONG_LONG_TYPE,
	UNSIGNED_LONG_LONG_INT_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	LONG_DOUBLE_TYPE,
	STRING_TYPE,
	BOOL_TYPE,
	POINTER_TYPE,
	ENUM_TYPE,
	FUNC_TYPE,
	FUNCV_TYPE,
	FUNC_ARGS_TYPE,
} t_soc_type;

// Structure représentant un argument : 
// { TYPE, "mavalue", &intArg },
typedef struct s_soc_args{
    t_soc_type type;
    const char *name;
    void* value;
} t_soc_args;

// Structure représentant une classe dynamique

typedef struct s_soc{
	t_bool		isNull;
	const char * name; 
    t_soc_args* args;
	int			args_size;
	void* (*setvar)(t_soc *so_class, const char* varname, t_soc_type type, void *value);
	void* (*getvar)(t_soc *so_class, const char* varname);
	void *so_return;
} t_soc;

// Structure représentant les classes dynamiques
typedef struct s_so_classes{
    t_soc class_[10];
    t_soc* (*find)(t_solib *solib, const char *soc_name);
    t_soc* (*add)(t_solib *solib, const char *soc_name, t_soc_args* args);
    void* (*get)(t_solib *solib, const char *soc_name, const char* propName);
    void* (*remove)(t_solib *solib, const char *soc_name, const char* propName);
    t_soc (*construct)(t_soc_args **args, int *args_size, int num_args, ...);
} t_so_classes;

typedef struct s_solib_vector2 {
	float	x;
	float	y;
} t_solib_vector2;

typedef struct s_solib_events {
	int (*key_press)(t_solib *solib, int keycode);
	int (*key_release)(t_solib *solib, int keycode);
} t_solib_events;

typedef struct s_solib_keys {
	char	*name;
	t_bool	pressed;
} t_solib_keys;

typedef struct s_solib_inputs {
	t_solib_vector2	mousePosition;
	int				level;
	t_bool			keys[256];
} t_solib_inputs;

// Structure représentant une fenetre
typedef struct s_solib_windows {
	char	*name;
	void	*window;
	int		width;
	int		height;
	int		target_frame;
} t_solib_windows;

typedef struct s_solib_time {
	t_solib_ticks	ticks;
	t_solib_clock	update;
	t_solib_clock	render;
} t_solib_time;

typedef struct s_solib_memory {
	void	*ptr;
	void	*next;
} t_solib_memory;

// Structure représentant solib
typedef struct s_solib{
	void			*minilibx;
	t_solib_windows	*windows;
	t_solib_inputs	*inputs;
	t_solib_events	*events;
	t_solib_time	*time;
	int				(*close)(t_solib *solib);
} t_solib;


#endif