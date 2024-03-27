# solib_no_time.h_ver
 cc -Wall -Wextra -Werror -gdwarf-4 src/*.c  libs/solib/so/*.c libs/solib/so_time/*.c  -Iminilibx/ -lX11 -lXext
 clear & valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-origins=yes ./a.out

 cc main.c libs/solib/*.c libs/solib/solib_hooks/*.c libs/solib/solib_init/*.c libs/solib/solib_memory/*.c libs/solib/solib_time/*.c libs/minilibx/libmlx.a -lX11 -lXext -Wall -Wextra -Werror

 cc main.c libs/solib/*.c libs/solib/solib_hooks/*.c libs/solib/solib_init/*.c libs/solib/solib_memory/*.c libs/solib/solib_time/*.c minilibx-linux/libmlx_Linux.a -lX11 -lXext -Wall -Wextra -Werror

 [![42 Profile Card](https://1337-readme-xi.vercel.app/api/profile?cursus=42&dark=true&email=hide&leet_logo=hide&login=zoyern)](https://github.com/mohouyizme/1337-readme)

func on click null ou bouton
itemMouse position NULL la souris null pars

 //canvas > 
 // render update canvas > mouse position
 // mouse on canvas x - y - w - h no func > NULL on click
					| read parent ! |
 // item mouse = canvas[child]
 // mouse on canvas search child on mouse > panel no func
 // item mouse = canvas[panel[child]] 
 // mouse panel > multiple button xyzh > func on click 

 

   cc -Wall -Wextra -Werror -gdwarf-4 src/main.c  libs/solib/*.c  libs/solib/solib_hooks/*.c libs/solib/solib_time/*.c libs/solib/solib_init/*.c libs/solib/solib_memory/*.c libs/solib/solib_init/init_utils/init_struct.c  libs/minilibx/libmlx.a -lX11 -lXext