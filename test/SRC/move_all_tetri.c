#include "../Includes/fillit.h"

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
		ft_putendl("appel de la fonction ft_tetri_decal");
		tab[i] = ft_tetri_decal(tab[i]);
		ft_putendl("fin de la fonction ft_tetri_decal");
		ft_putendl("appel de la fonction ft_replace_char");
		tab[i] = ft_replace_char(tab[i], 'A' + i);
		ft_putendl("fin de la fonction ft_replace_char");
		i++;
	}
		ft_putendl("return tab");
	return (tab);
}
