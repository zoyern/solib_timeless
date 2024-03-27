/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:22:06 by marvin            #+#    #+#             */
/*   Updated: 2024/03/22 14:22:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_solib_construct *solib_new_construct(t_solib *solib, char *name, char *args, t_bool enabled)
{
	t_solib_construct *construct;

	construct = (t_solib_construct *)solib->malloc(solib, sizeof(t_solib_construct));
	construct->name = name;
	construct->args = args;
	construct->enabled = enabled;
	return (construct);
}
