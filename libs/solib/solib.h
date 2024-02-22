/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:55:15 by marvin            #+#    #+#             */
/*   Updated: 2024/01/29 03:55:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_H
# define SOLIB_H

# include "../minilibx/mlx.h"
# include "solib_types.h"

//Setup
void	*solib_init(char *name);
int		solib_start(t_solib *solib);
int		solib_close(t_solib *solib);

#endif