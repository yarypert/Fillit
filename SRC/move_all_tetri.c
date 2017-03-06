#include "fillit.h"

char	*ft_replace_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] == '#')
			str[i] = c;
		i++;
	}
	return(str);
}

char **move_all_tetri(char **tab, int piece_nb)
{
	int i;

	i = 0;
	while (i < piece_nb)
	{
		tab[i] = ft_tetri_decal(tab[i]);
		tab[i] = ft_replace_char(tab[i], 'A' + i);
		i++;
	}
	return (tab);
}
