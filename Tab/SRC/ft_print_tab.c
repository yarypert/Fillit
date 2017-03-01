#include "../Includes/fillit.h"


void	print_2dim_tab(char **tab_tetri)
{
	//affiche uniquement un tetri
	int i;
	int j;


	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 5)
		{
			ft_putchar(tab_tetri[j][i]);
			i++;
		}
		j++;
	}
}

void	ft_putdoubletab(char **tab_tetri)
{
	//affiche nimporte quel tableau
	int t1;
	int t2;

	t1 = 0;
	t2 = 0;
	while (tab_tetri[t1] != NULL)
	{
		while (tab_tetri[t1][t2] != '\n')
		{
			ft_putchar(tab_tetri[t1][t2]);
			t2++;
		}
		ft_putchar(tab_tetri[t1][t2]);
		t2 = 0;
		t1++;
	}
}

void	print_tab(char ***tab, int piece_nb)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < piece_nb)
	{
		j = 0;
		while (j < 4)
		{
			k =0;
			while (k < 5)
			{
				ft_putchar(tab[i][j][k]);
				k++;
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
