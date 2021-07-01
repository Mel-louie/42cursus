echo "COMPIL"
#echo "gcc -Wall -Wextra -Werror -fsanitize=address -D BUFFER_SIZE=100 -o GNL get_next_line.c get_next_line_utils.c main.c"
#gcc -Wall -Wextra -Werror -fsanitize=address -D BUFFER_SIZE=100 -o GNL get_next_line.c get_next_line_utils.c main.c
echo "gcc -Wall -Wextra -Werror -D BUFFER_SIZE=100 -o GNL get_next_line.c get_next_line_utils.c main.c"
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=100 -o GNL get_next_line.c get_next_line_utils.c main.c
echo "\n"
echo "EXE"
./GNL text/some_lines.txt
