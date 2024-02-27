/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:45 by marvin            #+#    #+#             */
/*   Updated: 2024/02/27 19:20:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib.h"
#include "../solib_init/solib_init.h"

void	*solib_free(t_solib *solib, int size)
{
	void	*ptr;

	ptr = (void *)malloc(size);
	if (!ptr)
		solib_close(solib);
	solib_memory_add(solib, ptr);
	return (ptr);
}