/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:14:40 by almounib          #+#    #+#             */
/*   Updated: 2024/02/28 23:26:58 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "solong.h"

int	main(void)
{
	while (1)
	{
		
	}
	
}

typedef struct s_mini_canvas {
	float	width; // calculer grace a jsp quoi  
	float	height; //infinie donc commence a 1 (nbr de malloc) mais augmente au fur et a mesure qu'on ecrit
	
	//func null changeable
}	t_solib_vector2; 


//tableau[x][y]

#define WIDTH_T_SIZE 197
#define HEIGHT_T_SIZE 1

typedef struct s_mini_canvas {
	float	width; // calculer grace a jsp quoi  
	float	height; //infinie donc commence a 1 (nbr de malloc) mais augmente au fur et a mesure qu'on ecrit
	
	//func null changeable
}	t_solib_vector2; 

typedef struct s_mini
{
	
}	t_mini;


t_bool	mini_init(int width, int height, int displays, int type)
{
	t_mini	*mini;

	mini = (t_mini *)malloc(sizeof(t_mini));
	if (!mini)
		return (TRUE);
}

t_bool	solib_init(char *name, int width, int height, int target_frame)
{
	t_solib	*solib;

	solib = (t_solib *)malloc(sizeof(t_solib));
	if (!solib)
		return (TRUE);
	solib_memory_init(solib);
	solib->minilibx = mlx_init();
	if (!solib->minilibx)
		return (solib_close(solib));
	solib->target_frame = target_frame;
	solib_windows_init(solib, name, width, height);
	solib_inputs_init(solib);
	solib_events_init(solib);
	solib_time_init(solib, SIMUL_MHZ, 240, target_frame);
	solib->close = solib_close;
	solib_hooks(solib);
	solib_start(solib);
	mlx_loop_hook(solib->minilibx, solib_loop, solib);
	mlx_loop(solib->minilibx);
	solib_close(solib);
	return (FALSE);
}
*/
//int main(int argc, char const *argv[])
//{
//	(void)argc;
//	(void)argv;
//	if (mini_init(WIDTH_T_SIZE/*width*/, 1/*width*/,  3 /*screen nbr*/, 1 /*terminal type*/))
//		return (1);
//	return (0);
//}

/*
int	main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	//solib = solib_init("solong",1905, 1050, 60);
	if (solib_init("solong", 1905, 675, 60))
		return (1);
	return (0);
}

screen[1] 20% de tableau[x]
tableau[screen[1]screen[2]screen[3]]

int i;
int j;

while (i < x)
{
	
}


func ecrire screen 1*/