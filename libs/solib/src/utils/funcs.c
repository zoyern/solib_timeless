/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:26:21 by marvin            #+#    #+#             */
/*   Updated: 2024/03/22 14:26:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_solib_funcs	*solib_new_funcs(t_solib *solib, void *environement, int (*start)(t_solib *solib, void *environement), int (*update)(t_solib *solib, void *environement))
{
	t_solib_funcs	*funcs;

	funcs = (t_solib_funcs *)solib->malloc(solib, sizeof(t_solib_funcs));

	funcs->environement = environement;
	funcs->func1 = start;
	funcs->func2 = update;
	return (funcs);
}