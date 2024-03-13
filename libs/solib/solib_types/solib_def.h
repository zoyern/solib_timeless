/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:36:50 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 09:39:11 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_DEF_H
# define SOLIB_DEF_H
# define TRUE 1
# define FALSE 0

typedef unsigned long long	t_uint64;
typedef unsigned int		t_uint32;
typedef int					t_bool;

typedef struct s_solib				t_solib;
typedef struct s_solib_memory		t_solib_memory;
typedef struct s_solib_new			t_solib_new;
typedef struct s_solib_get			t_solib_get;
typedef struct s_solib_set			t_solib_set;
typedef struct s_solib_remove		t_solib_remove;
typedef struct s_solib_transform		t_solib_transform;
typedef struct s_solib_construct		t_solib_construct;
typedef struct s_solib_display		t_solib_display;
typedef struct s_solib_canvas		t_solib_canvas;
typedef struct s_solib_button		t_solib_button;
typedef struct s_solib_image_func		t_solib_image_func;
typedef struct s_solib_image		t_solib_image;
typedef struct s_solib_image_data		t_solib_image_data;
typedef struct s_solib_memory		t_solib_memory;
typedef struct s_solib_time		t_solib_time;
typedef struct s_solib_windows		t_solib_windows;
typedef struct s_solib_inputs		t_solib_inputs;
typedef struct s_solib_keys		t_solib_keys;
typedef struct s_solib_events		t_solib_events;
typedef struct s_solib_size		t_solib_size;
typedef struct s_solib_quate		t_solib_quate;
typedef struct s_solib_vector2		t_solib_vector2;
//typedef struct s_solib_		t_solib_;

#endif