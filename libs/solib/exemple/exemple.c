/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:37:18 by almounib          #+#    #+#             */
/*   Updated: 2024/03/20 16:15:37 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exemple.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	printf("salut\n");
	void *mlxptr = mlx_init();
	int w = 0;
	int h = 0;
	mlx_get_screen_size(mlxptr, &w, &h);
	printf("windows size : %d width -- %d height\n", w, h);
	return 0;
}