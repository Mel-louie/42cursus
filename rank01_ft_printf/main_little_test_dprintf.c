#include "ft_printf.h"
#include "libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>

int		main()
{
	int fd;
	int fd2;

	ft_printf("coucou\n");
	printf("coucou\n\n");

	fd = open("ft_dprintf", O_CREAT | O_RDWR, 0644);
	fd2 = open("dprintf", O_CREAT | O_RDWR, 0644);
	ft_dprintf(fd, "coucou\n");
	dprintf(fd2, "coucou\n");
	close(fd);
	close(fd2);
	return (0);
}
