#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int	ft_strlen(char *str)
{
	int i;
	i = 0;
	if (!str)
		return(-1);
	while (str[i])
		i++;
	return (i);
}
char *ft_strcpy(char *dest, char *src)
{
	int i;
	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char	*ft_strdup(char *str)
{
	int i;
	int len;
	char *dest;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if ((dest = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	ft_strcpy(dest, str);
	return (dest);
}
char *ft_strjoin(char *dest, char *src)
{
	int len;
	char *copy;
	len = ft_strlen(dest);
	copy = ft_strdup(dest);
	free(dest);
	dest = (char*)malloc(sizeof(char) * (len + ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, copy);
	free(copy);
	ft_strcpy(dest + len, src);
	return (dest);
}
int	get_next_line(char **line)
{
	static char buff[1];
	int ret;
	if (!line)
		return (-1);
	*line = ft_strdup("");
	while((ret = read(0, buff, 1)) > 0)
	{
		if (buff[0] == '\n')
			return (1);
		if ((*line = ft_strjoin(*line, buff)) == NULL)
			return (-1);
	}
	if (ret == -1)
		return (-1);
	return(ret);
}
