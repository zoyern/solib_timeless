/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_memory_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:15:43 by marvin            #+#    #+#             */
/*   Updated: 2024/02/26 22:15:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib.h"

void solib_memory_add(t_solib *solib, void *ptr)
{
    /* Création du nouvel élément */
    t_solib_memory *memory = (t_solib_memory *)malloc(sizeof(t_solib_memory));
    if (!memory)
        solib_close(solib);
    memory->ptr = ptr;
    memory->next = solib->memory;
    solib->memory = memory;
}