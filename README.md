# solib_no_time.h_ver
 cc -Wall -Wextra -Werror -gdwarf-4 src/*.c  libs/solib/so/*.c libs/solib/so_time/*.c  -Iminilibx/ -lX11 -lXext
 clear & valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-origins=yes ./a.out

 