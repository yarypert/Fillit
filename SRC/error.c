#include "fillit.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void	freeall(char *file, char **pieces, int i)
{
	if (i == -1)
		while (pieces && pieces[++i])
			;
	while (i)
		ft_memdel((void *)&pieces[i--]);
	ft_memdel((void *)&file);
	ft_memdel((void **)pieces);
	ft_error("error");
}
