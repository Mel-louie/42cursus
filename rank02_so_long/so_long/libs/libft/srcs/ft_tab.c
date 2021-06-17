#include "../includes/libft.h"

size_t	ft_tablen(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**ft_tabdup(char **tab)
{
	int		i;
	char	**new_tab;

	i = -1;
	new_tab = malloc(sizeof(char *) * (ft_tablen(tab) + 1));
	if (new_tab == NULL)
		return (NULL);
	while (tab[++i])
		new_tab[i] = ft_strdup(tab[i]);
	new_tab[i] = NULL;
	return (new_tab);
}
