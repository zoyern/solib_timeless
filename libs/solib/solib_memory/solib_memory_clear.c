/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_memory_clear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:17:31 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 06:13:14 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib.h"
#include "../solib_init/solib_init.h"

void	solib_memory_clear_free(t_solib_memory *memory)
{
	//printf("%llu -> %llu\n", (unsigned long long)memory, (unsigned long long)memory->ptr);
	//printf("%p -> %p -> %p\n", memory, memory->ptr, memory->next->ptr);
	if (memory->ptr)
		free(memory->ptr);
	free(memory);
}

void solib_memory_clear(t_solib *solib)
{
    t_solib_memory *current;
    t_solib_memory *tmp;
	
    current = solib->memory;
	//printf("\n\n");
	//solib_memory_show(solib);
	while (current->ptr)
	{
		tmp = current->next;
		//printf("%p -> %p\n", current, current->ptr);
		solib_memory_clear_free(current);
		current = tmp;
	}
	//printf("%p -> %p\n", current, current->ptr);
	free(current);
}