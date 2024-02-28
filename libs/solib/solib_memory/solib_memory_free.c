/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_memory_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:17:17 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 06:07:26 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib.h"
#include "../solib_init/solib_init.h"

void	solib_memory_free(t_solib *solib, void *ptr)
{
	(void)solib;
	printf("free ptr : %lu\n", (unsigned long)ptr);
}