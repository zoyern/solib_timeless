/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:55:15 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 09:32:17 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_H
# define SOLIB_H

# define SIMUL_CYCLES 15000
# define SIMUL_MHZ 2700

# include <stdlib.h>
# include <stdio.h>

# include "../minilibx/mlx.h"
# include "./solib_types/solib_types.h"

//Setup
t_bool			solib_init(char *name, int width, int height, int target_frame);
int				solib_start(t_solib *solib);
int				solib_update(t_solib *solib);
int				solib_render(t_solib *solib);

//Memory
void			*solib_malloc(t_solib *solib, int size);
t_bool			solib_free(t_solib *solib, void *ptr);
#endif