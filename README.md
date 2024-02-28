# solib_no_time.h_ver
 cc -Wall -Wextra -Werror -gdwarf-4 src/*.c  libs/solib/so/*.c libs/solib/so_time/*.c  -Iminilibx/ -lX11 -lXext
 clear & valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-origins=yes ./a.out

 cc main.c libs/solib/*.c libs/solib/solib_hooks/*.c libs/solib/solib_init/*.c libs/solib/solib_memory/*.c libs/solib/solib_time/*.c libs/minilibx/libmlx.a -lX11 -lXext -Wall -Wextra -Werror

 cc main.c libs/solib/*.c libs/solib/solib_hooks/*.c libs/solib/solib_init/*.c libs/solib/solib_memory/*.c libs/solib/solib_time/*.c minilibx-linux/libmlx_Linux.a -lX11 -lXext -Wall -Wextra -Werror