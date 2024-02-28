/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 05:58:53 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solib.h"

void solib_memory_init(t_solib *solib)
{
    solib->memory = (t_solib_memory *)malloc(sizeof(t_solib_memory));
    if (!solib->memory)
        solib_close(solib);
    solib->memory->ptr = NULL;
    solib->memory->next = NULL;
}
