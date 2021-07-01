#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int		width, heigh;
char	*draw;
char	type, color, back;
float	x, y, w, h;

int		check_hit(float i, float j) {
	if (i < x || i > x + w || j < y || j > y + h)
		return (0);
	if (i - x < 1 || x + w - i < 1 || j - y < 1 || y + h - j < 1)
		return (2);
	return (1);
}

void	drawing(void) {
	int i = -1, j, hit;

	while (++i < width) {
		j = -1;
		while (++j < heigh) {
			hit = check_hit((float)i, (float)j);
			if (hit == 2 || (hit == 1 && type == 'R'))
				draw[i + j * width] = color;
		}
	}
}

int		parser(FILE *file) {
	int i = 0, result;

	if (fscanf(file, "%d %d %c\n", &width, &heigh, &back) != 3)
		return (1);
	if (width < 1 || width > 300 || heigh < 1 || heigh > 300)
		return (1);
	draw = malloc(width * heigh);
	if (draw == NULL)
		return (1);
	while (i < width * heigh)
		draw[i++] = back;
	while ((result = fscanf(file, "%c %f %f %f %f %c\n", &type, &x, &y, &w, &h, &color)) == 6) {
		if (w <= 0 || h <= 0 || (type != 'r' && type != 'R'))
			return (1);
		drawing();
	}
	if (result != -1)
		return (1);
	return (0);
}

void	output(void) {
	int fd; //test
	int i = -1;

	fd = open("mon_test.txt", O_RDWR | O_CREAT | O_TRUNC,
					S_IRWXU | S_IRWXG | S_IRWXO); //test
	while (++i < heigh) {
		write(fd, draw + i * width, width);
		write(fd, "\n", 1);
	}
}

int		main(int ac, char **av) {
	FILE	*file;

	if (ac != 2) {
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(file = fopen(av[1], "r")) || parser(file)) {
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	output();
	fclose(file);
	free(draw);
	return (0);
}