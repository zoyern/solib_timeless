# solib_no_time.h_ver
 cc -Wall -Wextra -Werror -gdwarf-4 src/*.c  libs/solib/so/*.c libs/solib/so_time/*.c  -Iminilibx/ -lX11 -lXext
 valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./a.out