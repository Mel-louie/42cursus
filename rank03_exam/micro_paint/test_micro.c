/*
** a quick test to see if the output generate for my micro_paint
** has diffence with the one generate by the binary of the exam
** nb: should c/p the output of the exam's binary in a text file
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		main(int ac, char **av) {
	int c = 0, x, y;

	FILE *my_test = fopen("my_test.txt", "r");
	FILE *their_test = fopen("their_test.txt", "r");

	if (my_test != NULL && their_test != NULL)
	{
		while (1)
		{
			x = fgetc(my_test);
			y = fgetc(their_test);
			if (x != y)
				c++;
			if (x == EOF || y == EOF)
				break;
		}
		fclose(my_test);
		fclose(their_test);
    }
	printf("%d\n", c);
	return (0);
}