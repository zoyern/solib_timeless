/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_memory_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:17:17 by marvin            #+#    #+#             */
/*   Updated: 2024/02/26 22:17:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib.h"
#include "../solib_init/solib_init.h"

void	solib_memory_free(t_solib *solib, void *ptr)
{
	(void)solib;
	printf("free ptr : %lu\n", (unsigned long)ptr);
}