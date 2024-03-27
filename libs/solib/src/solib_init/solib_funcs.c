/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_new_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:23:32 by marvin            #+#    #+#             */
/*   Updated: 2024/03/21 17:23:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_init.h"

void	solib_funcs_init(t_solib *solib, t_solib_funcs *init)
{
	t_solib_func	*funcs;

	funcs = solib->malloc(solib, sizeof(t_solib_func));
	solib->environement = init->environement;
	funcs->start = init->func1;
	funcs->upate = init->func2;
	funcs->on_destroy = NULL;
	solib->func = funcs;
}